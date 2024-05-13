#include <iostream>
#include <fstream>
#include "Utils.h"
#include "Menu.h"
#include "PreTriage.h"
using namespace std;
namespace seneca {
  PreTriage::PreTriage(const char* filename): m_avgContaigenTime(15), m_avgTriageTime(5) {
    if (filename != nullptr && filename[0] != '\0') {
      m_filename = new char[U.strlen(filename) + 1];
      U.strcpy(m_filename, filename);
    }
    load();
  }

  PreTriage::~PreTriage(){
    save();
    for (int i = 0; i < m_numOfPatients; i++) {
      delete m_lineup[i];
      m_lineup[i] = nullptr;
    }
    delete[] m_filename;
    m_filename = nullptr;
  }

  Time PreTriage::getWaitTime(const Patient& p)const {
    int count = 0;
    for (int i = 0; i < m_numOfPatients; i++) {
      if (*m_lineup[i] == p) {
        count++;
      }
    }
    return Time((count) * (p == 'C' ? m_avgContaigenTime : m_avgTriageTime));
  }

  void PreTriage::setAverageWaitTime(const Patient& p) {
    Time awt;
    awt.reset();
    awt = ((awt - p.time()) + ((p == 'C' ? m_avgContaigenTime : m_avgTriageTime) * (p.number() - 1))) / p.number();
    p == 'C' ? m_avgContaigenTime = awt : m_avgTriageTime = awt;
  }

  int PreTriage::indexOfFirstInLine(const char type)const {
    int index = -1;
    for (int i = 0; i < m_numOfPatients && index == -1; i++) {
      if (*m_lineup[i] == type) {
        index = i;
      }
    }
    return index;
  }

  void PreTriage::load() {
    ifstream data(m_filename);
    cout << "Loading data..." << endl;
    if (!data.fail()) {
      data >> m_avgContaigenTime;
      data.ignore(1000, ',');
      data >> m_avgTriageTime;
      data.ignore(1000, '\n');
    }
    for (int i = 0; i < MAX_NUM_OF_PATIENTS && data; i++) {
      Patient* patient{};
      char type{};
      data >> type;
      data.ignore(1000, ',');
      if (type == 'C') {
        patient = new TestPatient;
      }
      else if (type == 'T') {
        patient = new TriagePatient;
      }
      
      if (patient != nullptr) {
        patient->read(data);
        m_lineup[i] = patient;
        m_numOfPatients++;
      }
    }
    if (m_numOfPatients > 0) {
      if (data.peek() != EOF) {
        cout << "Warning: number of records exceeded " << MAX_NUM_OF_PATIENTS << endl;
      }
      cout << m_numOfPatients << " Records imported..." << endl << endl;
    }
    else {
      cout << "No data or bad data file!" << endl << endl;
    }
    data.close();
  }

  void PreTriage::save()const{
    ofstream data(m_filename);
    int numOfTests = 0, numOfTriage = 0;
    cout << "Saving lineup..." << endl;
    data << m_avgContaigenTime << "," << m_avgTriageTime << endl;
    for (int i = 0; i < m_numOfPatients; i++) {
      data << *m_lineup[i] << endl;
      m_lineup[i]->type() == 'C' ? numOfTests++ : numOfTriage++;
    }
    cout << numOfTests << " Contagion Tests and " << numOfTriage << " Triage records were saved!" << endl;
    
    data.close();
  }

  void PreTriage::regist() {
    Menu menu("Select Type of Registration:\n1- Contagion Test\n2- Triage", 1);
    int selection = 0;
    if (m_numOfPatients < MAX_NUM_OF_PATIENTS) {
      menu >> selection;
      if (selection == 1 || selection == 2) {
      Patient* patient{};
      selection == 1 ? patient = new TestPatient : patient = new TriagePatient;
        if (patient != nullptr) {
          patient->setArrivalTime();
          cout << "Please enter patient information: " << endl;
          patient->read(cin);
          cout << endl;
          cout << "******************************************" << endl;
          cout << *patient;
          cout << "Estimated Wait Time: " << getWaitTime(*patient) << endl;
          cout << "******************************************" << endl << endl;
          m_lineup[m_numOfPatients] = patient;
          m_numOfPatients++;
        }
      }
    }
    else {
      cout << "Line up full!" << endl;
    }
  }

  void PreTriage::admit() {
    Menu menu("Select Type of Admittance:\n1- Contagion Test\n2- Triage", 1);
    int selection, index = 0;
    if (m_numOfPatients > 0) {
      menu >> selection;
      if (selection == 1 || selection == 2) {
        index = indexOfFirstInLine(selection == 1 ? 'C' : 'T');
        if (index != -1) {
          Time callTime{};
          callTime.reset();
          cout << endl << "******************************************" << endl;
          cout << "Call time: [" << callTime << "]" << endl;
          cout << "Calling at for "<< *m_lineup[index];
          cout << "******************************************" << endl << endl;
          setAverageWaitTime(*m_lineup[index]);
          U.removeDynamicElement(m_lineup, index, m_numOfPatients);
        }
      }
    }
    if (index == -1 || m_numOfPatients <= 0) {
      cout << "Lineup is empty!" << endl;
    }
  }

  void PreTriage::lineup()const {
    Menu menu("Select The Lineup:\n1- Contagion Test\n2- Triage", 1);
    int selection, count = 0;
    char type{};
    menu >> selection;
    type = selection == 1 ? 'C' : 'T';
    cout << "Row - Patient name                                          OHIP     Tk #  Time" << endl;
    cout << "-------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < m_numOfPatients; i++) {
      if (*m_lineup[i] == type) {
        count++;
        clog << count << "   - " << *m_lineup[i] << endl;
      }
    }
    if(count == 0) {
      cout << "Line up is empty!" << endl;
    }
    cout << "-------------------------------------------------------------------------------" << endl;
  }

  void PreTriage::run() {
    Menu menu("General Healthcare Facility Pre-Triage Application\n1- Register\n2- Admit\n3- View Lineup");
    int selection;
    while (menu >> selection) {
      switch (selection) {
        case 1: 
          regist(); 
          break;
        case 2: 
          admit();
          break;
        case 3: 
          lineup(); 
          break;
        default: 
          break;
      }
    };
  }
}
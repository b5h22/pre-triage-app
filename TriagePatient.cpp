#include <iostream>
#include "Utils.h"
#include "TriagePatient.h"
using namespace std;
namespace seneca {
  int nextTriageTicket = 1;
  TriagePatient::TriagePatient() : Patient(nextTriageTicket) {
    nextTriageTicket++;
  }
  char TriagePatient::type()const {
    return 'T';
  }
  ostream& TriagePatient::write(ostream& ostr)const {
    if(&ostr == &cout) ostr << "TRIAGE" << endl;
    Patient::write(ostr);
    if (&ostr == &cout) ostr << "Symptoms: " << m_symptoms << endl;
    else if (&ostr != &clog) ostr << "," << m_symptoms;
    
    return ostr;
  }
  istream& TriagePatient::read(istream& istr) {
    char temp[512];
    delete[] m_symptoms;
    m_symptoms = nullptr;
    Patient::read(istr);
    if(&istr != &cin) {
      istr.ignore(1000, ',');
      nextTriageTicket = number() + 1;
    }
    else cout << "Symptoms: ";
    
    istr.get(temp, 512, '\n');
    if (istr) {
      m_symptoms = new char[U.strlen(temp) + 1];
      U.strcpy(m_symptoms, temp);
    }
    else {
      delete[] m_symptoms;
      m_symptoms = nullptr;
    }
    istr.clear();
    istr.ignore(1000, '\n');
    return istr;
  }
  TriagePatient::~TriagePatient() {
    delete[] m_symptoms;
    m_symptoms = nullptr;
  }
}
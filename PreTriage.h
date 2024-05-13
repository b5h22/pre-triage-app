#ifndef SENECA_PRETRIAGE_H
#define SENECA_PRETRIAGE_H
#include "Patient.h"
#include "TestPatient.h"
#include "TriagePatient.h"
#include "Ticket.h"
#include "Time.h"
namespace seneca {
  const int MAX_NUM_OF_PATIENTS = 100;
  class PreTriage {
    Time m_avgContaigenTime{};
    Time m_avgTriageTime{};
    Patient* m_lineup[MAX_NUM_OF_PATIENTS]{};
    char* m_filename{};
    int m_numOfPatients{};
    Time getWaitTime(const Patient& p)const;
    void setAverageWaitTime(const Patient& p);
    int indexOfFirstInLine(const char type)const;
    void load();
    void save()const;
    void regist();
    void admit();
    void lineup()const;

  public:
    PreTriage(const char* filename);
    virtual ~PreTriage();
    void run();
  };
}
#endif
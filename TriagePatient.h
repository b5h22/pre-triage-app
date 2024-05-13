#ifndef SENECA_TRIAGEPATIENT_H
#define SENECA_TRIAGEPATIENT_H
#include <iostream>
#include "Patient.h"
namespace seneca{
  class TriagePatient : public Patient {
    char* m_symptoms{};
  public:
    TriagePatient();
    char type()const;
    std::ostream& write(std::ostream& ostr)const;
    std::istream& read(std::istream& istr);
    virtual ~TriagePatient();
  };
}
#endif
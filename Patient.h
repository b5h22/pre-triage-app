#ifndef SENECA_PATIENT_H
#define SENECA_PATIENT_H
#include <iostream>
#include "IOAble.h"
#include "Utils.h"
#include "Ticket.h"
namespace seneca {
  class Patient : public IOAble {
    char* m_name{};
    int m_ohipNum{};
    Ticket m_ticket{0};
    void copy(const Patient& p);
  public:
    Patient(int ticketNum);
    Patient(const Patient& p);
    Patient& operator=(const Patient& p);
    virtual ~Patient();
    virtual char type()const = 0;
    bool operator==(const char t)const;
    bool operator==(const Patient& p)const;
    void setArrivalTime();
    Time time()const;
    int number()const;
    operator bool()const;
    operator const char*()const;
    std::ostream& write(std::ostream& ostr)const;
    std::istream& read(std::istream& istr);
  };
}
#endif
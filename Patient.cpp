#include <iostream>
#include "Utils.h"
#include "Patient.h"
using namespace std;
namespace seneca {
  void Patient::copy(const Patient& p) {
    if(p.m_name != nullptr && p.m_name[0] != '\0') {
      m_name = new char[U.strlen(p.m_name) + 1];
      U.strcpy(m_name, p.m_name);
      m_ohipNum = p.m_ohipNum;
      m_ticket = p.m_ticket;
    } 
  };
  Patient::Patient(int ticketNum): m_ticket(ticketNum) {};
  Patient::Patient(const Patient& p) {
    copy(p);
  }
  Patient& Patient::operator=(const Patient& p) {
    if (this != &p) {
      delete[] m_name;
      m_name = nullptr;
      copy(p);
    }
    return *this;
  }
  Patient::~Patient() {
    delete[] m_name;
  }
  bool Patient::operator==(const char t)const {
    return type() == t;
  }
  bool Patient::operator==(const Patient& p)const {
    return type() == p.type();
  }
  void Patient::setArrivalTime() {
    m_ticket.resetTime();
  }
  Time Patient::time()const {
    return m_ticket.time();
  }
  int Patient::number()const {
    return m_ticket.number();
  }
  Patient::operator bool()const {
    return m_name != nullptr && m_name[0] != '\0' && m_ohipNum != 0 && m_ticket.number() != 0;
  }
  Patient::operator const char*()const {
    return m_name;
  }
  ostream& Patient::write(ostream& ostr)const {
    if (&ostr == &clog) {
      if (*this) {
          ostr.width(53);
          ostr.fill('.');
          ostr.setf(ios::left);
          ostr << m_name;
          ostr.fill(' ');
          ostr.unsetf(ios::left);
          ostr << m_ohipNum;
          ostr.width(5);
          ostr.setf(ios::right);
          ostr << m_ticket.number() << ' ' << time();
          ostr.unsetf(ios::right);
        } 
        else {
          ostr << "Invalid Patient Record";
        }
    }
    else if (&ostr == &cout) {
      if (*this) {
          m_ticket.write(ostr) << endl << m_name << ", OHIP: " << m_ohipNum << endl;
        }
        else {
          ostr << "Invalid Patient Record" << endl;
        }
    }
    else {
      ostr << type() << ',' << m_name << ',' << m_ohipNum << ',';
      m_ticket.write(ostr);
    }
    return ostr;
  }
  istream& Patient::read(istream& istr) {
    char name[51];
    if (&istr == &cin) {
      cout << "Name: ";
      istr.get(name, 51, '\n');
      if (istr) {
        delete[] m_name;
        m_name = new char[U.strlen(name) + 1];
        U.strcpy(m_name, name);
      }
      else {
        delete[] m_name;
        m_name = nullptr;
      }
      istr.clear();
      istr.ignore(1000, '\n');

      cout << "OHIP: ";
      do
      {
        istr >> m_ohipNum;
        if (!istr) {
          cout << "Bad integer value, try again: ";
          istr.clear();
          istr.ignore(1000, '\n');
        }
        else if (m_ohipNum < 100000000 || m_ohipNum > 999999999) {
          cout << "Invalid value enterd, retry[100000000 <= value <= 999999999]: ";
        }
      } while (m_ohipNum < 100000000 || m_ohipNum > 999999999);
      istr.clear();
      istr.ignore(1000, '\n');
    }
    else {
      istr.get(name, 51, ',');
      if(istr) {
        delete[] m_name;
        m_name = new char[U.strlen(name) + 1];
        U.strcpy(m_name, name);
      } 
      else {
        delete[] m_name;
        m_name = nullptr;
      }
      istr.clear();
      istr.ignore(1000, ','); 
      
      istr >> m_ohipNum;
      istr.ignore(1000, ',');
      m_ticket.read(istr);
    }
    return istr;
  }
}
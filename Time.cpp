#include "Time.h"
#include "Utils.h"
using namespace std;
namespace seneca {
  Time& Time::reset() {
    m_mins = U.getTime();
    return *this;
  }
  Time::Time(unsigned int min) {
    m_mins = min;
  }
  ostream& Time::write(ostream& ostr) const {
    int hour = m_mins / 60;
    int min = m_mins % 60;
    ostr.fill('0');
    ostr.width(2);
    ostr << hour << ":";
    ostr.fill('0');
    ostr.width(2);
    ostr << min;
    return ostr;
  }
  istream& Time::read(istream& istr) {
    int hour, min;
    char colon;
    istr >> hour;
    if (istr.peek() == '\n' || !(istr >> colon) || colon != ':') {
        istr.setstate(ios::failbit);
    } else {
        istr >> min;
        m_mins = hour * 60 + min;       
    }
    return istr;
  }

  Time::operator unsigned int()const {
    return m_mins;
  }
  Time& Time::operator*= (int val) {
    m_mins *= val;
    return *this;
  }
  Time& Time::operator-= (const Time& D) {
    if (m_mins < D.m_mins) {
      m_mins += 1440;
    }
    m_mins -= D.m_mins;
    return *this;
  }
  Time Time::operator- (const Time& T)const {
    Time temp;
    temp.m_mins = m_mins - T.m_mins;
    if (temp.m_mins < 0) {
      temp.m_mins += 1440;
    }
    return temp;
  }
  std::ostream& operator<<(std::ostream& ostr, const Time& T) {
    return T.write(ostr);
  }
  std::istream& operator>>(std::istream& istr, Time& T) {
    return T.read(istr);
  }
}
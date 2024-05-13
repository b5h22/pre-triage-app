#ifndef SENECA_TIME_H
#define SENECA_TIME_H
#include <iostream>
namespace seneca {
  class Time {
    int m_mins{};
  public:
    Time& reset();
    Time(unsigned int min = 0u);
    virtual ~Time() = default;
    std::ostream& write(std::ostream& ostr = std::cout) const;
    std::istream& read(std::istream& istr = std::cin);
    operator unsigned int()const;
    Time& operator*= (int val);
    Time& operator-= (const Time& D);
    Time operator-(const Time& T)const;
  };
  std::ostream& operator<<(std::ostream& ostr, const Time& T);
  std::istream& operator>>(std::istream& istr, Time& T);
}
#endif
#ifndef SENECA_IOABLE_H
#define SENECA_IOABLE_H
#include <iostream>
namespace seneca {
  class IOAble {
  public:
    virtual std::ostream& write(std::ostream& ostr) const = 0;
    virtual std::istream& read(std::istream& istr) = 0;
    virtual ~IOAble() = default;
  };
  std::ostream& operator<<(std::ostream& ostr, const IOAble& io);
  std::istream& operator>>(std::istream& istr, IOAble& io);
}
#endif
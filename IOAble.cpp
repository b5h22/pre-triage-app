#include "IOAble.h"
#include <iostream>
using namespace std;
namespace seneca {
  ostream& operator<<(ostream& ostr, const IOAble& io) {
    return io.write(ostr);
  }
  istream& operator>>(istream& istr, IOAble& io) {
    return io.read(istr);
  }
}
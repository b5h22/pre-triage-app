#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Utils.h"
#include "Time.h"
using namespace std;
namespace seneca {
   // start provided code
   bool debug = false;
   Utils U;
   int Utils::getTime() {
      int mins = -1;
      if (debug) {
         int duration[]{ 3,5,9,20,30 };
         mins = (m_testMins %= 1440);
         m_testMins += duration[m_testIndex++ % 5];
      }
      else {
         time_t t = time(NULL);
         tm lt = *localtime(&t);
         mins = lt.tm_hour * 60 + lt.tm_min;
      }
      return mins;
   }
   void Utils::setDebugTime(int hour, int min) {
      seneca::debug = true;
      m_testMins = hour * 60 + min;
   }
   // end provided code
   int Utils::strcmp(const char* s1, const char* s2)const {
      int i;
      for (i = 0; s1[i] && s2[i] && s1[i] == s2[i]; i++);
      return s1[i] - s2[i];
   }
   char* Utils::strcat(char* des, const char* src)const {
      int len = strlen(des);
      int i = 0;
      while (src[i]) {
         des[i + len] = src[i];
         i++;
      }
      des[i + len] = char(0);
      return des;
   }
   int Utils::strcmp(const char* s1, const char* s2, int len)const {
      int i = 0;
      while (i < len - 1 && s1[i] && s2[i] && s1[i] == s2[i]) {
         i++;
      }
      return s1[i] - s2[i];
   }
   char* Utils::strcpy(char* des, const char* src)const {
      int i;
      for (i = 0; src[i]; i++) des[i] = src[i];
      des[i] = char(0);
      return des;
   }
   char* Utils::strcpy(char* des, const char* src, int len)const {
      int i;
      for (i = 0; i < len && src[i]; i++) des[i] = src[i];
      des[i] = 0; // unlike strncpy, this function null terminates
      return des;
   }
   char* Utils::strncpy(char* des, const char* src, int len)const {
      int i = 0;
      while (i < len - 1 && src[i]) {
         des[i] = src[i];
         i++;
      }
      des[i] = src[i];
      return des;
   }
   int Utils::strlen(const char* str)const {
      int len;
      for (len = 0; str[len]; len++);
      return len;
   }
   const char* Utils::strstr(const char* str, const char* find)const {
      const char* faddress = nullptr;
      int i, flen = strlen(find), slen = strlen(str);
      for (i = 0; i <= slen - flen && strcmp(&str[i], find, flen); i++);
      if (i <= slen - flen) faddress = &str[i];
      return faddress;
   }
}
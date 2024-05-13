#ifndef SENECA_UTILS_H_
#define SENECA_UTILS_H_
#include <iostream>
namespace seneca {
   class Utils {
      /// <summary>
      /// Start point for the simulated time
      /// Set to 8 AM
      /// </summary>
      unsigned int m_testMins = 480;
      /// <summary>
      /// index for the time addition intervals ({ 3,5,9,20,30 });
      /// </summary>
      unsigned int m_testIndex = 0;
   public:
      template <typename type>
      void removeDynamicElement(type* array[], int index, int& size) {
         delete array[index];
         for (int j = index; j < size; j++) {
            array[j] = array[j + 1];
         }
         size--;
      }
      /// <summary>
      /// Set the debug global variable to true and sets the m_testMins attribute to 
      ///  hour x 60 + min. This value will be the intial starting time for debugging
      ///  and testing. 
      /// </summary>
      /// <param name="hour">hours</param>
      /// <param name="min">minutes</param>
      void setDebugTime(int hour, int min);
      /// <summary>
      /// If not in debugging mode, returns the current minute value of the system hour
      ///  and minute. If debugging is active it will first return the value of m_testMins 
      ///  then adds the following values in these intervals (3,5,9,20,30) to simulate passage
      ///  of time. 
      /// </summary>
      /// <returns>the current time in minutes</returns>
      int getTime(); // returns the time of day in minutes

      /// <summary>
      /// compares s1 to s2
      /// </summary>
      /// <param name="s1">Cstring</param>
      /// <param name="s2">Cstring</param>
      /// <returns> &gt;0 if s1 &gt; s2  OR  &lt;0 if s1 &lt; s2 OR 0 if s1 = s2</returns>
      int strcmp(const char* s1, const char* s2)const;

      /// <summary>
      /// concatenates src to des
      /// </summary>
      /// <param name="des">destination Cstring</param>
      /// <param name="src">source Cstring</param>
      /// <returns>des</returns>
      char* strcat(char* des, const char* src)const;

      /// <summary>
      /// compares s1 to s2 up to len characters
      /// </summary>
      /// <param name="s1">Cstring</param>
      /// <param name="s2">Cstring</param>
      /// <param name="len">number of characters to compare</param>
      /// <returns>result</returns>
      int strcmp(const char* s1, const char* s2, int len)const;

      /// <summary>
      /// copies src to des
      /// </summary>
      /// <param name="des">destination Cstring</param>
      /// <param name="src">source Cstring</param>
      /// <returns>des</returns>
      char* strcpy(char* des, const char* src)const;

      /// <summary>
      /// copies src to des up to len characters
      /// </summary>
      /// <param name="des">destination Cstring</param>
      /// <param name="src">source Cstring</param>
      /// <param name="len">number of characters to copy</param>
      /// <returns>des</returns>
      char* strcpy(char* des, const char* src, int len)const;

      /// <summary>
      /// returns the length of the Cstring
      /// </summary>
      /// <param name="str">Cstring</param>
      /// <returns>length of the Cstring</returns>
      char* strncpy(char* des, const char* src, int len)const;

      /// <summary>
      /// returns the length of the Cstring
      /// </summary>
      /// <param name="str">Cstring</param>
      /// <returns>length of the Cstring</returns>
      int strlen(const char* str)const;

      /// <summary>
      /// returns the address of the first occurance of find in str
      /// </summary>
      /// <param name="str">Cstring</param>
      /// <param name="find">Cstring to find</param>
      /// <returns>address of the first occurance of find in str</returns>
      const char* strstr(const char* str, const char* find)const;
   };
   /// <summary>
      /// making seneca::debug variable global to all the files
      /// which include "Utils.h"
      /// </summary>
   extern bool debug;
   /// <summary>
   /// making seneca::U "Utils" object global to all the files which include "Utils.h"
   /// </summary>
   extern Utils U;

}
#endif // !SENECA_UTILS_H_
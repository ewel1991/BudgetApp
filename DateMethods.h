#ifndef DateMethods_h
#define DateMethods_h


#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <chrono>
#include <regex>
#include <iomanip>
#include <sstream>



using namespace std;
using namespace chrono;

class DateMethods
{

   static void calculateCurrentDate(std::map <string, int> &currentDate);
   static bool isYearLeap (int year);


public:

    static bool validateDate (string &date);
    static int convertStringDateToInt (const string &dateAsString);
    static string convertIntDateToStringWithDashes(int dateAsString);
    static int getCurrentDate();
    static int getCurrentMonthFirstDayDate();
    static int getPreviousMonthFirstDayDate();
    static int getPreviousMonthLastDayDate();



};

#endif

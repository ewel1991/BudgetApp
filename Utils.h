#ifndef Utils_h
#define Utils_h


#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

class Utils
{
    public:
    static char getCharacter();
    static string readLine();
    static string changeDoubleIntoString(double amount);
    bool validateInput (string input);

};

#endif

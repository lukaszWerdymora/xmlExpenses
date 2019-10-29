#ifndef HELPMETHODS_H
#define HELPMETHODS_H

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <windows.h>

using namespace std;
class HelpMethods
{


int getMonthFromSystem();
int getDayFromSystem();
int getYearFromSystem();
int howManyDaysLeftToEndOfMonth();
bool ifLeapYear(int year);
public:

    static int conversionStringToInt (string str);
    static string conversionIntToString (int digit);
    static double conversionStringToDouble (string doubleDigitString);
    static string conversionDoubleToString (double doubleDigit);
    static string returnDataWithDash(int intDate);// do wykasowania
    static int howManyDaysLeftToEndOfMonth( int month, int day);
    static string getDateFromSystem();

};


#endif // HELPMETHODS_H

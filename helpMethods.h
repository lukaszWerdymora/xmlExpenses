#ifndef HELPMETHODS_H
#define HELPMETHODS_H

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <windows.h>
#include <conio.h>
#include <cstdlib>

using namespace std;
class HelpMethods
{


int getMonthFromSystem();
int getDayFromSystem();


bool ifLeapYear(int year);
static bool ifNumber(char number, int numberPosition);
static bool ifDash(char dash, int dashPosition);
public:
    static string getYearFromSystem();
    static int conversionStringToInt (string str);
    static string conversionIntToString (int digit);
    static double conversionStringToDouble (string doubleDigitString);
    static string conversionDoubleToString (double doubleDigit);
    static string returnDataWithDash(int intDate);// do wykasowania
    static int howManyDaysLeftToEndOfMonth( int month, int day);
    static string getDateFromSystem();
    static string returnMonthFromDate(string date);
    static string returnYearFromDate (string date);
    static string returnTwoDigitsDate (string date);
    static void returnFullNameMonth (string month);
    static char returnSingleDigit();
    static string returnHiddenPassword ();
    static bool correctData (string data);
    static bool ifProvidedMonthCorrectly (string month);


};


#endif // HELPMETHODS_H

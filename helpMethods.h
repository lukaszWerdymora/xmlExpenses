#ifndef HELPMETHODS_H
#define HELPMETHODS_H

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;
class HelpMethods
{

public:

    static int conversionStringToInt (string str);
    static string conversionIntToString (int digit);
    static double conversionStringToDouble (string doubleDigitString);
    static string conversionDoubleToString (double doubleDigit);
    static int separtaeIntOnDigit(int number);
    static string returnDataWithDash(int data);

};


#endif // HELPMETHODS_H

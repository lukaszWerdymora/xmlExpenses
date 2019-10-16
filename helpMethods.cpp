#include "helpMethods.h"

int HelpMethods :: conversionStringToInt( string str)
{
    int digit;
    digit=atoi(str.c_str());

    return digit;
}

string HelpMethods :: conversionIntToString (int digit)
{
    ostringstream ss;
    ss << digit;
    string str = ss.str();
    return str;
}

double HelpMethods :: conversionStringToDouble (string doubleDigitString)
{

    double doubleDigit;
    //doubleDigit=atof(doubleDigitString.c_str());
    istringstream (doubleDigitString)>>doubleDigit;
    return doubleDigit;

}
string HelpMethods ::conversionDoubleToString (double doubleDigit)
{
    ostringstream strs;
    strs<<doubleDigit;
    string str= strs.str();
    return str;
}

string HelpMethods :: returnDataWithDash (int data){
    vector <string> dataWithDash;
    vector <string>::iterator itr=dataWithDash.begin();
    string strData;
    strData=conversionIntToString(data);
    dataWithDash.push_back(strData);


    for (itr; itr!=dataWithDash.end(); itr++){


            dataWithDash.insert(itr,"-");

    }

    return strData;
}


//do wykasowania
int HelpMethods :: separtaeIntOnDigit (int number)
{
    int digit;
    int *reversData=new int [8];
    //reversData
    int tab [8];
    int i=0;
    while (number>0)
    {
        tab[i]=number%10;
        number/=10;
        i++;
    }
    i=0;

    for (int j=7; j>=0; j--)
    {

        reversData[i]=tab[j];
        i++;
    }

    for(int i=0; i<8; i++)
    {
        cout<< reversData[i];
    }

//    return reversData;
//    delete reversData[];
}

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

string HelpMethods :: returnDataWithDash (int intDate){//do wykasowania

    string stringData="";
    string dataWithDash="";
    string year="";
    string month="";
    string day="";
    stringData=conversionIntToString(intDate);

    for (int i=0; i<stringData.size(); i++){
        if (i<4){
            year+=stringData[i];
        }
        if ((i>=4)&& (i<6)){
            month+=stringData[i];
        }
        if (i>=6){
            day+=stringData[i];
        }
    }

    //cout<< year<<endl<<month<<endl<<day;
    dataWithDash=year+"-"+month+"-"+day;
    return dataWithDash;
}

string HelpMethods :: getDateFromSystem(){
    string date="NULL";
    int month=0;
    SYSTEMTIME st;
    GetSystemTime(&st);

    date=conversionIntToString(st.wYear)+"-";

    if (st.wMonth<10) {

        date+="0"+conversionIntToString(st.wMonth)+"-";
    }else {date+=conversionIntToString(st.wMonth)+"-";}

    if (st.wDay<10){

        date+="0"+conversionIntToString(st.wDay);
    }else date+=conversionIntToString(st.wDay);
    return date;
}

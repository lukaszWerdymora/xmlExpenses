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

string HelpMethods :: returnMonthFromDate(string date)
{
    string month="";
    for (int i=0; i<date.size(); i++)
    {
        if ((i>4) && (i<7))
        {
            month+=date[i];
        }
    }
    return month;
}

string HelpMethods :: returnTwoDigitsDate (string date){

        if (date.size()==1){
            return "0"+date;
        }
        else return date;

}
bool HelpMethods :: returnFullNameMonth (string month){
    int digitMonth=conversionStringToInt(month);
    bool ifGoodMonth=false;

    switch (digitMonth){
case 1:
    cout<<"Styczen";ifGoodMonth=true;
    break;
case 2:
    cout<<"Luty";ifGoodMonth=true;
    break;
case 3:
    cout<<"Marzec";ifGoodMonth=true;
    break;
case 4:
    cout<<"Kwiecien";ifGoodMonth=true;
    break;
case 5:
    cout<<"Maj";ifGoodMonth=true;
    break;
case 6:
    cout<<"Czerwiec";ifGoodMonth=true;
    break;
case 7:
    cout<<"Lipiec";ifGoodMonth=true;
    break;
case 8:
    cout<<"Sierpien";ifGoodMonth=true;
    break;
case 9:
    cout<<"Wrzesien";ifGoodMonth=true;
    break;
case 10:
    cout<<"Pazdziernik";ifGoodMonth=true;
    break;
case 11:
    cout<<"Listopad";ifGoodMonth=true;
    break;
case 12:
    cout<<"Grudzien";ifGoodMonth=true;
    break;
default:
    cout<<"Nie ma takiego miesiaca";ifGoodMonth=false;
    break;

    }

}

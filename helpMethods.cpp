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
void HelpMethods :: returnFullNameMonth (string month){
    int digitMonth=conversionStringToInt(month);


    switch (digitMonth){
case 1:
    cout<<"Styczen";
    break;
case 2:
    cout<<"Luty";
    break;
case 3:
    cout<<"Marzec";
    break;
case 4:
    cout<<"Kwiecien";
    break;
case 5:
    cout<<"Maj";
    break;
case 6:
    cout<<"Czerwiec";
    break;
case 7:
    cout<<"Lipiec";
    break;
case 8:
    cout<<"Sierpien";
    break;
case 9:
    cout<<"Wrzesien";
    break;
case 10:
    cout<<"Pazdziernik";
    break;
case 11:
    cout<<"Listopad";
    break;
case 12:
    cout<<"Grudzien";
    break;

    }

}


char HelpMethods :: returnSingleDigit (){
    char digit={0};
    string text="";

    while (true){
        getline (cin, text);
        if (text.length()==1){
            digit=text[0];
            break;
        }else{
            cout<<"To nie jest pojedynczy znak\n";
        }
    }

   return digit;
}

string HelpMethods :: returnHiddenPassword (){

    char a;
    string password="";
    string temp="";
    int countStars=0;
    int passwordLength=0;// zrobiles to do petli while rownie dobrz moze byc =0

    //cout<<"Podaj haslo: ";
    for (int i=0; (a=getch())!='\r'; i++)
    {

        if (a==8)
        {

            passwordLength=password.length()-1;
            password[passwordLength]=NULL;
            //password[password.length()-1]=NULL;
            //passwordLength=password.length()-1;
            for (int j=0; j<passwordLength; j++)
            {
                temp+=password[j];
            }
            password=temp;
            temp="";
            countStars--;
        }
        else
        {

            countStars++;
            password+=a;
        }
        system ("cls");
        cout<<"Podaj haslo: ";
        for (int i=0; i<countStars; i++)
        {
            cout<<"*";
        }
    }


return password;


}

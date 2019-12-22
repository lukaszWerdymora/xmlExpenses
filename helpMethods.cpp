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

string HelpMethods :: returnDataWithDash (int intDate) //do wykasowania
{

    string stringData="";
    string dataWithDash="";
    string year="";
    string month="";
    string day="";
    stringData=conversionIntToString(intDate);

    for (int i=0; i<stringData.size(); i++)
    {
        if (i<4)
        {
            year+=stringData[i];
        }
        if ((i>=4)&& (i<6))
        {
            month+=stringData[i];
        }
        if (i>=6)
        {
            day+=stringData[i];
        }
    }

    //cout<< year<<endl<<month<<endl<<day;
    dataWithDash=year+"-"+month+"-"+day;
    return dataWithDash;
}

string HelpMethods :: getDateFromSystem()
{
    string date="NULL";
    int month=0;
    SYSTEMTIME st;
    GetSystemTime(&st);

    date=conversionIntToString(st.wYear)+"-";

    if (st.wMonth<10)
    {

        date+="0"+conversionIntToString(st.wMonth)+"-";
    }
    else
    {
        date+=conversionIntToString(st.wMonth)+"-";
    }

    if (st.wDay<10)
    {

        date+="0"+conversionIntToString(st.wDay);
    }
    else
        date+=conversionIntToString(st.wDay);
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

string HelpMethods :: returnYearFromDate(string date){
    string year="";
    for (int i=0; i<4; i++){

            year+=date[i];


        //cout<<i<<" ";
    }
    return year;
}

string HelpMethods :: returnTwoDigitsDate (string date)
{

    if (date.size()==1)
    {
        return "0"+date;
    }
    else
        return date;

}
void HelpMethods :: returnFullNameMonth (string month)
{
    int digitMonth=conversionStringToInt(month);


    switch (digitMonth)
    {
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


char HelpMethods :: returnSingleDigit ()
{
    char digit= {0};
    string text="";

    while (true)
    {
        getline (cin, text);
        if (text.length()==1)
        {
            digit=text[0];
            break;
        }
        else
        {
            cout<<"To nie jest pojedynczy znak\n";
        }
    }

    return digit;
}

string HelpMethods :: returnHiddenPassword ()
{

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
bool HelpMethods :: ifNumber(char number, int numberPosition)
{
    //int intNumber=conversionStringToInt(number);

    if (number>='0' && number<='9')
    {
        return true;
    }
    else
    {
        cout<<"Pozycja nr: "<<numberPosition+1<<" w wyrazeniu jest niepoprawna. Popraw!\n";
        return  false;
    }

}
bool HelpMethods :: ifDash (char dash, int dashPosition)
{
    if (dash=='-')
    {

        return true;
    }
    else
    {
        cout<<"Pozycja nr: "<<dashPosition+1<<" w wyrazeniu jest niepoprawna. Popraw!\n";
        return false;
    }
}
bool HelpMethods :: correctData(string data)
{

    string temp="";
    bool correctNumber=false;
    bool wholeExpresion=true;
    int i=0;

        while (i<data.length())
        {
            switch (i)
            {
            case 0:
                correctNumber=ifNumber(data[i],i);
                wholeExpresion&=correctNumber;
                temp+=data[i];
                break;


            case 1:
                //correctNumber=ifNumber(data[i],i);
                correctNumber=ifNumber(data[i],i);
                wholeExpresion&=correctNumber;
                temp+=data[i];
                break;
            case 2:
                correctNumber=ifNumber(data[i],i);
                wholeExpresion&=correctNumber;
                temp+=data[i];
                break;
            case 3:
                correctNumber=ifNumber(data[i],i);
                wholeExpresion&=correctNumber;
                temp+=data[i];;
                break;
            case 4:
                correctNumber=ifDash(data[i],i);
                wholeExpresion&=correctNumber;
                temp+=data[i];
                break;

            case 5:
                correctNumber=ifNumber(data[i],i);
                wholeExpresion&=correctNumber;
                temp+=data[i];
                break;
            case 6:
                correctNumber=ifNumber(data[i],i);
                wholeExpresion&=correctNumber;
                temp+=data[i];
                break;
            case 7:
                correctNumber=ifDash(data[i],i);
                wholeExpresion&=correctNumber;
                temp+=data[i];
                break;
            case 8:
                correctNumber=ifNumber(data[i],i);
                wholeExpresion&=correctNumber;
                temp+=data[i];
                break;
            case 9:
                correctNumber=ifNumber(data[i],i);
                wholeExpresion&=correctNumber;
                temp+=data[i];
                break;

            }

            i++;
        }
        if (data.length()!=10)
        {
            wholeExpresion=false;
            cout<<"Dlugosc daty jest zla\n";
        }
        if (!wholeExpresion){
        cout<<"Format daty jest: YYYY-MM-DD\n";
        cout<<"A wpisales        "<<temp<<endl;
        }


        return wholeExpresion;
}

string HelpMethods :: getYearFromSystem (){

    string currentYear="NULL";

    SYSTEMTIME st;
    GetSystemTime(&st);
    currentYear=conversionIntToString(st.wYear);

    return currentYear;
}


bool HelpMethods :: ifProvidedMonthCorrectly (string month){
    int monthToCheck=0;
    monthToCheck = HelpMethods ::conversionStringToInt( month );

    if ((monthToCheck > 0 )&& (monthToCheck < 13)){
        return true;
    }else {
        return false;
    }
}
/*
void HelpMethods :: correctData(string data)
{
    //cout<<data;
    string temp="";
    bool correctNumber=false;
    bool wholeExpresion=true;
    int i=0;
    while (i<data.length())
    {
        switch (i)
        {
        case 0:
            ifNumber(data[i]);
            temp+=data[i];
            break;
        case 1:
            if (data[i]>47 && data[i]<58)
            {
                correctNumber=true;
                wholeExpresion&=correctNumber;

            }
            else
            {
                correctNumber=false;
                wholeExpresion&=correctNumber;
                cout<<"Pozycja nr: "<<i+1<<" w wyrazeniu jest niepoprawna. Popraw!\n";

            }
            temp+=data[i];
            break;
        case 2:
            if (data[i]>47 && data[i]<58)
            {
                correctNumber=true;
                wholeExpresion&=correctNumber;

            }
            else
            {
                correctNumber=false;
                wholeExpresion&=correctNumber;
                cout<<"Pozycja nr: "<<i+1<<" w wyrazeniu jest niepoprawna. Popraw!\n";

            }
            temp+=data[i];
            break;
        case 3:
            if (data[i]>47 && data[i]<58)
            {
                correctNumber=true;
                wholeExpresion&=correctNumber;

            }
            else
            {
                correctNumber=false;
                wholeExpresion&=correctNumber;
                cout<<"Pozycja nr: "<<i+1<<" w wyrazeniu jest niepoprawna. Popraw!\n";

            }
            temp+=data[i];
            break;
        case 4:
            if (data[i]==45)
            {
                correctNumber=true;
                wholeExpresion&=correctNumber;

            }
            else
            {
                correctNumber=false;
                wholeExpresion&=correctNumber;
                cout<<"Pozycja nr: "<<i+1<<" w wyrazeniu jest niepoprawna. Popraw!\n";

            }
            temp+=data[i];
            break;

        case 5:
            if (data[i]>47 && data[i]<58)
            {
                correctNumber=true;
                wholeExpresion&=correctNumber;

            }
            else
            {
                correctNumber=false;
                wholeExpresion&=correctNumber;
                cout<<"Pozycja nr: "<<i+1<<" w wyrazeniu jest niepoprawna. Popraw!\n";

            }
            temp+=data[i];
            break;
        case 6:
            if (data[i]>47 && data[i]<58)
            {
                correctNumber=true;
                wholeExpresion&=correctNumber;

            }
            else
            {
                correctNumber=false;
                wholeExpresion&=correctNumber;
                cout<<"Pozycja nr: "<<i+1<<" w wyrazeniu jest niepoprawna. Popraw!\n";

            }
            temp+=data[i];
            break;
        case 7:
            if (data[i]==45)
            {
                correctNumber=true;
                wholeExpresion&=correctNumber;

            }
            else
            {
                correctNumber=false;
                wholeExpresion&=correctNumber;
                cout<<"Pozycja nr: "<<i+1<<" w wyrazeniu jest niepoprawna. Popraw!\n";

            }
            temp+=data[i];
            break;
        case 8:
            if (data[i]>47 && data[i]<58)
            {
                correctNumber=true;
                wholeExpresion&=correctNumber;

            }
            else
            {
                correctNumber=false;
                wholeExpresion&=correctNumber;
                cout<<"Pozycja nr: "<<i+1<<" w wyrazeniu jest niepoprawna. Popraw!\n";

            }
            temp+=data[i];
            break;
        case 9:
            if (data[i]>47 && data[i]<58)
            {
                correctNumber=true;
                wholeExpresion&=correctNumber;

            }
            else
            {
                correctNumber=false;
                wholeExpresion&=correctNumber;
                cout<<"Pozycja nr: "<<i+1<<" w wyrazeniu jest niepoprawna. Popraw!\n";

            }
            temp+=data[i];
            break;
        }

        i++;
    }
    if (data.length()!=10){
        wholeExpresion=false;
        cout<<"Dlugosc daty jest zla\n";
    }

    cout<<"Format daty jest: YYYY-MM-DD\n";
    cout<<"A wpisales        "<<temp;
    cout<<"\nZaliczamy "<<wholeExpresion;
}

*/

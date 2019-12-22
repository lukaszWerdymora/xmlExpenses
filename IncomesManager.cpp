#include "IncomesManager.h"

void IncomesManager :: loadAllIncomesFromFilleToVector (int ID_LOGGED_USER)
{
    incomes= incomesFileManager.laodAllIncomesLoggedUser(ID_LOGGED_USER);


}
Income IncomesManager :: returnSingleIncome()
{
    Income income;
    double value=0;
    string ifDataToday="";
    string date="";
    string stringIncome="";
    string stringTag="";
    income.setIncomeID(returnLastIdIncome()+1);
    income.setIdLoggedUser (ID_LOGGED_USER);
    cout<<"Podaj tytul wplywu\n";
    getline(cin, stringIncome);

    cout<<"Podaj wartos wplywu\n";
    cin>>value;
    cin.ignore();
    income.setValue (value);

    cout<< "Czy wplyw z dzisiejszego dnia: t/n -> wpisz odpowiednie ";
    cin>>ifDataToday;
    cin.ignore();
    if (ifDataToday=="t")
    {
        income.setDate (HelpMethods :: getDateFromSystem());
    }
    else if (ifDataToday=="n")
    {
        do
        {
            cout<<"Wpisz date w formacie YYYY-MM-DD\n";
            cin>>date;
            cin.ignore();

            income.setDate(date);

        }
        while (!HelpMethods :: correctData (date));

    }
    cout<<"Podaj kategorie\n";
    getline(cin,stringTag);
    income.setTag (stringTag);

    income.setIncome (stringIncome);

    return income;
}
void IncomesManager :: addNewIncome()
{

    Income income;
    income=returnSingleIncome();
    incomes.push_back(income);
    incomesFileManager.saveNewIncomeToFile(income);

}

int IncomesManager :: returnLastIdIncome ()
{
    int lastIdFromFile=0;
    int lastIdFromVector=0;
    if (incomes.size()!=0)
    {
        lastIdFromVector=incomes.back().getIncomeID();
    }
    lastIdFromFile=incomesFileManager.getIdLastIncome();

    if (lastIdFromFile<lastIdFromVector)
    {
        return lastIdFromVector;
    }
    else
    {
        return lastIdFromFile;
    }
}

void IncomesManager :: toPrint()
{
    vector <Income>:: iterator itr=incomes.begin();

    for (itr; itr!=incomes.end(); itr++)
    {
        cout<<itr->getIncomeID()<<endl;
        cout<<itr->getIdLoggedUser()<<endl;
        cout<<itr->getDate()<<endl;
        cout<<itr->getValue()<<endl;
        cout<<itr->getIncome()<<endl;
        cout<<itr->getTag()<<endl;
    }
}
double IncomesManager :: monthlyIncomes()
{

    string monthToCalculateIncomes="";
    string monthFromVector="";
    string yearFromVector="";
    string fullDateFromFile="";
    double monthlyIncomes=0.0;
    vector <Income>::iterator itr;
    string currentYear="";
    currentYear=HelpMethods :: getYearFromSystem();

    cout<<endl<<"Podaj miesiac za ktory chesz uzyskac wykaz wplywow: ";
    cin>>monthToCalculateIncomes;

    if (HelpMethods :: ifProvidedMonthCorrectly (monthToCalculateIncomes))
    {

        monthToCalculateIncomes=HelpMethods:: returnTwoDigitsDate (monthToCalculateIncomes);

        for (itr=incomes.begin(); itr!=incomes.end(); itr++)
        {
            fullDateFromFile= itr->getDate();
            monthFromVector=HelpMethods :: returnMonthFromDate (fullDateFromFile);
            yearFromVector=HelpMethods :: returnYearFromDate (fullDateFromFile);

            if (monthToCalculateIncomes==monthFromVector && currentYear==yearFromVector)
            {
                monthlyIncomes+=itr->getValue();
            }
        }
        cout<<"\nW misiacu ";
        HelpMethods :: returnFullNameMonth(monthToCalculateIncomes);
        cout<<" zarobiono "<<monthlyIncomes<< " PLN";

    }
    else
    {
        cout<<"\nNie ma takiego miesiaca";
    }

    if (monthlyIncomes>=0){
        return monthlyIncomes;
    }else {
        cout<<"Wystapil blad podczas liczenia wplywow";
        return 0;
    }


}


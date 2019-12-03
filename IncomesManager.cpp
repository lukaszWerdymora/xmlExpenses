#include "IncomesManager.h"

void IncomesManager :: loadAllIncomesFromFilleToVector (int ID_LOGGED_USER){
    incomes= incomesFileManager.laodAllIncomesLoggedUser(ID_LOGGED_USER);


}
Income IncomesManager :: returnSingleIncome(){
    Income income;
    double value=0;
    string ifDataToday="";
    string date="";
    string stringIncome="";
    string stringTag="";
    cout<<"Podaj tytul wplywu\n";
    getline(cin, stringIncome);

    cout<<"Podaj wartos wplywu\n";
    cin>>value;
    cin.ignore();
    //tu wpisac date
    cout<< "Czy wplyw z dzisiejszego dnia: t/n -> wpisz odpowiednie ";
    cin>>ifDataToday;
    cout<<" wpisales "<<ifDataToday;
    cin.ignore();
    if (ifDataToday=="t"){
        income.setDate (HelpMethods :: getDateFromSystem());
    }else if (ifDataToday=="n"){

        cout<<"Wpisz date w formacie YYYY-MM-DD\n";
        cin>>date;
        income.setDate(date);
    }
    cout<<"Podaj kategorie\n";
    getline(cin,stringTag);
    income.setIncomeID(returnLastIdIncome());

    income.setIdLoggedUser (ID_LOGGED_USER);
    income.setValue (value);

    //expense.setDate("2019-07-23");
    income.setIncome (stringIncome);
    income.setTag (stringTag);

    return income;


}
void IncomesManager :: addNewIncome(){

    Income income;
    income=returnSingleIncome();
    incomes.push_back(income);
    incomesFileManager.saveNewIncomeToFile(income);

}

int IncomesManager :: returnLastIdIncome (){
    int lastId=incomesFileManager.getIdLastIncome()+1;

    return lastId;

}

void IncomesManager :: toPrint(){
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

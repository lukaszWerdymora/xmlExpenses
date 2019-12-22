#include "ExpensesManager.h"
void ExpensesManager :: loadAllExpensesFromFileToVector (int ID_LOGGED_USER)
{
    expenses= expensesFileManager.loadAllExpensesLoggedUser(ID_LOGGED_USER);

}

void ExpensesManager :: addNewExpense ()
{
    Expense expense;
    expense= returnSingleExpense();
    expenses.push_back(expense);
    expensesFileManager.saveNewExpenseToFile (expense);

}

Expense ExpensesManager :: returnSingleExpense()
{

    Expense expense;
    double value=0;
    string ifDataToday="";
    string date="";
    string stringExpense="";
    string stringTag="";
    expense.setExpenseID(returnLastIdExpense()+1);
    expense.setIdLoggedUser (ID_LOGGED_USER);
    cout<<"Podaj tytul wydatku\n";
    getline(cin, stringExpense);

    cout<<"Podaj wartos wydatku\n";
    cin>>value;
    cin.ignore();
    expense.setValue (value);

    cout<< "Czy wydatek z dzisiejszego dnia: t/n -> wpisz odpowiednie ";
    cin>>ifDataToday;
    cin.ignore();
    if (ifDataToday=="t"){
        expense.setDate (HelpMethods :: getDateFromSystem());
    }else if (ifDataToday=="n"){
        do{
        cout<<"Wpisz date w formacie YYYY-MM-DD\n";
        cin>>date;
        cin.ignore();

        expense.setDate(date);

        }while (!HelpMethods :: correctData (date));

    }
    cout<<"Podaj kategorie\n";
    getline(cin,stringTag);
    expense.setTag (stringTag);

    expense.setExpense(stringExpense);

    return expense;

}



void ExpensesManager :: toPrint()
{
    vector <Expense>:: iterator itr=expenses.begin();
    cout<<endl;
    for (itr; itr!=expenses.end(); itr++)
    {

        cout<<itr->getExpenseID()<<endl;
        cout<<itr->getIdLoggedUser()<<endl;

        cout<<itr->getDate()<<endl;
        cout<<itr->getValue()<<endl;
        cout<<itr->getExpense()<<endl;
        cout<<itr->getTag()<<endl;
    }

}

int ExpensesManager :: returnLastIdExpense() // tak naprawde to set
{

    int lastIdFromFile=0;
    int lastIdFromVector=0;
    if (expenses.size()!=0){
       lastIdFromVector=expenses.back().getExpenseID();
    }
    lastIdFromFile=expensesFileManager.getIdLastExpense();

    if (lastIdFromFile<lastIdFromVector){
        return lastIdFromVector;
    }else{
        return lastIdFromFile;
    }

}


void ExpensesManager :: sumAllExpenses ()
{
    double allExpenses=0;
    vector <Expense>::iterator itr;
    for (itr=expenses.begin(); itr!=expenses.end(); itr++)
    {
        allExpenses+=itr->getValue();
    }

    cout<<endl<<"Do tej pory zostlo wydane: "<< allExpenses<<endl;
}


double ExpensesManager :: monthlyExpenses ()
{
    string monthToCalulateExpenses="";
    string monthFromVector="";
    string yearFromVector="";
    string fullDataFromFile="";
    double monthlyExpenses=0;
    vector <Expense>:: iterator itr;
    string currentYear="";
    currentYear=HelpMethods :: getYearFromSystem();

    cout<<endl<<"Podaj miesiac za ktory chesz uzyskac wykaz wydatkow: ";

    cin>>monthToCalulateExpenses;

    if (HelpMethods :: ifProvidedMonthCorrectly (monthToCalulateExpenses)){
            monthToCalulateExpenses=HelpMethods:: returnTwoDigitsDate (monthToCalulateExpenses);
    for (itr=expenses.begin(); itr!=expenses.end(); itr++)
    {
        fullDataFromFile=itr->getDate();
        monthFromVector=HelpMethods :: returnMonthFromDate (fullDataFromFile);
        yearFromVector=HelpMethods :: returnYearFromDate (fullDataFromFile);

        if ((monthToCalulateExpenses== monthFromVector) && (currentYear==yearFromVector)){
            monthlyExpenses+=itr->getValue();
        }
    }

    cout<<"\nW misiacu ";
    HelpMethods :: returnFullNameMonth(monthToCalulateExpenses);
    cout<<" wydano "<<monthlyExpenses<< " PLN";
    }
    else {

        cout<<"\nNie ma takiego miesiaca";
    }
    if (monthlyExpenses>=0){
        return monthlyExpenses;
    }else {
        cout<<"Wystapil blad podczas liczenia wplywow";
        return 0;
    }
}



/*
Expense ExpensesManager :: returnSingleExpense()
{

    Expense expense;
    expense.setExpenseID(returnLastIdExpense());

    expense.setIdLoggedUser (ID_LOGGED_USER);
    expense.setValue (10.1);
    expense.setDate (HelpMethods :: getDateFromSystem());
    //expense.setDate("2019-07-23");
    expense.setExpense ("Pralka");
    expense.setTag ("Sprzet domowy");

    return expense;

}



int ExpensesManager :: returnLastIdExpense() // tak naprawde to set
{


    return expensesFileManager.getIdLastExpense()+1;

}



*/

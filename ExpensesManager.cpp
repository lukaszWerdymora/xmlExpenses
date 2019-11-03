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
    expense.setExpenseID(returnLastIdExpense());

    expense.setIdLoggedUser (ID_LOGGED_USER);
    expense.setValue (10.1);
    expense.setDate (HelpMethods :: getDateFromSystem());
    //expense.setDate("2019-07-23");
    expense.setExpense ("Pralka");
    expense.setTag ("Sprzet domowy");

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


    return expensesFileManager.getIdLastExpense()+1;

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


void ExpensesManager :: monthlyExpenses ()
{
    string monthToCalulateExpenses="";
    string monthFromVector="";
    double monthlyExpenses=0;
    vector <Expense>:: iterator itr;
    cout<<endl<<"Podaj miesiac za ktory chesz uzyskac wykaz wydatkow: ";

    cin>>monthToCalulateExpenses;

    if (ifProvidedMonthCorrectly (monthToCalulateExpenses)){
            monthToCalulateExpenses=HelpMethods:: returnTwoDigitsDate (monthToCalulateExpenses);
    for (itr=expenses.begin(); itr!=expenses.end(); itr++)
    {
        monthFromVector=HelpMethods :: returnMonthFromDate (itr->getDate());
        if (monthToCalulateExpenses== monthFromVector){
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
}

bool ExpensesManager :: ifProvidedMonthCorrectly (string month){
    int monthToCheck=0;
    monthToCheck = HelpMethods ::conversionStringToInt( month );

    if ((monthToCheck > 0 )&& (monthToCheck < 13)){
        return true;
    }else {
        return false;
    }
}


#include "ExpensesManager.h"
void ExpensesManager :: loadAllExpensesFromFileToVector (int ID_LOGGED_USER){
    expenses= expensesFileManager.loadAllExpensesLoggedUser(ID_LOGGED_USER);
    numberOfExpenses=expensesFileManager.getLastExpenseID();
    //cout<<numberOfExpenses;
//wyswietl();
}

void ExpensesManager :: addNewExpense (){
    Expense expense;
    expense= returnSingleExpense();
    expenses.push_back(expense);
    expensesFileManager.saveNewExpenseToFile (expense);

    wyswietl();
}

Expense ExpensesManager :: returnSingleExpense(){

    Expense expense;

    //cout<<numberOfExpenses<<endl<<endl;
    expense.setExpenseID(numberOfExpenses+1);

    expense.setIdLoggedUser (ID_LOGGED_USER);
    expense.setValue (325);
    expense.setDate (20190913);

    expense.setExpense ("Pralka");
    expense.setTag ("Sprzet domowy");

    return expense;

}



void ExpensesManager :: wyswietl(){
    vector <Expense>:: iterator itr=expenses.begin();
    cout<<endl;
    for (itr; itr!=expenses.end(); itr++){

        cout<<itr->getExpenseID()<<"\texpensesID"<<endl;
        cout<<itr->getIdLoggedUser()<<"\tlogged user "<<endl;
        cout<<itr->getDate()<<"\tdata"<<endl;
        cout<<itr->getValue()<<"\twartosc"<<endl;
        cout<<itr->getExpense()<<"\twydatek"<<endl;
        cout<<itr->getTag()<<"\tznacznik"<<endl;
    }
}


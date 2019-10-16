#include "ExpensesManager.h"
void ExpensesManager :: loadAllExpensesFromFileToVector (int ID_LOGGED_USER){
    expenses= expensesFileManager.loadAllExpensesLoggedUser(ID_LOGGED_USER);

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
    double temp=23.4;
    expense.setExpenseID(returnLastIdExpense());
    //expense.setExpenseID(1);
    expense.setIdLoggedUser (ID_LOGGED_USER);
    expense.setValue (temp);
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

int ExpensesManager :: returnLastIdExpense(){// tak naprawde to set


        return expensesFileManager.getIdLastExpense()+1;

}

void ExpensesManager :: dateWithdash(){
    vector <Expense>:: iterator itr=expenses.begin();
    int dataWithDash;
    for (itr; itr!=expenses.end(); itr++){


        dataWithDash=itr->getDate();
        cout<<dataWithDash<<endl;


    }

}

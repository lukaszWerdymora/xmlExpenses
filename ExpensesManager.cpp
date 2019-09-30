#include "ExpensesManager.h"

void ExpensesManager :: addNewExpense (){
    Expense expense;
    expense= returnSingleExpense();
    expenses.push_back(expense);
    expensesFileManager.saveNewExpenseToFile (expense);

    wyswietl2();
}

Expense ExpensesManager :: returnSingleExpense(){

    Expense expense;

    expense.setExpenseID(1);
    expense.setIdLoggedUser (ID_LOGGED_USER);
    expense.setValue (100);
    expense.setDate (20190909);

    expense.setExpense ("Restauracja");
    expense.setTag ("Rozrywka");

    return expense;

}

void ExpensesManager :: wyswietl(){

    for (int i =0; i<expenses.size(); i++){

        cout<<expenses[i].getExpenseID()<<endl;
        cout<<expenses[i].getIdLoggedUser()<<endl;;
        cout<<expenses[i].getDate()<<endl;;
        cout<<expenses[i].getExpense()<<endl;;
        cout<<expenses[i].getValue()<<endl;;
        cout<<expenses[i].getTag()<<endl;;
    }
}
void ExpensesManager :: wyswietl2(){
    vector <Expense>:: iterator itr=expenses.begin();

    for (itr; itr!=expenses.end(); itr++){

        cout<<itr->getExpenseID()<<endl;
        cout<<itr->getIdLoggedUser()<<endl;
        cout<<itr->getDate()<<endl;
        cout<<itr->getExpense()<<endl;
        cout<<itr->getValue()<<endl;
        cout<<itr->getTag()<<endl;
    }
}

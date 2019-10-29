#include "ExpensesManager.h"
void ExpensesManager :: loadAllExpensesFromFileToVector (int ID_LOGGED_USER){
    expenses= expensesFileManager.loadAllExpensesLoggedUser(ID_LOGGED_USER);

}

void ExpensesManager :: addNewExpense (){
    Expense expense;
    expense= returnSingleExpense();
    expenses.push_back(expense);
    expensesFileManager.saveNewExpenseToFile (expense);

}

Expense ExpensesManager :: returnSingleExpense(){

    Expense expense;
    expense.setExpenseID(returnLastIdExpense());

    expense.setIdLoggedUser (ID_LOGGED_USER);
    expense.setValue (45.3);
    expense.setDate (HelpMethods :: getDateFromSystem());

    expense.setExpense ("Pralka");
    expense.setTag ("Sprzet domowy");

    return expense;

}



void ExpensesManager :: toPrint(){
    vector <Expense>:: iterator itr=expenses.begin();
    cout<<endl;
    for (itr; itr!=expenses.end(); itr++){

        cout<<itr->getExpenseID()<<endl;
        cout<<itr->getIdLoggedUser()<<endl;

        cout<<itr->getDate()<<endl;
        cout<<itr->getValue()<<endl;
        cout<<itr->getExpense()<<endl;
        cout<<itr->getTag()<<endl;
    }
}

int ExpensesManager :: returnLastIdExpense(){// tak naprawde to set


        return expensesFileManager.getIdLastExpense()+1;

}


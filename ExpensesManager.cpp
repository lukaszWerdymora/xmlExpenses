#include "ExpensesManager.h"

void ExpensesManager :: addNewExpense (){
    Expense expense;
    expense= returnSingleExpense();
    expensesFileManager.saveNewExpenseToFile (expense);
}

Expense ExpensesManager :: returnSingleExpense(){

    Expense expense;

    expense.setValue (100);
    expense.setDate (20190909);
    expense.setIdLoggedUser (1);
    expense.setExpense ("Restauracja");
    expense.setTag ("Rozrywka");

    return expense;

}


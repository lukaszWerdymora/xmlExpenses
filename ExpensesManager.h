#ifndef EXPENSESMANAGER_H
#define EXPENSESMANAGER_H

#include <iostream>
#include <vector>;
#include "Expense.h"
#include "ExpensesFileManager.h"
#include "helpMethods.h"
using namespace std;

class ExpensesManager {
    ExpensesFileManager expensesFileManager;
    Expense returnSingleExpense();
    int ID_LOGGED_USER;
    int newExpenseID;
    vector <Expense> expenses;
    int returnLastIdExpense();

public:
    ExpensesManager (string fileName,int idLoggedUser) : expensesFileManager (fileName),ID_LOGGED_USER (idLoggedUser) {
        loadAllExpensesFromFileToVector(ID_LOGGED_USER);
    };

    void toPrint();// zmien nazwe

    void addNewExpense();
    void loadAllExpensesFromFileToVector(int ID_LOGGED_USER);
    void sumAllExpenses();
    void monthlyExpenses();


};
#endif // EXPENSESmANAGER_H

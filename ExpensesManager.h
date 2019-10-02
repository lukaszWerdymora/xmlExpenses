#ifndef EXPENSESMANAGER_H
#define EXPENSESMANAGER_H

#include <iostream>
#include <vector>;
#include "Expense.h"
#include "ExpensesFileManager.h"
using namespace std;

class ExpensesManager {
    ExpensesFileManager expensesFileManager;
    Expense returnSingleExpense();
    int ID_LOGGED_USER;
    int newExpenseID;
    vector <Expense> expenses;
    int numberOfExpenses;


public:
    ExpensesManager (string fileName,int idLoggedUser) : expensesFileManager (fileName),ID_LOGGED_USER (idLoggedUser) {
        loadAllExpensesFromFileToVector(ID_LOGGED_USER);
    };

    void wyswietl();// zmien nazwe

    void addNewExpense();
    void loadAllExpensesFromFileToVector(int ID_LOGGED_USER);
};
#endif // EXPENSESmANAGER_H

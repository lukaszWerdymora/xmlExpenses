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
    vector <Expense> expenses;

public:
    ExpensesManager (string fileName,int idLoggedUser) : expensesFileManager (fileName),ID_LOGGED_USER (idLoggedUser) {};

    void wyswietl();// zmien nazwe
    void wyswietl2();
    void addNewExpense();
};
#endif // EXPENSESmANAGER_H

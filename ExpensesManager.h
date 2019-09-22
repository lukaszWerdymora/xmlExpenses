#ifndef EXPENSESMANAGER_H
#define EXPENSESMANAGER_H

#include <iostream>
#include "Expense.h"
#include "ExpensesFileManager.h"
using namespace std;

class ExpensesManager {
    ExpensesFileManager expensesFileManager;
    Expense returnSingleExpense();
    int ID_LOGGED_USER;

public:
    ExpensesManager (string fileName,int idLoggedUser) : expensesFileManager (fileName),ID_LOGGED_USER (idLoggedUser) {};


    void addNewExpense();
};
#endif // EXPENSESmANAGER_H

#ifndef EXPENSESMANAGER_H
#define EXPANSESMANAGER_H

#include <iostream>
#include "Expense.h"
#include "ExpensesFileManager.h"
using namespace std;

class ExpensesManager {
    ExpensesFileManager expensesFileManager;
    Expense returnSingleExpense();

public:
    ExpensesManager (string fileName) : expensesFileManager (fileName){};


    void addNewExpense();
};
#endif // EXPENSESmANAGER_H

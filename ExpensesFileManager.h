#ifndef EXPENSESFILEMANAFER_H
#define EXPENSESFILEMANAFER_H

#include <iostream>
#include <vector>
#include "Markup.h"
#include "Expense.h"
#include "helpMethods.h"

using namespace std;
class ExpensesFileManager {
    CMarkup xml;
    int lastExpenseID;
    const string NAME_EXPENSES_FILE;
    void creatNewForm();
public:
    ExpensesFileManager (string nameExpensesFile) : NAME_EXPENSES_FILE (nameExpensesFile){};
    void saveNewExpenseToFile(Expense expense);
    Expense loadExpanseFromFile();
    vector <Expense> loadAllExpensesLoggedUser(int idLoggedUser);
    int getLastExpenseID();

};

#endif // EXPENSESFILEMANAFER_H

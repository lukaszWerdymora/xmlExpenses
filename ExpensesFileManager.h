#ifndef EXPENSESFILEMANAFER_H
#define EXPENSESFILEMANAFER_H

#include <iostream>
#include "Markup.h"
#include "Expense.h"

using namespace std;
class ExpensesFileManager {
    CMarkup xml;
    const string NAME_EXPANSES_FILE= "xmlExpenses.xml";
    void creatNewForm();
public:
    ExpensesFileManager (string nameExpensesFile) : NAME_EXPANSES_FILE (nameExpensesFile){};
    void saveNewExpenseToFile(Expense expense);
};

#endif // EXPENSESFILEMANAFER_H

#ifndef EXPENSESCONTROLPROGRAM_H
#define EXPENSESCONTROLPROGRAM_H

#include <iostream>
#include "UserManager.h"
#include "ExpensesManager.h"
#include "IncomesManager.h"

using namespace std;

class ExpensesControlProgram {

    UserManager userManager;
    ExpensesManager *expensesManager;
    IncomesManager *incomesManager;
    const string NAME_EXPENSES_FILE;
    const string NAME_INCOMES_FILE;

public:
    ExpensesControlProgram (string fileNameWithUsers, string nameExpensesFile, string nameIncomesFile)
    : userManager (fileNameWithUsers), NAME_EXPENSES_FILE (nameExpensesFile), NAME_INCOMES_FILE (nameIncomesFile)
    {
        expensesManager=NULL;
        incomesManager= NULL;
    };
    ~ExpensesControlProgram () {
        delete expensesManager;
        expensesManager=NULL;
        delete incomesManager;
        incomesManager=NULL;
    };
    void registerUser();
    int loggingUser ();
    void changingPassword();
    void loggedOutUser();
    void addNewExpenses();
    void addNewIncomes();
    void loadExpensesFromFileToVector();
    void toPrintExpenses();
    void toPrintIncomes();
    void sumAllExpenses();
    double monthlyExpenses();
    void mainMenu();
    void sumMonthlyExpenses ();
    double monthlyIncomes();
    void balanceInMonth();

};

#endif // EXPENSESCONTROLPROGRAM_H

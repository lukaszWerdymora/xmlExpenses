#ifndef EXPENSESCONTROLPROGRAM_H
#define EXPENSESCONTROLPROGRAM_H

#include <iostream>
#include "UserManager.h"
#include "ExpensesManager.h"

using namespace std;

class ExpensesControlProgram {

    UserManager userManager;
    ExpensesManager *expensesManager;
    const string NAME_EXPENSES_FILE;
public:
    ExpensesControlProgram (string fileNameWithUsers, string nameExpensesFile)
    : userManager (fileNameWithUsers), NAME_EXPENSES_FILE (nameExpensesFile)
    {
        expensesManager=NULL;
    };
    ~ExpensesControlProgram () {
        delete expensesManager;
        expensesManager=NULL;
    };
    void registerUser();
    int loggingUser ();
    void changingPassword();
    void loggedOutUser();
    void addNewExpenses();
    void loadExpensesFromFileToVector();
};

#endif // EXPENSESCONTROLPROGRAM_H

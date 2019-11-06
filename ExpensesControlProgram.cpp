#include "ExpensesControlProgram.h"

void ExpensesControlProgram :: registerUser() {
    userManager.registerUser();
}
int ExpensesControlProgram :: loggingUser() {
    userManager.loggingUser();
    if (userManager.ifAnyUserIsLogg()) {
        expensesManager =new ExpensesManager (NAME_EXPENSES_FILE, userManager.getIdLoggedUser());

    }
}
void ExpensesControlProgram :: changingPassword() {
    userManager.changingPassword();
}
void ExpensesControlProgram :: loggedOutUser() {
    userManager.loggedOut();
    delete expensesManager;
    expensesManager=NULL;
}
void ExpensesControlProgram :: addNewExpenses() {
    expensesManager->addNewExpense();

}
void ExpensesControlProgram :: loadExpensesFromFileToVector() {
    expensesManager-> loadAllExpensesFromFileToVector(userManager.getIdLoggedUser());

}
void ExpensesControlProgram :: toPrintExpenses() {

    expensesManager->toPrint();

}

void ExpensesControlProgram :: sumAllExpenses() {
    expensesManager->sumAllExpenses();
}
void ExpensesControlProgram :: monthlyExpenses () {
    expensesManager->monthlyExpenses();
}

void ExpensesControlProgram :: mainMenu () {
    char choose;

    choose=userManager.mainMenu();
    switch (choose) {
    case '1':
        userManager.registerUser();
        break;
    case '2':
        userManager.loggingUser();
        if (userManager.ifAnyUserIsLogg()) {
            expensesManager =new ExpensesManager (NAME_EXPENSES_FILE, userManager.getIdLoggedUser());
        }
        break;
    case '9':
        userManager.loggedOut();
        delete expensesManager;
        expensesManager=NULL;
        cout<<"Koniec Programu";
        Sleep(1500);
        exit(0);
    }
}

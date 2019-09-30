#include "ExpensesControlProgram.h"

void ExpensesControlProgram :: registerUser(){
    userManager.registerUser();
}
int ExpensesControlProgram :: loggingUser(){
    userManager.loggingUser();
    if (userManager.ifAnyUserIsLogg()){
        expensesManager =new ExpensesManager (NAME_EXPENSES_FILE, userManager.getIdLoggedUser());

    }
}
void ExpensesControlProgram :: changingPassword(){
    userManager.changingPassword();
}
void ExpensesControlProgram :: loggedOutUser(){
    userManager.loggedOut();
    delete expensesManager;
    expensesManager=NULL;
}
void ExpensesControlProgram :: addNewExpenses(){
    expensesManager->addNewExpense();

}

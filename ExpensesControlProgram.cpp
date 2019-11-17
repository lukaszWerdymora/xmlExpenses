#include "ExpensesControlProgram.h"

void ExpensesControlProgram :: registerUser() {
    userManager.registerUser();
}
int ExpensesControlProgram :: loggingUser() {
    userManager.loggingUser();
    if (userManager.ifAnyUserIsLogg()) {
        expensesManager =new ExpensesManager (NAME_EXPENSES_FILE, userManager.getIdLoggedUser());
        incomesManager= new IncomesManager (NAME_INCOMES_FILE, userManager.getIdLoggedUser());

    }
}
void ExpensesControlProgram :: changingPassword() {
    userManager.changingPassword();
}
void ExpensesControlProgram :: loggedOutUser() {
    userManager.loggedOut();
    delete expensesManager;
    expensesManager=NULL;
    delete incomesManager;
    incomesManager=NULL;
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
        //userManager.registerUser();
        registerUser();
        break;
    case '2':
        loggingUser();
        cout<<">>>>>>>> Menu wydatkow i zarobkow <<<<<<<<\n\n";
        cout<<"1. Wyswietl wplywy\n";// dopisz aby od razu sumowalo
        cout<<"2. Wyswietl wydatki\n";//dopisz aby od razu sumowalo
        cout<<"3. Dodaj wp³w\n";
        cout<<"4. Dodaj wydatki\n";
        cout<<"5. Oblicz bilans wplyw - wydatki w danym miesiacu\n";


        /*
        userManager.loggingUser();
        if (userManager.ifAnyUserIsLogg()) {
            expensesManager =new ExpensesManager (NAME_EXPENSES_FILE, userManager.getIdLoggedUser());
            incomesManager= new IncomesManager (NAME_INCOMES_FILE, userManager.getIdLoggedUser());
        }
        */
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

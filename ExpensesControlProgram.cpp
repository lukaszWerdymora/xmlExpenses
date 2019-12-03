#include "ExpensesControlProgram.h"

void ExpensesControlProgram :: registerUser()
{
    userManager.registerUser();
}
int ExpensesControlProgram :: loggingUser()
{
    int idLoggedUser=0;
    idLoggedUser=userManager.loggingUser();
    if (userManager.ifAnyUserIsLogg())
    {
        expensesManager =new ExpensesManager (NAME_EXPENSES_FILE, userManager.getIdLoggedUser());
        incomesManager= new IncomesManager (NAME_INCOMES_FILE, userManager.getIdLoggedUser());

    }
    return idLoggedUser;
}
void ExpensesControlProgram :: changingPassword()
{
    userManager.changingPassword();
}
void ExpensesControlProgram :: loggedOutUser()
{
    userManager.loggedOut();
    delete expensesManager;
    expensesManager=NULL;
    delete incomesManager;
    incomesManager=NULL;
}
void ExpensesControlProgram :: addNewExpenses()
{
    expensesManager->addNewExpense();

}
void ExpensesControlProgram :: addNewIncomes()
{
    incomesManager-> addNewIncome();
}
void ExpensesControlProgram :: loadExpensesFromFileToVector()
{
    expensesManager-> loadAllExpensesFromFileToVector(userManager.getIdLoggedUser());

}
void ExpensesControlProgram :: toPrintExpenses()
{

    expensesManager->toPrint();

}
void ExpensesControlProgram :: toPrintIncomes()
{
    incomesManager->toPrint();
}

void ExpensesControlProgram :: sumAllExpenses()
{
    expensesManager->sumAllExpenses();
}
void ExpensesControlProgram :: monthlyExpenses ()
{
    expensesManager->monthlyExpenses();
}

void ExpensesControlProgram :: mainMenu ()
{
    char choose='0';
    int choiceMinorMenu=0;
    int idLoggedUser=0;
    bool ifLoggedOut=true;

    do
    {
        choose=userManager.mainMenu();
        switch (choose)
        {
        case '1':
            //userManager.registerUser();
            registerUser();
            break;
        case '2':
            idLoggedUser = loggingUser();
            ifLoggedOut=false;
            if (idLoggedUser!=0)
            {
                do
                {
                    cout<<"\n>>>>>>>> Menu wydatkow i zarobkow <<<<<<<<\n\n";
                    cout<<"1. Wyswietl wplywy\n";// dopisz aby od razu sumowalo
                    cout<<"2. Wyswietl wydatki\n";//dopisz aby od razu sumowalo
                    cout<<"3. Dodaj wplyw\n";
                    cout<<"4. Dodaj wydatki\n";
                    cout<<"5. Oblicz bilans wplyw - wydatki w danym miesiacu\n";
                    cout<<"0. Wylogowanie i powrot do Menu Glownego\n\n";

                    cin>>choiceMinorMenu;
                    cin.ignore();

                    switch (choiceMinorMenu)
                    {
                    case 1:
                        toPrintIncomes();
                        break;
                    case 2:
                        toPrintExpenses();
                        break;
                    case 3:

                        addNewIncomes();

                        break;
                    case 4:
                        addNewExpenses();
                    case 9:
                        break;
                    case 0:

                        userManager.loggedOut();
                        delete expensesManager;
                        expensesManager=NULL;
                        delete incomesManager;
                        incomesManager=NULL;
                        ifLoggedOut=true;
                        break;
                    }

                }
                while (ifLoggedOut!=true);
            }

            break;

        case '9':
            //userManager.loggedOut();
            //delete expensesManager;
            //expensesManager=NULL;
            cout<<"Koniec Programu";
            Sleep(1500);
            exit(0);
        }
    }
    while (choose!='0');

}

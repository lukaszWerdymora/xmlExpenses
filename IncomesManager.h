#ifndef INCOMESMANAGER_H
#define INCOMESMANAGER_H

#include <iostream>
#include <vector>
#include "Income.h"
#include "IncomesFileManager.h"
#include "helpMethods.h"

using namespace std;

class IncomesManager {
    IncomesFileManager incomesFileManager;
    int ID_LOGGED_USER;
    Income returnSingleIncome();
    vector <Income> incomes;



public:
    int returnLastIdIncome();// zmien na private
    IncomesManager (string fileName, int idLoggedUser) : incomesFileManager (fileName), ID_LOGGED_USER (idLoggedUser){

        loadAllIncomesFromFilleToVector (ID_LOGGED_USER);
    };
    void addNewIncome();
    void loadAllIncomesFromFilleToVector (int ID_LOGGED_USER);
    void toPrint();

};

#endif // INCOMESMANAGER_H

#ifndef INCOMESFILEMANAGER_H
#define INCOMESFILEMANAGER_H

#include <iostream>
#include <vector>
#include "Markup.h"
#include "helpMethods.h"
#include "Income.h"
using namespace std;

class IncomesFileManager {
    CMarkup xml;

    const string NAME_INCOMES_FILE;
    void creatNewForm();
    int idLastIncome;
    bool ifEmptyFile;
    bool ifFileExist;
    Income loadIncomeFromFile();
public:
    IncomesFileManager (string nameIncomesFile) : NAME_INCOMES_FILE (nameIncomesFile){};
    void saveNewIncomeToFile (Income income);
    int getIdLastIncome();
    vector <Income> laodAllIncomesLoggedUser (int loggedUser);
};
#endif // INCOMESFILEMANAGER_H

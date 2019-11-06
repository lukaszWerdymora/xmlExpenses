#ifndef INCOME_H
#define INCOME_H

#include <iostream>
#include "helpMethods.h"

using namespace std;

class Income {

    int idLoggedUser, incomeID;
    string income, tag;
    double value;
    string date;

public:
    void setIdLoggedUser        (int idLoggedUser);
    void setIncomeID            (int incomeID);
    void setValue               (double value);
    void setIncome              (string income);
    void setDate                (string date);
    void setTag                 (string tag);

    int getIdLoggedUser();
    int getIncomeID();
    double getValue();
    string getIncome();
    string getDate();
    string getTag();

};

#endif // INCOME_H

#ifndef EXPENSE_H
#define EXPENSE_H
#include <iostream>

using namespace std;

class Expense{
    int value, date, idLoggedUser;
    string expense, tag;

public:
    void setValue   (int value);
    void setDate    (int date);
    void setIdLoggedUser (int idLoggedUser);
    void setExpense (string expense);
    void setTag     (string tag);

    int getValue ();
    int getDate ();
    int getIdLoggedUser ();
    string getExpense ();
    string getTag ();


};
#endif // EXPENSES_H

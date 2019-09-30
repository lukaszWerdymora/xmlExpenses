#ifndef EXPENSE_H
#define EXPENSE_H
#include <iostream>

using namespace std;

class Expense{
    int value, date, idLoggedUser, expenseID;
    string expense, tag;

public:
    void setValue   (int value);
    void setDate    (int date);
    void setIdLoggedUser (int idLoggedUser);
    void setExpense (string expense);
    void setTag     (string tag);
    void setExpenseID (int expenseID);

    int getValue ();
    int getDate ();
    int getIdLoggedUser ();
    int getExpenseID();
    string getExpense ();
    string getTag ();


};
#endif // EXPENSES_H

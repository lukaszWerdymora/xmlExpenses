#ifndef EXPENSE_H
#define EXPENSE_H
#include <iostream>

using namespace std;

class Expense{
    //int date, idLoggedUser, expenseID;
    int idLoggedUser, expenseID;
    string expense, tag;
    double value;
    string date;

public:
    void setValue   (double value);
    void setIdLoggedUser (int idLoggedUser);
    void setExpense (string expense);
    void setTag     (string tag);
    //void setDate    (int date);
    void setDate    (string date);
    void setExpenseID (int expenseID);

    double getValue ();

    int getIdLoggedUser ();
    int getExpenseID();
    string getExpense ();
    string getTag ();
    //int getDate ();
    string getDate();
};
#endif // EXPENSES_H

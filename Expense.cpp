#include "Expense.h"

void Expense :: setValue (double newValue){
    value = newValue;
}
void Expense :: setIdLoggedUser (int newIdLoggedUser){
    idLoggedUser= newIdLoggedUser;
}
void Expense :: setExpense (string newExpense){
    expense = newExpense;
}
void Expense :: setTag (string newTag){
    tag = newTag;
}
void Expense :: setDate (int newDate){
    date = newDate;
}
void Expense :: setExpenseID(int newExpenseID){
    expenseID=newExpenseID;
}
double Expense :: getValue () {return value;}

int Expense :: getIdLoggedUser () {return idLoggedUser;}
int Expense :: getExpenseID() {return expenseID;}

string Expense :: getExpense () {return expense;}
string Expense :: getTag () {return tag;}
int Expense :: getDate () {return date;}



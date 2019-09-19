#include "Expense.h"

void Expense :: setValue (int newValue){
    value = newValue;
}

void Expense :: setDate (int newDate){
    date = newDate;
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
int Expense :: getValue () {return value;}
int Expense :: getDate () {return date;}
int Expense :: getIdLoggedUser () {return idLoggedUser;}

string Expense :: getExpense () {return expense;}
string Expense :: getTag () {return tag;}




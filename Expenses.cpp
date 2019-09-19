#include "Expenses.h"

void Expenses :: setValue (int newValue){
    value = newValue;
}

void Expenses :: setDate (int newDate){
    date = newDate;
}
void Expenses :: setIdLoggedUser (int newIdLoggedUser){
    idLoggedUser= newIdLoggedUser;
}
void Expenses :: setExpense (string newExpense){
    expense = newExpense;
}
void Expenses :: setTag (string newTag){
    tag = newTag;
}
int Expenses :: getValue () {return value;}
int Expenses :: getDate () {return date;}
int Expenses :: getIdLoggedUser () {return idLoggedUser;}

string Expenses :: getExpense () {return expense;}
string Expenses :: getTag () {return tag;}




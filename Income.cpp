#include "Income.h"

void Income :: setIdLoggedUser (int newIdLoggedUser){
    idLoggedUser=newIdLoggedUser;

}

void Income :: setIncomeID (int newIncomeID){
    incomeID=newIncomeID;
}
void Income :: setValue (double newValue){
    value= newValue;
}
void Income :: setIncome (string newIncome){
    income=newIncome;
}
void Income :: setDate (string newDate){
    date = newDate;
}
void Income :: setTag (string newTag){
    tag= newTag;
}

int Income :: getIdLoggedUser(){
    return idLoggedUser;
}
int Income :: getIncomeID(){
    return incomeID;
}
double Income :: getValue(){
    return value;
}

string Income :: getIncome (){
    return income;
}
string Income :: getDate (){
    return date;
}
string Income :: getTag(){
    return tag;
}


#include <iostream>
#include "Markup.h"
#include "User.h"
#include "Expense.h"
#include "UserManager.h"
#include "FileManager.h"
#include "ExpensesFileManager.h"
#include "ExpensesManager.h"
#include "helpMethods.h"

//gore wyrzuc
#include "ExpensesControlProgram.h"
//http://www.firstobject.com/dn_markupmethods.htm
using namespace std;


int main() {


    ExpensesControlProgram expensesControlProgram ("xmlUser.xml", "xmlExpenses.xml");
    //expensesControlProgram.loggingUser();
    //expensesControlProgram.changingPassword();
    //expensesControlProgram.addNewExpenses();
    //expensesControlProgram.addNewExpenses();
    //expensesControlProgram.loadExpensesFromFileToVector();
    //expensesControlProgram.toPrintExpenses();
    //expensesControlProgram.monthlyExpenses();
    //HelpMethods :: returnFullNameMonth ("11");
    expensesControlProgram.mainMenu();


    return 0;
}

    // Expense zmien na expenseID zrobione
    // 20191001 Poprawiles dzialanie programu i co najwazniejsze dodalesmetode pobierani z plku wydatkow tylko zalogowanego uzytkownika
    // napisz metode na uzyskiwanie expanseID. Napisales ale nie dzila poprawnie, trzeba ja wziac z pliku
    //napisz dobry plik z wydatkami i zapisz go w oddzielnym katalogu
    // zmien typ danych amount expenses na double

    //zrobione
    //napisz metode zwracajaca miesiac zrob najlepiej w klasie help methods
    //WAZNE sprawdz jak zapisuje sie data z zerem czy bez !!!!!!!!!!!!!!!!!!!!!!!!
    // przejrzyj nazwy metod
    //zmien User getDataNewUser(); na private

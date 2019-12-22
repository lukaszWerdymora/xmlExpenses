#include <iostream>
#include "Markup.h"
#include "User.h"
#include "Expense.h"
#include "UserManager.h"
#include "FileManager.h"
#include "ExpensesFileManager.h"
#include "ExpensesManager.h"
#include "helpMethods.h"
#include "IncomesManager.h"
//gore wyrzuc
#include "ExpensesControlProgram.h"
//http://www.firstobject.com/dn_markupmethods.htm
using namespace std;


int main() {


    ExpensesControlProgram expensesControlProgram ("xmlUser.xml", "xmlExpenses.xml","xmlIncomes.xml" );



     expensesControlProgram.mainMenu();
    return 0;
}

    // nie pobiera ostatniego incomeID z pliku
    // przejrzyj nazwy metod
    //zmien User getDataNewUser(); na private

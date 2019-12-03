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
    //IncomesManager incomesManager ("xmlIncomes.xml",1);
    //IncomesFileManager incomesFileManager ("xmlIncomes.xml");

    //HelpMethods :: returnFullNameMonth ("11");
    expensesControlProgram.mainMenu();
    //incomesManager.addNewIncome();
    //incomesManager.loadAllIncomesFromFilleToVector(1);

    //incomesFileManager.laodAllIncomesLoggedUser(1);
    //incomesFileManager.getIdLastIncome();
    //incomesManager.toPrint();
    //expensesControlProgram.loggingUser();
    //expensesControlProgram.toPrintExpenses();


    return 0;
}

    // nie pobiera ostatniego incomeID z pliku
    // przejrzyj nazwy metod
    //zmien User getDataNewUser(); na private

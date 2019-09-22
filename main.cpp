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
    expensesControlProgram.loggingUser();
    //expensesControlProgram.changingPassword();
    expensesControlProgram.addNewExpenses();
    return 0;
}


#include "ExpensesFileManager.h"

void ExpensesFileManager :: creatNewForm()
{
    bool ifFileExist=xml.Load (NAME_EXPENSES_FILE);

    if (!ifFileExist)
    {

        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Expenses");
    }

}

void ExpensesFileManager :: saveNewExpenseToFile (Expense expense)
{
    creatNewForm ();

    xml.FindElem();
    xml.IntoElem();

    xml.AddElem("Expense");
    xml.IntoElem();
    //xml.AddElem("UserID", user.getId());
    xml.AddElem("ExpenseID", expense.getExpenseID());
    xml.AddElem("UserID", expense.getIdLoggedUser());
    xml.AddElem("Value", expense.getValue());
    xml.AddElem("Data", expense.getDate());
    xml.AddElem("Expense", expense.getExpense());
    xml.AddElem("Tag", expense.getTag());

    xml.Save(NAME_EXPENSES_FILE);

}

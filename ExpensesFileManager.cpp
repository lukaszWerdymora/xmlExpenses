#include "ExpensesFileManager.h"

void ExpensesFileManager :: creatNewForm()
{
    bool ifFileExist=xml.Load (NAME_EXPANSES_FILE);

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
    xml.AddElem("UserID", 1);
    xml.AddElem("Value", expense.getValue());
    xml.AddElem("Data", expense.getDate());
    xml.AddElem("Expense", expense.getExpense());
    xml.AddElem("Tag", expense.getTag());
    //string document=xml.GetDoc();
    //cout<<document;
/*
    int getValue ();
    int getDate ();
    int getIdLoggedUser ();
    string getExpense ();
    string getTag ();
*/
    xml.Save(NAME_EXPANSES_FILE);

}

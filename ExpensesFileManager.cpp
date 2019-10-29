#include "ExpensesFileManager.h"

void ExpensesFileManager :: creatNewForm()
{
    ifFileExist=xml.Load (NAME_EXPENSES_FILE);

    if (!ifFileExist)
    {

        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Expenses");
        ifEmptyFile=true;

    }

}

void ExpensesFileManager :: saveNewExpenseToFile (Expense expense)
{
    creatNewForm ();

    xml.FindElem();
    xml.IntoElem();

    xml.AddElem("Expense");
    xml.IntoElem();

    xml.AddElem("ExpenseID", expense.getExpenseID());
    xml.AddElem("UserID", expense.getIdLoggedUser());
    //xml.AddElem("Value",HelpMethods:: conversionDoubleToString () expense.getValue());
    xml.AddElem("Value",HelpMethods:: conversionDoubleToString (expense.getValue()) );
    xml.AddElem("Date", expense.getDate());
    xml.AddElem("Expense", expense.getExpense());
    xml.AddElem("Tag", expense.getTag());

    xml.Save(NAME_EXPENSES_FILE);

}
Expense ExpensesFileManager :: loadExpanseFromFile()
{

    Expense expense;

    if (xml.FindElem("ExpenseID"))
    {

        string tempExpenseID="";

        tempExpenseID=xml.GetData();
        expense.setExpenseID(HelpMethods :: conversionStringToInt (tempExpenseID));

    }
    if (xml.FindElem("UserID"))
    {
        string tempUserID="";

        tempUserID=xml.GetData();
        expense.setIdLoggedUser(HelpMethods :: conversionStringToInt (tempUserID));

    }


    if (xml.FindElem("Value"))
    {
        string tempValue="";
        tempValue=xml.GetData();
        expense.setValue(HelpMethods :: conversionStringToDouble (tempValue));

    }

    if (xml.FindElem("Date"))
    {
        string tempDate="";
        tempDate=xml.GetData();
        //expense.setDate(HelpMethods :: conversionStringToInt (tempDate));
        expense.setDate(xml.GetData());
        //expense.setDate(tempDate);
    }

    if (xml.FindElem("Expense"))
    {
        string tempE;
        tempE=xml.GetData();
        expense.setExpense(xml.GetData());

    }
    if (xml.FindElem("Tag"))
    {
        string tempT;
        tempT=xml.GetData();
        expense.setTag(xml.GetData());

    }

    return expense;
}

vector <Expense> ExpensesFileManager :: loadAllExpensesLoggedUser(int idLoggedUser)
{
    vector <Expense> expenses;
    Expense expense;

    ifFileExist=xml.Load(NAME_EXPENSES_FILE);
    xml.ResetPos();

    xml.FindElem("Expenses");
    xml.IntoElem();

    while (xml.FindElem("Expense"))
    {

        xml.IntoElem();
        expense=loadExpanseFromFile();

        if (idLoggedUser==expense.getIdLoggedUser())
        {
            expenses.push_back(expense);
            xml.OutOfElem();
        }
        else
        {
            xml.OutOfElem();
        }
        idLastExpense=expense.getExpenseID();
    }
    return expenses;

}

int ExpensesFileManager :: getIdLastExpense()
{
    if (!ifFileExist){
        idLastExpense=0;
        return idLastExpense;
    }else{
        return idLastExpense;
    }

}


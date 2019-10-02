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
    xml.AddElem("Date", expense.getDate());
    xml.AddElem("Expense", expense.getExpense());
    xml.AddElem("Tag", expense.getTag());

    //xml.Save(NAME_EXPENSES_FILE);

}
Expense ExpensesFileManager :: loadExpanseFromFile()
{

    Expense expense;

    if (xml.FindElem("ExpenseID"))
    {

        string tempExpenseID="";
        tempExpenseID=xml.GetData();
        expense.setExpenseID(HelpMethods :: conversionStringToInt (tempExpenseID));
        //cout<<tempExpenseID<<" to jest ExpeID"<<endl;
    }
    if (xml.FindElem("UserID"))
    {
        string tempUserID="";
        tempUserID=xml.GetData();
        expense.setIdLoggedUser(HelpMethods :: conversionStringToInt (tempUserID));
        //cout<<tempUserID<<" to jest UserID"<<endl;
    }


    if (xml.FindElem("Value"))
    {
        string tempValue="";
        tempValue=xml.GetData();
        expense.setValue(HelpMethods :: conversionStringToInt (tempValue));
        //cout<<tempValue<<" to jest value"<<endl;
    }

    if (xml.FindElem("Date"))
    {
        string tempDate="";
        tempDate=xml.GetData();
        expense.setDate(HelpMethods :: conversionStringToInt (tempDate));
        //cout<<tempDate<<" to jest data"<<endl;
    }

    if (xml.FindElem("Expense")){
        string tempE;
        tempE=xml.GetData();
        expense.setExpense(xml.GetData());
        //cout<<tempE<<" to jest wydatek"<<endl;
    }
    if (xml.FindElem("Tag")){
            string tempT;
            tempT=xml.GetData();
        expense.setTag(xml.GetData());
        //cout<<tempT<<" to jest znacznik"<<endl;
    }

    return expense;
}

vector <Expense> ExpensesFileManager :: loadAllExpensesLoggedUser(int idLoggedUser){
    vector <Expense> expenses;
    Expense expense;

    xml.Load(NAME_EXPENSES_FILE);
    xml.ResetPos();

    xml.FindElem("Expenses");
    xml.IntoElem();

    while (xml.FindElem("Expense")){

        xml.IntoElem();
        expense=loadExpanseFromFile();

        if (idLoggedUser==expense.getIdLoggedUser()){
            expenses.push_back(expense);
        xml.OutOfElem();
        }else{
            xml.OutOfElem();
        }

    lastExpenseID=expense.getExpenseID();

    }


/*
    vector <Expense>:: iterator itr=expenses.begin();

    for (itr; itr!=expenses.end(); itr++){

        cout<<itr->getExpenseID()<<"\texpensesID"<<endl;
        cout<<itr->getIdLoggedUser()<<"\tlogged user "<<endl;
        cout<<itr->getDate()<<"\tdata"<<endl;
        cout<<itr->getValue()<<"\twartosc"<<endl;
        cout<<itr->getExpense()<<"\twydatek"<<endl;
        cout<<itr->getTag()<<"\tznacznik"<<endl<<endl;
    }
*/
    return expenses;

}
int ExpensesFileManager :: getLastExpenseID (){
    return lastExpenseID;
}

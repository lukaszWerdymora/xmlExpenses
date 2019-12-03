#include "IncomesFileManager.h"

void IncomesFileManager :: creatNewForm ()
{
    ifFileExist=xml.Load (NAME_INCOMES_FILE);

    if (!ifFileExist)
    {

        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomes");
        ifEmptyFile=true;

    }
}

void IncomesFileManager :: saveNewIncomeToFile (Income income)
{
    creatNewForm ();

    xml.FindElem();
    xml.IntoElem();

    xml.AddElem("Income");
    xml.IntoElem();

    xml.AddElem("IncomeID", income.getIncomeID());
    xml.AddElem("UserID", income.getIdLoggedUser());
    //xml.AddElem("Value",HelpMethods:: conversionDoubleToString () expense.getValue());
    xml.AddElem("Value",HelpMethods:: conversionDoubleToString (income.getValue()) );
    xml.AddElem("Date", income.getDate());
    xml.AddElem("Expense", income.getIncome());
    xml.AddElem("Tag", income.getTag());

    xml.Save(NAME_INCOMES_FILE);

}

vector <Income> IncomesFileManager :: laodAllIncomesLoggedUser (int idLoggedUser)
{
    vector <Income> incomes;
    Income income;

    ifFileExist=xml.Load(NAME_INCOMES_FILE);
    xml.ResetPos();

    xml.FindElem("Incomes");
    xml.IntoElem();

    while (xml.FindElem("Income"))
    {

        xml.IntoElem();
        income=loadIncomeFromFile();

        if (idLoggedUser==income.getIdLoggedUser())
        {
            incomes.push_back(income);
            xml.OutOfElem();
        }
        else
        {
            xml.OutOfElem();
        }
        idLastIncome=income.getIncomeID();
    //cout<<idLastIncome<<" IncomesFileManager :: laodAllIncomesLoggedUser (int idLoggedUser)\n";
    }

    return incomes;
}
Income IncomesFileManager :: loadIncomeFromFile ()
{
    Income income;

    if (xml.FindElem("IncomeID"))
    {

        string tempIncomeID="";

        tempIncomeID=xml.GetData();
        income.setIncomeID(HelpMethods :: conversionStringToInt (tempIncomeID));
        //income.setIncomeID(3);

    }
    if (xml.FindElem("UserID"))
    {
        string tempUserID="";

        tempUserID=xml.GetData();
        income.setIdLoggedUser(HelpMethods :: conversionStringToInt (tempUserID));

    }


    if (xml.FindElem("Value"))
    {
        string tempValue="";
        tempValue=xml.GetData();
        income.setValue(HelpMethods :: conversionStringToDouble (tempValue));

    }

    if (xml.FindElem("Date"))
    {
        string tempDate="";
        tempDate=xml.GetData();
        //expense.setDate(HelpMethods :: conversionStringToInt (tempDate));
        income.setDate(xml.GetData());
        //expense.setDate(tempDate);
    }

    if (xml.FindElem("Expense"))
    {
        string tempI;
        tempI=xml.GetData();
        income.setIncome(xml.GetData());

    }
    if (xml.FindElem("Tag"))
    {
        string tempT;
        tempT=xml.GetData();
        income.setTag(xml.GetData());

    }

    return income;
}
int IncomesFileManager :: getIdLastIncome ()
{

    if (!ifFileExist)
    {
        idLastIncome=0;

        return idLastIncome;
    }
    else
    {

        return idLastIncome;
    }

}

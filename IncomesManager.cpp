#include "IncomesManager.h"

void IncomesManager :: loadAllIncomesFromFilleToVector (int ID_LOGGED_USER){
    incomes= incomesFileManager.laodAllIncomesLoggedUser(ID_LOGGED_USER);


}
Income IncomesManager :: returnSingleIncome(){
    Income income;

    income.setIncomeID(returnLastIdIncome());

    income.setIdLoggedUser (ID_LOGGED_USER);
    income.setValue (2345.67);
    income.setDate (HelpMethods :: getDateFromSystem());
    //expense.setDate("2019-07-23");
    income.setIncome ("Wyplata");
    income.setTag ("Staly dochod");

    return income;


}
void IncomesManager :: addNewIncome(){

    Income income;
    income=returnSingleIncome();
    incomes.push_back(income);
    incomesFileManager.saveNewIncomeToFile(income);

}

int IncomesManager :: returnLastIdIncome (){
    int lastId=incomesFileManager.getIdLastIncome()+1;
    cout<< lastId<<" IncomesManager :: returnLastIdIncome ()\n";
    return lastId;

}

void IncomesManager :: toPrint(){
    vector <Income>:: iterator itr=incomes.begin();

    for (itr; itr!=incomes.end(); itr++)
    {

        cout<<itr->getIncomeID()<<endl;
        cout<<itr->getIdLoggedUser()<<endl;

        cout<<itr->getDate()<<endl;
        cout<<itr->getValue()<<endl;
        cout<<itr->getIncome()<<endl;
        cout<<itr->getTag()<<endl;
    }
}

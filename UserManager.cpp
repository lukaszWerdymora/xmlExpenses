#include "UserManager.h"
void UserManager :: registerUser()
{
    User user;

    user=getDataNewUser();
    users.push_back(user);
    fileManager.saveUserToFile (user);
}
User UserManager :: getDataNewUser ()
{
    User user;
    string login, name, surname, password;
    cout<<"Podaj dane uzytkownika do rejestracji: \nLogin: ";
    cin>>login;
    cout<<"\nImie: ";
    cin>>name;
    cout<<"\nNazwisko: ";
    cin>>surname;
    cout<<"\nHaslo: ";
    cin>>password;
    user.setId (returnIdNewUser());
    user.setLogin(login);
    user.setName (name);
    user.setSurname (surname);
    user.setPassword (password);

    return user;
}
void UserManager :: addUserToVector()
{
    User user;
    user=getDataNewUser();
    users.push_back(user);
}
void UserManager :: wyswietl ()
{
    //cout<<users.size();
    for (int i=0; i<users.size(); i++)
    {

        cout<<users[i].getId()<<endl;
        cout<<users[i].getLogin()<<endl;
        cout<<users[i].getName()<<endl;
        cout<<users[i].getSurname()<<endl;
        cout<<users[i].getPassword()<<endl;
    }

}

int UserManager :: loggingUser()
{
    //User user;


    string login="", password="";
    int step=0;
    cout<<endl<< "Podaj login: ";
    cin>>login;
    vector <User>::iterator itr =users.begin();
    while (itr!=users.end())
    {

        if (itr -> User :: getLogin() == login)
        {
            for (int numberAttempts =3; numberAttempts>0; numberAttempts--){
                cout << "\nPodaj haslo. Pozostalo prob: " << numberAttempts << ": ";
                //cin >> password;
                password=HelpMethods :: returnHiddenPassword();
                if (itr ->User :: getPassword() == password){
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    idLoggedUser= itr -> User :: getId();
                    return idLoggedUser;
                }
            }
            cout << "\nWprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return 0;

        }
        itr++;

    }

    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");

return 0;
}

int UserManager :: returnIdNewUser(){
    int id=0;
    if (users.empty()==true){
        id=1;
    }else {
        id=users.back().getId()+1;
    }
    cout<<id;
    return id;
}
void UserManager :: loggedOut(){
    idLoggedUser=0;
    cout<<"\nZostales wylogowany\n";
    Sleep(1000);
}

bool UserManager :: ifAnyUserIsLogg(){
    if (idLoggedUser > 0){
        return true;
    }else {
        return false;
    }

}
void UserManager :: changingPassword(){
    cin.clear();
    cin.ignore (1000,'\n');

    if (ifAnyUserIsLogg()){
    cout<<"\nPodaj nowe haslo\n";
    string newPassword="";
    cin>>newPassword;

        for (vector <User>::iterator itr=users.begin(); itr !=users.end(); itr++){
            if (itr -> User::getId()==idLoggedUser){
                itr -> User :: setPassword (newPassword);
                fileManager.changePassword(idLoggedUser, newPassword);

            }
        }
    } else {
        cout<<"Nie jestes zalogowany";
    }

}
int UserManager :: getIdLoggedUser(){

    return idLoggedUser;
}

char UserManager :: mainMenu (){
        char wybor;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    wybor = HelpMethods :: returnSingleDigit();

}

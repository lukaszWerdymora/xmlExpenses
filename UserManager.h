#ifndef USERMANAGER_H
#define USERMANAGER_H

#include "User.h"
#include "FileManager.h"
#include <vector>
#include <windows.h>

using namespace std;

class UserManager {
    vector <User> users;
    FileManager fileManager;
    int idLoggedUser;
    int returnIdNewUser();


public:
    UserManager (string fileNameWithUsers) : fileManager (fileNameWithUsers){
    idLoggedUser=0;
    users=fileManager.loadAllUsersFromFileToVector();
    };
    ~UserManager(){//dopisales nie wiadomo czy potrzebne
        //loggedOut();
    };
    User getDataNewUser();//zmien to pozniej na private
    int getIdLoggedUser();
    void addUserToVector();
    void registerUser();
    void wyswietl ();
    int loggingUser();
    void loggedOut();
    bool ifAnyUserIsLogg();
    void changingPassword();
    char mainMenu ();



};

#endif // USERMANAGER_H

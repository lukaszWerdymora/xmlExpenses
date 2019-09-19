#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "User.h"
#include "Markup.h"
#include "helpMethods.h"
#include <vector>
using namespace std;

class FileManager {
    CMarkup xml;

    const string NAME_FILE="xmlUser.xml";
    User loadUserFromFile ();

public:
    void changePassword(int idUserToChange, string newPassword);//zmien na private, to moze byc nie potrzebne
    int returnLastID ();//zmien na private zwrot Id oststniego uzytkownika ma sie odbywac po vector
    //vector <User> loadFromFileToVectorAllUsers (CMarkup &xml);
    vector <User> loadAllUsersFromFileToVector();
    void loadFile(CMarkup &xml);
    FileManager (string fileName) : NAME_FILE (fileName){};

    void saveUserToFile (User user);
    void saveAllUsersFromVectorToFile (vector <User> users);

};
#endif // FILEMANAGER_H

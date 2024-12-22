#ifndef UserManager_h
#define UserManager_h

#include <iostream>
#include <vector>
#include <windows.h>
#include <sstream>

#include "User.h"
#include "UserFile.h"

using namespace std;

class UserManager
{
    int loggedUserId;
    vector <User> users;

    UserFile userFile;

    bool checkIfLoginExist (string &login);
    User enterUserData();
    void findUserByLogin(string &login);
    int findUserById ();


    public:
    UserManager(string userFileName) : userFile (userFileName)
    {
    loggedUserId = 0;
    users = userFile.loadUsersFromFile();
    }


    void registerUser();
    int logInUser();
    void changeUserPassword();
    void logOutUser();

    bool isUserLoggedIn();
    int getLoggedUserId();
    int getIdOfNewUser();



};

#endif

#ifndef UserFile_h
#define UserFile_h


#include <iostream>
#include <vector>
#include <cstdlib>

#include "User.h"
#include "Utils.h"
#include "File.h"

class File;

using namespace std;

class UserFile: public File
{


public:

    UserFile(string fileName) :  File(fileName){};

    vector <User> loadUsersFromFile();
    bool addUserToFile(const User &user);
    void changePasswordInFile(int id, string newPassword);


};

#endif

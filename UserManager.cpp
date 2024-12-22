#include "UserManager.h"


bool UserManager:: isUserLoggedIn()
{
    if (loggedUserId > 0)
        return true;
    else
        return false;
}


void UserManager::registerUser()
{
    User user = enterUserData();

    users.push_back(user);
    userFile.addUserToFile(user);
    //userFile.addUserToFile(User &user);
    cout << endl << "Account created successfully" << endl << endl;
    system("pause");
}

User UserManager:: enterUserData()
{
    User user;

    //uzytkownik.ustawId(pobierzIdNowegoUzytkownika());
    //user.id = findUserById(vector <User>::iterator & itr);
    user.id = findUserById();

    string login;

    do
    {
        cout << "Add login: ";
        cin >> login;
        user.login = login;
    }
    while (checkIfLoginExist(user.login) == true);

    string password;
    cout << "Add password: ";
    cin >> password;
    //uzytkownik.ustawHaslo(haslo);
    user.password = password;

    string firstName;
    cout << "Add first name: ";
    cin >> firstName;
    user.firstName = firstName;

    string lastName;
    cout << "Add last name: ";
    cin >> lastName;
    user.lastName = lastName;


    return user;
}

int UserManager:: findUserById()
{
    if (users.empty() == true)
        return 1;
    else
        return users.back().id + 1;
}




bool UserManager::checkIfLoginExist(string &login)
{

    for (int i = 0; i < users.size(); i++)
    {
        if (users[i].login == login)
        {
            cout << endl << "There is a user with this login." << endl;
            return true;
        }
    }
    return false;

}





int UserManager:: logInUser()
{

    User user;

    string login = "", password = "";
    cout << endl << "Enter login: ";
    cin >> login;

    user.login = login;

    for (int i = 0; i < users.size(); i++)
    {
        if (users[i].login == login)
        {
            for (int numberOfAttempts = 3; numberOfAttempts > 0; numberOfAttempts--)
            {
                cout << "Enter password . Remaining attempts: " << numberOfAttempts << ": ";
                cin >> password;

               user.password = password;

                if (users[i].password == password)
                {
                    cout << endl << "You've logged in." << endl << endl;
                    loggedUserId = users[i].id;

                    system("pause");
                    return loggedUserId;


                }
            }

            cout << "The wrong password has been entered 3 times." << endl;
            system("pause");
            return 0;

        }
    }
    cout << "There is no user with such a login" << endl << endl;
    system("pause");
    return 0;


}

int UserManager::getLoggedUserId()
{

    return loggedUserId;
}


void UserManager:: changeUserPassword()
{
    string newPassword = "";
    int id = 0;
    cout << "Enter new password: ";
    cin >> newPassword;

    for (int i = 0; i < users.size(); i++)
    {
        if (users[i].id == loggedUserId)
        {
            id = loggedUserId;
            users[i].password = newPassword;
            cout << "Password has been changed." << endl << endl;
            system("pause");
        }
    }
    userFile.changePasswordInFile(id, newPassword);
}





void UserManager::logOutUser()
{
    loggedUserId = 0;
}

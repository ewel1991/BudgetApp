#include "UserFile.h"


vector <User> UserFile:: loadUsersFromFile()
{
    User user;
    vector <User> users;
    CMarkup xml;

    bool fileExists = xml.Load ("users.xml");

    xml.FindElem(); // ROOT element is root
    xml.IntoElem(); // inside ROOT
    while ( xml.FindElem("User") )
    {
        xml.FindChildElem( "id" );
        user.id = stoi(xml.GetChildData());

        xml.FindChildElem( "firstName" );
        user.firstName = xml.GetChildData();

        xml.FindChildElem( "lastName" );
        user.lastName = xml.GetChildData();

        xml.FindChildElem( "login" );
        user.login = xml.GetChildData();

        xml.FindChildElem( "password" );
        user.password = xml.GetChildData();

        users.push_back(user);

    }

    xml.Save("users.xml");

    return users;
}


bool UserFile:: addUserToFile (const User &user)
{
    //User user;
    int userId = 0;

    CMarkup xml;

    bool fileExists = xml.Load ("users.xml");

    xml.FindElem(); // ROOT element is root
    xml.IntoElem(); // inside ROOT
    while ( xml.FindElem("User") )
    {
        xml.FindChildElem( "id" );
        userId = stoi(xml.GetChildData());
        //user.id = userId;
    }

    //cout << "Id: " << id << endl;

    if (!fileExists)
    {
        xml.AddElem ("ROOT");

    }

    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("id", userId+1);
    xml.AddElem("firstName", user.firstName);
    xml.AddElem("lastName", user.lastName);
    xml.AddElem("login", user.login);
    xml.AddElem("password", user.password);

    xml.Save("users.xml");
}


void UserFile:: changePasswordInFile (int id, string newPassword)
{

    CMarkup xml;

    bool fileExists = xml.Load ("users.xml");

    xml.FindElem(); // ROOT element is root
    xml.IntoElem(); // inside ROOT

    while ( xml.FindElem("User") )
    {
        xml.FindChildElem( "id" );

        if (id == stoi(xml.GetChildData()))
            {
                xml.FindChildElem( "password" );
                xml.SetChildData(newPassword);
            }

    }

    xml.Save("users.xml");
}

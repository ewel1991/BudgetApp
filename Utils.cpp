#include "Utils.h"



string Utils:: readLine()
{
    cin.sync();
    string line = "";
    getline(cin, line);
    return line;
}



char Utils::getCharacter()
{
    string text = "";
    char character  = {0};

    while (true)
    {
        getline(cin, text);

        if (text.length() == 1)
        {
            character = text[0];
            break;
        }
        cout << "This is not a single character. Type again." << endl;
    }
    return character;
}


string Utils:: changeDoubleIntoString(double amount)
{
std::ostringstream strs;
strs << amount;
std::string str = strs.str();

return str;
}

#include "Menus.h"


void Menus:: showTitle(string title )
{
    system("cls");

    cout << "             >>> "<< title << "<<<" << endl;
    cout << "-----------------------------------------------" << endl;

}

void Menus::showHomeMenu()
{

    //system("cls");
    cout << "1. LOGIN USER" << endl;
    cout << "2. REGISTER USER" << endl;
    cout << "9. EXIT" << endl;
    cout << "-----------------------------------------------" << endl;
    cout << "Your choice: ";

}


void Menus::showMainMenu()
{


    //system("cls");

    cout << "1. ADD INCOME" << endl;
    cout << "2. ADD EXPENSE" << endl;
    cout << "3. SHOW CURRENT MONTH BALANCE" << endl;
    cout << "4. SHOW PREVIOUS MONTH BALANCE" << endl;
    cout << "5. SHOW CUSTOM PERIOD BALANCE" << endl;
    cout << "-----------------------------------------------" << endl;
    cout << "6. CHANGE USER PASSWORD" << endl;
    cout << "7. LOG OUT USER" << endl;
    cout << "-----------------------------------------------" << endl;
    cout << "Your choice: ";




}

#ifndef BudgetMainApp_h
#define BudgetMainApp_h


#include <iostream>

#include "BudgetManager.h"
#include "UserManager.h"

using namespace std;

class BudgetMainApp
{

    UserManager userManager;

    BudgetManager *budgetManager;

    const string INCOME_FILE_NAME;
    const string EXPENSE_FILE_NAME;




public:

    BudgetMainApp(string userFileName, string incomeFileName, string expenseFileName)
        : userManager(userFileName), INCOME_FILE_NAME(incomeFileName), EXPENSE_FILE_NAME(expenseFileName)
    {
        budgetManager = NULL;
    };



    ~BudgetMainApp()
    {
        delete budgetManager;
        budgetManager = NULL;
    }


    bool isUserLoggedIn();
    void registerUser();
    void logInUser();
    void changeUserPassword();
    void logOutUser();

    void addIncome();
    void addExpense();
    void showCurrentMonthBalance();
    void showPreviousMonthBalance();
    void showCustomPeriodBalance();

};

#endif

#include "BudgetMainApp.h"

bool BudgetMainApp::isUserLoggedIn()
{
    userManager.isUserLoggedIn();
}

void BudgetMainApp::registerUser()
{
    userManager.registerUser();
}




void BudgetMainApp::logInUser()
{
    userManager.logInUser();

    if( userManager.isUserLoggedIn())
    {
        budgetManager = new BudgetManager (INCOME_FILE_NAME, EXPENSE_FILE_NAME, userManager.getLoggedUserId());
    }

}


void BudgetMainApp :: addIncome()
{
    if (userManager.isUserLoggedIn())
    {
        budgetManager->addIncome();
    }
}


void BudgetMainApp :: addExpense()
{
    if (userManager.isUserLoggedIn())
    {
        budgetManager->addExpense();
    }
}


void BudgetMainApp :: showCurrentMonthBalance()
{
    if (userManager.isUserLoggedIn())
    {
        budgetManager->showCurrentMonthBalance();
    }
}

void BudgetMainApp :: showPreviousMonthBalance()
{
    if (userManager.isUserLoggedIn())
    {
        budgetManager->showPreviousMonthBalance();
    }
}


void BudgetMainApp :: showCustomPeriodBalance()
{
    if (userManager.isUserLoggedIn())
    {
        budgetManager -> showCustomPeriodBalance();
    }
}

void BudgetMainApp::changeUserPassword()
{
    userManager.changeUserPassword();
}



void BudgetMainApp::logOutUser()
{

    userManager.logOutUser();
    delete budgetManager;
    budgetManager = NULL;

}

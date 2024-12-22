#ifndef BUDGETMANAGER_h
#define BUDGETMANAGER_h


#include <iostream>
#include <vector>
#include <windows.h>
#include <sstream>
#include <string>
#include <algorithm>
#include <iomanip>



#include "OperationFile.h"
#include "Operation.h"
#include "Utils.h"
#include "Menus.h"
#include "Type.h"
#include "CashMethods.h"
#include "DateMethods.h"

class BudgetManager
{
    const int LOGGED_USER_ID;
    OperationFile incomeFile;
    OperationFile expenseFile;
    vector <Operation> incomes;
    vector <Operation> expenses;

    Operation addOperationDetails(const Type &type);
    void showBalance (int startDate, int endDate);

public:
    BudgetManager(string incomeFileName, string expenseFileName, int loggedUserId)
    :LOGGED_USER_ID(loggedUserId), incomeFile(incomeFileName), expenseFile(expenseFileName)
{
    incomes = incomeFile.loadOperationsFromFile(LOGGED_USER_ID);
    expenses = expenseFile.loadOperationsFromFile(LOGGED_USER_ID);
}

void addIncome();
void addExpense();
void showCurrentMonthBalance();
void showPreviousMonthBalance();
void showCustomPeriodBalance();
void listItems (vector <Operation> items, int dateBegin, int dateEnd1);
double calculateBalance (vector <Operation> items, int dateBegin, int dateEnd1);

};





#endif

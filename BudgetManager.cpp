#include "BudgetManager.h"
using namespace std;

void BudgetManager:: addIncome()
{

    Operation operation;
    operation = addOperationDetails(INCOME);
    incomes.push_back(operation);
    if(incomeFile.addOperationToFile(operation))
    {
        cout << endl;
        cout << "New income added successfully" << endl;
    }


    else
        cout << "Error. Failed to add new income." << endl;

    system("pause");


}

void BudgetManager:: addExpense()
{

    Operation operation;
    operation = addOperationDetails(EXPENSE);
    expenses.push_back(operation);
    if(expenseFile.addOperationToFile(operation))
    {
        cout << endl;
        cout << "New expense added successfully" << endl;
    }


    else
        cout << "Error. Failed to add new expense." << endl;

    system("pause");
}

void BudgetManager:: showCurrentMonthBalance()
{
    cout << endl;
    cout << "Current month first date: " << DateMethods:: convertIntDateToStringWithDashes(DateMethods:: getCurrentMonthFirstDayDate()) << endl;
    cout << "Today is:                 " << DateMethods:: convertIntDateToStringWithDashes(DateMethods::getCurrentDate()) << endl;
    cout << endl;

    showBalance (DateMethods:: getCurrentMonthFirstDayDate(), DateMethods::getCurrentDate());
}

void BudgetManager:: showPreviousMonthBalance()
{
    cout << endl;
    cout << "Previous month first date: " << DateMethods:: convertIntDateToStringWithDashes(DateMethods:: getPreviousMonthFirstDayDate()) << endl;
    cout << "Previous month last date:  " << DateMethods:: convertIntDateToStringWithDashes(DateMethods:: getPreviousMonthLastDayDate()) << endl;
    cout << endl;


    showBalance (DateMethods:: getPreviousMonthFirstDayDate(), DateMethods::getPreviousMonthLastDayDate());
}


void BudgetManager:: showCustomPeriodBalance()
{
    int startDate, endDate;
    string startDateString, endDateString;

    do
    {
        cout << endl;
        cout << "Enter start date: ";
        startDateString = Utils:: readLine();
    }
    while (!DateMethods:: validateDate(startDateString));


    do
    {
        cout << "Enter end date: ";
        endDateString = Utils:: readLine();
    }
    while (!DateMethods:: validateDate(endDateString));

    startDate = DateMethods::convertStringDateToInt(startDateString);
    endDate = DateMethods::convertStringDateToInt(endDateString);

    showBalance (startDate, endDate);
}


Operation BudgetManager:: addOperationDetails(const Type &type)
{
    string typeDescription, tempDate, tempAmount;
    Operation operation;

    Menus:: showTitle("ADD OPERATION DETAILS");

    switch (type)
    {
    case INCOME:
        operation.id = incomeFile.getLastId() + 1;
        typeDescription = "income";
        break;

    case EXPENSE:
        operation.id = expenseFile.getLastId() + 1;
        typeDescription = "expense";
        break;
    }

    operation.userId =  LOGGED_USER_ID;

    do
    {
        cout << "Enter " << typeDescription << " date. Press 't' if you want to enter current date: ";
        tempDate = Utils:: readLine();
    }
    while (!DateMethods:: validateDate(tempDate));

    operation.date = DateMethods::convertStringDateToInt(tempDate);

    cout << "Enter " << typeDescription << " name: ";
    operation.item = Utils::readLine();

    do
    {
        cout << "Add " << typeDescription << " amount with up to two decimal places: ";
        tempAmount = Utils::readLine();
    }
    while (!CashMethods:: validateAmount(tempAmount));

    operation.amount = CashMethods:: changeFromStingIntoDouble (tempAmount);

    system("pause");

    return operation;

}

void BudgetManager:: showBalance (int startDate, int endDate)
{
    double incomeBalance = 0, expenseBalance = 0;

    cout << endl;
    cout << "-----------------------------------------------" << endl;
    cout << "Incomes: " << endl;
    cout << "-----------------------------------------------" << endl;
    sort(incomes.begin(), incomes.end(), [] (const Operation & a, const Operation & b)
    {
        return a.date < b.date;
    });


    listItems (incomes, startDate, endDate);
    incomeBalance = calculateBalance (incomes, startDate, endDate);
    cout << "-----------------------------------------------" << endl;
    cout << "Income balance:          " << incomeBalance;
    cout << endl;
    cout << endl;

    cout << "-----------------------------------------------" << endl;
    cout << "Expenses: " << endl;
    cout << "-----------------------------------------------" << endl;

    sort(expenses.begin(), expenses.end(), [] (const Operation & a, const Operation & b)
    {
        return a.date < b.date;
    });


    listItems (expenses, startDate, endDate);
    expenseBalance = calculateBalance (expenses, startDate, endDate);
    cout << "-----------------------------------------------" << endl;
    cout << "Expence balance:         " << expenseBalance;
    cout << endl;
    cout << endl;

    CashMethods:: calculateBalance (incomeBalance, expenseBalance);
    system("pause");


}

void BudgetManager:: listItems (vector <Operation> items, int dateBegin, int dateEnd1)
{
    //time_t dateCheck;

    cout << left << setw(5) <<"Id" << setw(20) << "Item" <<setw(15) <<"Amount" << setw(8) <<"Date" << endl;
    cout << endl;

    for (Operation item : items)
    {

        if (item.date >= dateBegin && item.date < dateEnd1 && item.userId == LOGGED_USER_ID)
        {

            cout << left << setw(5) <<item.id << setw(20) << item.item <<setw(15) <<item.amount << setw(8) <<DateMethods:: convertIntDateToStringWithDashes(item.date)<< endl;
            cout << endl;

        }

    }
}


double BudgetManager:: calculateBalance (vector <Operation> items, int dateBegin, int dateEnd)
{

    double  sum = 0;

    for (Operation item : items)
    {

        if (item.date >= dateBegin && item.date < dateEnd && item.userId == LOGGED_USER_ID)
        {
            sum += item.amount;
        }
    }

    return sum;
}



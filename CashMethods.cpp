#include "CashMethods.h"


double CashMethods:: changeFromStingIntoDouble (string tempAmount)
{
    double amountDouble;

    for (int i = 0; i < tempAmount.length(); i++)
    {
        if (tempAmount[i] == ',')
        {
            tempAmount.replace(i, 1, ".");
        }
    }

    amountDouble = stod (tempAmount);
    return amountDouble;
}


bool CashMethods::validateAmount(string amount)
{

    //string modifiedInput;

    for (int i = 0; i < amount.length(); i++)
    {
        if (amount[i] == ',')
        {
            amount.replace(i, 1, ".");
        }
    }

    size_t dotPosition = amount.find('.');

    if (dotPosition != std::string::npos) {

        string fractionalPart = amount.substr(dotPosition + 1);
        if (fractionalPart.length() > 2) {
            return false;
        }
    }
return true;
}



void CashMethods:: calculateBalance (double incomeSum, double expenseSum)
{
    if (incomeSum - expenseSum >= 0)
        cout << "You have profit of:      " << incomeSum - expenseSum << " zl" <<endl;

    else
        cout << "You have debt of: " << -(incomeSum - expenseSum) << " zl" << endl;

        cout << endl;
}

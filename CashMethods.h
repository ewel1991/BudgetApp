#ifndef CashMethods_h
#define CashMethods_h


#include <iostream>
#include <string>
#include <regex>



using namespace std;

class CashMethods
{

public:

static bool validateAmount (string amount);
static double changeFromStingIntoDouble (string tempAmount);
static void checkBalance (double incomeSum, double expenseSum);
static void  calculateBalance (double incomeSum, double expenseSum);

};

#endif

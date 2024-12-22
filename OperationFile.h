#ifndef OperationFile_h
#define OperationFile_h



#include <iostream>
#include <vector>

#include "Operation.h"
#include "Utils.h"
#include "File.h"

class File;

using namespace std;

class OperationFile: public File
{


public:

OperationFile(string fileName) :  File(fileName){};

vector <Operation> loadOperationsFromFile (const int loggedUserId);
bool addOperationToFile (const Operation &operation);




};

#endif


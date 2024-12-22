#include "OperationFile.h"

vector <Operation> OperationFile:: loadOperationsFromFile(const int loggedUserId)
{
    Operation operation;
    vector <Operation> operations;
    CMarkup xml;

    bool fileExists = xml.Load (getFileName().c_str());

    xml.FindElem(); // ROOT element is root
    xml.IntoElem(); // inside ROOT
    while ( xml.FindElem("Operation") )
    {
        xml.FindChildElem( "id" );
        operation.id = stoi(xml.GetChildData());
        setLastId(operation.id);


        xml.FindChildElem( "userId" );
        operation.userId = stoi(xml.GetChildData());

        xml.FindChildElem( "date" );
        operation.date = stoi(xml.GetChildData());

        xml.FindChildElem( "item" );
        operation.item = xml.GetChildData();

        xml.FindChildElem( "amount" );
        operation.amount = stod(xml.GetChildData());


        operations.push_back(operation);

    }

    xml.Save(getFileName().c_str());

    return operations;
}



bool OperationFile :: addOperationToFile(const Operation &operation)
{
    vector <Operation> operations;
    CMarkup xml;

    bool fileExists = xml.Load (getFileName().c_str());


    if (!fileExists)
    {
        xml.AddElem ("Root");

    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Operation");
    xml.IntoElem();
    setLastId(operation.id);
    xml.AddElem("id", operation.id);
    xml.AddElem("userId", operation.userId);
    xml.AddElem("date", operation.date);
    xml.AddElem("item", operation.item);
    xml.AddElem("amount", Utils:: changeDoubleIntoString(operation.amount));

    xml.Save(getFileName().c_str());

return true;
}

#ifndef FILE_h
#define FILE_h


#include <iostream>
#include <Markup.h>
#include <vector>
#include <string>


using namespace std;

class File
{

    const string FILE_NAME;
    int lastId;

public:

    File (string fileName) : FILE_NAME(fileName)
     {

     lastId = 0;

     }


    CMarkup xmlDoc;

    string getFileName();
    int getLastId();
    void setLastId(int id);




};

#endif

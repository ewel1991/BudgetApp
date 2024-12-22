#include "DateMethods.h"

bool DateMethods:: isYearLeap (int year)
{

    return (((year % 4 == 0) &&
             (year % 100 != 0)) ||
            (year % 400 == 0));

}


void DateMethods::calculateCurrentDate(std::map <string, int> &currentDate)
{
    auto currentTime = std::chrono::system_clock::now();
    time_t currentDateTime = std::chrono::system_clock::to_time_t(currentTime);

    std::tm currentTm;
    localtime_s(&currentTm, &currentDateTime);

    currentDate["year"] = currentTm.tm_year + 1900;
    currentDate["month"] = currentTm.tm_mon + 1;
    currentDate["day"] = currentTm.tm_mday;
}




bool DateMethods:: validateDate (std::string &date)
{
    int year, month, day;
    std::map<std::string, int> currentDate;
    std::stringstream ss;


    calculateCurrentDate(currentDate);

    if (date == "t" || date == "T")
    {
        ss << currentDate["year"] << "-" << (currentDate["month"] < 10 ? "0" : "") << currentDate["month"] << "-" << (currentDate["day"] < 10 ? "0" : "") << currentDate["day"];
        date = ss.str();
        return true;

    }

if (date.length() !=10)
    {
        cout << "Incorrect date format. Try again." << endl;
        return false;
    }

    if (!std::regex_match(date, regex ("[0-9]{4}-[0-9]{2}-[0-9]{2}")))
    {
        cout << "Incorrect date format. Try again." << endl;
        return false;
    }

    try
    {
        year = stoi(date.substr(0,4));
        month = stoi (date.substr(5,2));
        day = stoi (date.substr(8,2));
    }

    catch (const exception &e)
    {
        cout << "Exception occured: " << e.what() << endl;
        return false;
    }

    if (year < 2000 || year > currentDate["year"])
    {
        cout << "Invalid year. Try again." << endl;
        return false;
    }

    if (month < 1 || month > 12 || (year == currentDate["year"] && month > currentDate["month"]))
    {
        cout << "Invalid month. Try again." << endl;
        return false;
    }

    switch (month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:

        if (day > 31)
        {
            cout << "Invalid date. Try again." << endl;
            return false;
        }
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        if (day > 30)
        {
            cout << "Invalid day. Try again." << endl;
            return false;
        }
        break;

    case 2:
        if (DateMethods:: isYearLeap(year))
        {
            if (day > 29)
            {
                cout << "Invalid day. Try again" << endl;
                return false;
            }
        }
        else
        {
            if (day > 28)
            {
                cout << "Invalid day. Try again." << endl;
                return false;
            }
        }
        break;
    default:
        cout << "Invalid day. Try again." << endl;
        return false;
    }
    return true;

}




int DateMethods:: convertStringDateToInt(const string &dateAsString)
{
    string textWithoutDashes = "";
    int dateAsInt;

    for (int i= 0; i < dateAsString.length(); i++)
    {
        if (dateAsString[i] != '-')
        {
            textWithoutDashes += dateAsString[i];
        }
    }
    dateAsInt = stoi(textWithoutDashes);

    return dateAsInt;

}



int DateMethods:: getCurrentDate ()
{
    // Retrieve the current time as a chrono time point
    auto currentTime = std::chrono::system_clock::now();

    // Convert the chrono time point into a time_t (seconds since epoch)
    time_t currentDateTime = std::chrono::system_clock::to_time_t(currentTime);

    std::tm currentTm;

    // Convert the time_t into local time (broken-down format), storing the result in currentTm
    localtime_s(&currentTm, &currentDateTime);

    // Get the full year (tm_year is years since 1900, so add 1900)
    int year = currentTm.tm_year + 1900;

    // Get the month (tm_mon is 0-based, so add 1)
    int month = currentTm.tm_mon + 1;

    // Get the day of the month
    int day = currentTm.tm_mday;

    // Construct the date as an integer in the format YYYYMMDD
    // Multiply the year by 10000, the month by 100, and add the day
    int dateAsInt = year * 10000 + month * 100 + day;


    return dateAsInt;
}



int DateMethods:: getCurrentMonthFirstDayDate()
{

 // Get the current time
    auto currentTime = std::chrono::system_clock::now();
    std::time_t currentDateTime = std::chrono::system_clock::to_time_t(currentTime);

    // Convert to local time (tm structure)
    std::tm currentTm;
    localtime_s(&currentTm, &currentDateTime);

    // Set the day to the 1st of the current month
    currentTm.tm_mday = 1;


    // Normalize the structure (mktime will update tm_mday to the first day of the previous month)
    std::mktime(&currentTm);

    // currentTm.tm_mday now contains the first day of the previous month
    // Format the date in YYYYMMDD
    char buffer[9];
    strftime(buffer, sizeof(buffer), "%Y%m%d", &currentTm);

    // Convert the string to an integer
    int dateCurrentMonthFirstDate = std::stoi(buffer);

    return dateCurrentMonthFirstDate;
}


int DateMethods:: getPreviousMonthLastDayDate()
{
    auto currentTime1 = std::chrono::system_clock::now();
    std::time_t currentDateTime1 = std::chrono::system_clock::to_time_t(currentTime1);

    // Convert to local time (tm structure)
    std::tm currentTm1;
    localtime_s(&currentTm1, &currentDateTime1);


    // Set the day before teh 1st of the month
    currentTm1.tm_mday = 0;


    // Normalize the structure (mktime will update tm_mday to the last day of the previous month)
    std::mktime(&currentTm1);

    // currentTm.tm_mday now contains the last day of the previous month
    // Format the date in YYYYMMDD
    char buffer[9];
    strftime(buffer, sizeof(buffer), "%Y%m%d", &currentTm1);

    // Convert the string to an integer
    int datePreviousMonthLastDate = std::stoi(buffer);


    return datePreviousMonthLastDate;

}


int DateMethods:: getPreviousMonthFirstDayDate()
{
    // Get the current time
    auto currentTime = std::chrono::system_clock::now();
    std::time_t currentDateTime = std::chrono::system_clock::to_time_t(currentTime);

    // Convert to local time (tm structure)
    std::tm currentTm;
    localtime_s(&currentTm, &currentDateTime);

    //  Move to the previous month by setting the month to the current month - 1
    if (currentTm.tm_mon == 0) {
        // If it's January, we need to move back to December of the previous year
        currentTm.tm_mon = 11;  // December
        currentTm.tm_year--;    // Move to the previous year
    } else {
        currentTm.tm_mon--;  // Otherwise, just subtract one from the current month
    }

    // Set the day to the last day of the previous month (maximum possible day in the month)
    currentTm.tm_mday = 1;  // Set day to the 1ast of the current month
    std::mktime(&currentTm); // Normalize the structure to update tm_mday

    // currentTm.tm_mday now contains the last day of the previous month
    // Format the date in YYYYMMDD
    char buffer[9];
    strftime(buffer, sizeof(buffer), "%Y%m%d", &currentTm);


    int dateAsInt = std::stoi(buffer);

    return dateAsInt;

}


string DateMethods:: convertIntDateToStringWithDashes(int dateAsString)
{
    int year = dateAsString / 10000;
    int month = (dateAsString / 100) % 100;
    int day = dateAsString % 100;

    std::ostringstream formattedDate;
    formattedDate << year << "-"
                  << (month < 10 ? "0" : "") << month << "-"
                  << (day < 10 ? "0" : "") << day;

    return formattedDate.str();
}



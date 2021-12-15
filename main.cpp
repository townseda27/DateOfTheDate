/*
Author: Daniel Townsend

File Description: This program works with dates. It can either 
get the day of the week of a given date, or generate a random date.
Verifies a given date is valid.
*/

#include <iostream>
using namespace std;

void PrintOptions();
bool isCorrectDate(int year, int month, int day);
string calcDayOfWeek(int year, int month, int day);
void option1();
void option2();

int main()
{
    bool wantsToExit = false;

    while (!wantsToExit)
    {
        PrintOptions();
        int option;
        cin >> option;

        while (option != 1 && option != 2 && option != 3)
        {
            cout << "The wrong option was entered!!!" << endl
                 << endl;
            PrintOptions();
            cin >> option;
        }

        switch (option)
        {
        case 1:
            option1();
            break;
        case 2:
            option2();
            break;
        case 3:
            wantsToExit = true;
            cout << "Thanks for testing our implementation, bye!" << endl;
            break;
        }
    }
}

// prints all the options for the user
void PrintOptions()
{
    cout << "MENU" << endl;
    cout << "1. Enter a date" << endl;
    cout << "2. Generate a date" << endl;
    cout << "3. Exit" << endl;
    cout << "Please choose an option: " << endl;
}

// verifies if the given year, month and day is a valid date
bool isCorrectDate(int year, int month, int day)
{
    if (!(year > 0 && year < 9999))
    {
        return false;
    }
    if (!(month >= 1 && month <= 12))
    {
        return false;
    }

    // 31 day months
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
    {
        if (!(day >= 1 && day <= 31))
        {
            return false;
        }
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11)
    { // 30 day months
        if (!(day >= 1 && day <= 30))
        {
            return false;
        }
    }
    else
    {
        // only month left is Feb
        if (year % 4 == 0)
        {
            // leap years allow Feb 29th to be a valid date
            if (!(day >= 1 && day <= 29))
            {
                return false;
            }
        }
        else
        {
            if (!(day >= 1 && day <= 28))
            {
                return false;
            }
        }
    }
    return true;
}

string calcDayOfWeek(int year, int month, int day)
{

    // the given formula uses january and february as the
    // 13th and 14th month of the previous year respectively
    if (month == 1)
    {
        month = 13;
        year--;
    }
    else if (month == 2)
    {
        month = 14;
        year--;
    }

    // using the given formula
    int dayOfWeekInt = (day + (26 * (month + 1) / 10) + year % 100 + ((year % 100) / 4) + ((year / 100) / 4) + 5 * (year / 100)) % 7;

    switch (dayOfWeekInt)
    {
    case 0:
        return "Saturday";
    case 1:
        return "Sunday";
    case 2:
        return "Monday";
    case 3:
        return "Tuesday";
    case 4:
        return "Wednesday";
    case 5:
        return "Thursday";
    case 6:
        return "Friday";
    }
    return "Error";
}

// this method executes if the user chooses the first option
// this option will verify if the date given is correct. if it is
// correct, then the day of the week will be outputted
void option1()
{
    cout << "Enter the date yyyy mm dd" << endl;
    int year;
    int month;
    int day;
    cin >> year;
    cin >> month;
    cin >> day;

    while (!isCorrectDate(year, month, day))
    {
        cout << "!! Your date is not correct!!" << endl
             << endl;
        cout << "Enter the date yyyy mm dd" << endl;
        cin >> year;
        cin >> month;
        cin >> day;
    }

    cout << "The day of the week is " << calcDayOfWeek(year, month, day) << endl
         << endl;
}

// this function will be executed if the user choose option 2
// this option generates a random date given a seed
void option2()
{
    cout << "Enter an unsigned int seed number:" << endl;
    int seed;
    cin >> seed;

    srand(seed);

    int year;
    int month;
    int day;
    year = (rand() % (2021 - 2010 + 1)) + 2010;
    month = (rand() % (12 - 1 + 1)) + 1;

    // once the month and year are known, we can then determine the day, as not all months
    // have the same number of days
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
    {
        day = (rand() % (31 - 1 + 1)) + 1;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11)
    { // 30 day months
        day = (rand() % (30 - 1 + 1)) + 1;
    }
    else
    {
        // only month left is Feb
        if (year % 4 == 0)
        {
            // leap years allow Feb 29th to be a valid date
            day = (rand() % (29 - 1 + 1)) + 1;
        }
        else
        {
            day = (rand() % (28 - 1 + 1)) + 1;
        }
    }

    cout << "Computer generate " << year << " " << month << " " << day << endl;
    cout << "The day of the week is " << calcDayOfWeek(year, month, day) << endl
         << endl;
}

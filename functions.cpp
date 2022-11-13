#include "functions.h"

void PrintLines(string days) {
    int weeks = days.size() / 14;
    if (days.size() % 14 != 0) {
        ++weeks;
    }
    unsigned int offset;
    for (int i = 0; i < weeks; ++i) {
        cout << "|";
        offset = 14 * i;
        for (int j = 0; j < 7; ++j) {
            if (offset <= days.size()-2) {
                cout << " " << days.substr(offset, 2) << "|";
                offset += 2;
            }
            else {
                cout << "   |";
            }
        }
        cout << endl;
        cout << "|———————————————————————————|" << endl;
    }
    cout << endl;
}

void PrintCalendar(string day, string month, int year) {
    bool leap = false;
    if ((year % 4 == 0) && (year % 100 != 0)) {
        leap = true;
    }
    if (year % 400 == 0) {
        leap = true;
    }
    if (leap && month == "February") {
        day.append("29");
    }
    int space = 22 - month.size();
    string lspace = "";
    string mspace = "";
    for (int i = 0; i < (space/2); ++i) {
        lspace.push_back(' ');
    }
    if ((space % 2) != 0) {
        mspace = " ";
    }

    cout << endl;
    cout << "_____________________________" << endl;
    cout << "|                           |" << endl;
    cout << "|" << lspace << month << mspace << " " << year << lspace << "|" << endl;
    cout << "|———————————————————————————|" << endl;
    cout << "| S | M | T | W | T | F | S |" << endl;
    cout << "|———————————————————————————|" << endl;
    PrintLines(day);
}

std::string Caps(string month) {
    month.at(0) = toupper(month.at(0));
    for (unsigned int i = 1; i < month.size(); ++i) {
        month.at(i) = tolower(month.at(i));
    }
    return month;
}

int NumDays(string month) {
    int days;
    if (month == "February") {
        days = 28;
    }
    else if (month == "April" || month == "June" || month == "September" || month == "November") {
        days = 30;
    }
    else {
        days = 31;
    }
    return days;
}

bool ValidMonth(string month) {
    if (month == "January" || 
    month == "February"  || 
    month == "March" || 
    month == "April" || 
    month == "May" || 
    month == "June" || 
    month == "July" || 
    month == "August" || 
    month == "September" || 
    month == "October" || 
    month == "November" || 
    month == "December") {
        return true;
    }
    else {
        return false;
    }
}

int WeekdayNum(string month, int year) {
    int y;
    int yy;
    int m;
    int c;
    int w;
    bool leap = false;
    int total;
    if (month == "March") {
        m = 3;
    }
    else if (month == "April") {
        m = 6;
    }
    else if (month == "May") {
        m = 1;
    }
    else if (month == "June") {
        m = 4;
    }
    else if (month == "July") {
        m = 6;
    }
    else if (month == "August") {
        m = 2;
    }
    else if (month == "September") {
        m = 5;
    }
    else if (month == "October") {
        m = 0;
    }
    else if (month == "November") {
        m = 3;
    }
    else if (month == "December") {
        m = 5;
    }
    else if (month == "January") {
        m = 0;
    }
    else if (month == "February") {
        m = 3;
    }

    yy = year % 100;
    y = (yy + (yy/4)) % 7;

    switch(year / 100) {
        case 17:
        case 21:
        c = 4;
        break;

        case 18:
        case 22:
        c = 2;
        break;

        case 19:
        case 23:
        c = 0;
        break;

        case 20:
        c = 6;
        break;
    }
    if ((year % 4 == 0) && (year % 100 != 0)) {
        leap = true;
    }
    if (year % 400 == 0) {
        leap = true;
    }
    total = y + m + c + 1;
    
    if (leap && (month == "January" || month == "February")) {
        --total;
    }
    w = total % 7;
    if (w < 0) {
        w *= (-1);
    }

    return w;    
}

std::string DaysString(int num_days, int weekday) {
    string days = "";
    for (int i = 1; i <= num_days; ++i) {
        if (i < 10) {
            days.push_back(' ');
            days.append(std::to_string(i));
        }
        else {
            days.append(std::to_string(i));
        }
    }
    if (weekday != 0) {
        for (int i = 0; i < weekday; ++i) {
            days.insert(0, "  ");
        }
    }
    
    return days;
}

int GetValidYear() {
    int year;
    cout << "Enter a year: ";
    cin >> year;
    while (!cin.good() || year < 1753 || year > 2399) {
        if (year < 1753 || year > 2399) {
            cout << "Year is not in range." << endl;
            cout << "Enter a year between 1753 and 2399: ";
        }
        else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input, year must be an integer." << endl;
            cout << "Enter a year as an integer: ";
        }
        cin >> year;
    }
    return year;

}
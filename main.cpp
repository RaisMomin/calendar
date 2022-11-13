#include "functions.h"

int main() {

    string days;
    string month;
    int year;
    int weekday;
    int num_days;
    string repeat;

    cout << "Welcome to calendar generator!" << endl << endl;

    do {
        cout << "Enter a month: ";
        cin >> month;
        month = Caps(month);
        while (!ValidMonth(month)) {
            cout << "Invalid month entered. Enter a valid month (ex: January): ";
            cin >> month;
            month = Caps(month);
        }

        year = GetValidYear();
        num_days = NumDays(month);
        weekday = WeekdayNum(month, year);
        days = DaysString(num_days, weekday);
        PrintCalendar(days, month, year);

        cout << endl << "Print another month? (y/n): ";
        cin >> repeat;

    } while (repeat == "y" || repeat == "yes");

    cout << endl << "Thanks for using calendar generator!" << endl;

    return 0;
}
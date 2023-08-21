#include "Calender.h"

void Calender::Run(int year, int month, int day)
{
    // set user specified date

    // day is 0 in default
    c_date.setDay(day);
    c_date.setMonth(month);
    c_date.setYear(year);
}

void Calender::Draw()
{
    // calculate week day value
    int y, c, m;
    if (c_date.GetDay() == 1 || c_date.GetDay() == 2) {
        y = (c_date.GetYear() - 1) % 100;
        c = (c_date.GetYear() - 1) / 100;
        m = c_date.GetMonth() + 12;
    }
    else {
        y = (c_date.GetYear()) % 100;
        c = (c_date.GetYear()) / 100;
        m = c_date.GetMonth();
    }

    int week = ((y + y / 4 + c / 4 - 2 * c + 26 * (m + 1) / 10) % 7 + 7) % 7;

    // for number of days in month
    int mlen = 0;

    // 31 days for month
    if (c_date.GetMonth() == 1 || c_date.GetMonth() == 3 || c_date.GetMonth() == 5 || c_date.GetMonth() == 7 || c_date.GetMonth() == 8 || c_date.GetMonth() == 10 || c_date.GetMonth() == 12) {
        mlen = 31;
    }
    else {
        // for february
        if (m == 2) {
            int year = c_date.GetYear();

            // checking leap year
            bool leap = false;
            if ((year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0))) {
                leap = true;
            }

            // for leap year
            if (leap == true) {
                mlen = 29;
            }
            else {
                mlen = 28;
            }
        }
        else {
            mlen = 30;
        }
    }


    // print month name
    cout << " ";
    switch (c_date.GetMonth()) {
    case 1: {
        cout << "January";
        break;
    }
    case 2: {
        cout << "February";
        break;
    }
    case 3: {
        cout << "March";
        break;
    }
    case 4: {
        cout << "April";
        break;
    }
    case 5: {
        cout << "May";
        break;
    }
    case 6: {
        cout << "June";
        break;
    }
    case 7: {
        cout << "July";
        break;
    }
    case 8: {
        cout << "August";
        break;
    }
    case 9: {
        cout << "September";
        break;
    }
    case 10: {
        cout << "October";
        break;
    }
    case 11: {
        cout << "November";
        break;
    }
    case 12: {
        cout << "December";
        break;
    }
    }

    // print year
    cout << " " << c_date.GetYear() << endl;
    cout << "*********************";

    // header for day name
    cout << "\n SU";
    cout << " ";
    cout << "MO";
    cout << " ";
    cout << "TU";
    cout << " ";
    cout << "WE";
    cout << " ";
    cout << "TH";
    cout << " ";
    cout << "FR";
    cout << " ";
    cout << "SA";
    cout << "\n";

    // for initial spacees for week day start
    for (int i = 0; i < week; i++) {
        cout << " ";

        // for two character
        cout << " ";
        cout << " ";
    }

    for (int i = week; i < mlen + week; i++) {

        // for new line
        // in a week 7 days
        if (i != 0 && i % 7 == 0) {
            cout << endl;
        }
        cout << " ";

        // fill 2 character space using decimal day
        cout << setfill('0') << setw(2) << (i - week + 1);
    }

    cout << endl;
}

void Calender::NextMonth()
{
    // next month
    int m = c_date.GetMonth() == 12 ? 1 : (c_date.GetMonth() + 1);

    // if current month is 12 , increase year
    if (c_date.GetMonth() == 12) {
        c_date.setYear(c_date.GetYear() + 1);
    }

    // set next month
    c_date.setMonth(m);


}

void Calender::PreviousMonth()
{
    // previous month
    int m = c_date.GetMonth() == 1 ? 12 : (c_date.GetMonth() - 1);

    // current month is 1 , decrease year
    if (c_date.GetMonth() == 1) {
        c_date.setYear(c_date.GetYear() - 1);
    }

    // set previous month
    c_date.setMonth(m);
}

void Calender::CreateEvent(Date date, string s)
{
    // load event
    Event event(date, s);
    events.push_back(event);
}

bool Calender::removeEvent(int id)
{
    // if given id less tha equal to the vector size
    if (events.size() >= id && id > 0) {

        // delete evenet
        events.erase(events.begin() + id - 1, events.begin() + id);
        return true;
    }
    return false;
}

vector<Event> Calender::getallEvents()
{
    return events;
}

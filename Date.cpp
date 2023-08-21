
//#pragma once
#include "Event.h"
Date::Date()
{
    day = 0;
    month = 0;
    year = 0;

}

Date::Date(int a, int b, int c)
{
    day = a;
    month = b;
    year = c;
}

void Date::setDay(int a)
{
    day = a;
}

void Date::setMonth(int a)
{
    month = a;
}

void Date::setYear(int a)
{
    year = a;
}

int Date::GetDay()
{
    return day;
}

int Date::GetMonth()
{
    return month;
}

int Date::GetYear()
{
    return year;
}

//#pragma once
class Date {
private:
    int day;
    int month;
    int year;
public:
    Date();

    Date(int a, int b, int c);

    void setDay(int a);
    void setMonth(int a);
    void setYear(int a);

    int GetDay();
    int GetMonth();
    int GetYear();
};

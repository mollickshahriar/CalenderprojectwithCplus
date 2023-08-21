//#pragma once

#include"Event.h"
#include<string>
#include<iostream>
#include<vector>
#include<iomanip>

using namespace std;

class Calender {
private:
    Date c_date;
    vector<Event> events;
public:
    void Run(int year, int month, int day = 0);
    void Draw();
    void NextMonth();
    void PreviousMonth();
    void CreateEvent(Date date, string s);
    bool removeEvent(int id);
    vector<Event> getallEvents();
};

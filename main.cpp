#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<ctime>
#include<fstream>
#include<sstream>
#include"Calender.h"

using namespace std;

int main() {
	system("Color 1B");

    // get current date
    int year, month, day;
    time_t t = time(NULL);
    struct tm* now = localtime(&t);
    year = now->tm_year + 1900;
    month = now->tm_mon + 1;
    day = now->tm_mday;

    // set current date
    Calender calender;
    calender.Run(year, month, day);
    calender.Draw();

    while (true) {

        // for user choice
       cout<<"*******************************************************************************************************************************"<<endl; 
       cout<<"  Press 'N': Show the calendar for the next month"<<endl;
       cout<<"  Press 'P': Show the calendar for the previous month"<<endl;
       cout<<"  Press 'C': Input year and month, the program will show the calendar as you inputted"<<endl;
       cout<<"  Press 'A': Input year/month/day, then input a description, it will add an event to the calendar"<<endl;
       cout<<"  Press 'L': Show all events you have created, each one with an ID"<<endl;
       cout<<"  Press 'D': Input event ID, delete the event with this ID"<<endl;
       cout<<"  Press 'S': Input a file name, save the events you have created in this calendar program to a file on the disk"<<endl;
       cout<<"  Press 'R': Input a file name, load the events you have saved"<<endl;
       cout<<"  Press 'Q': Exit the program"<<endl;
       cout<<"*******************************************************************************************************************************"<<endl; 
	   cout<<"NOW YOUR CHOICE WHAT YOU WANT TO PRESS N,P,C,A,L,D,S,R,Q:"; 
    char ch;
    cin >> ch;

        // next month
        if (ch == 'N') {
            calender.NextMonth();
            calender.Draw();
        }

        // previous month
        if (ch == 'P') {
            calender.PreviousMonth();
            calender.Draw();
        }

        // any use define date
        if (ch == 'C') {
            cout << "Enter year : ";
            int year;
            cin >> year;
            cout << "Enter month : ";
            int month;
            cin >> month;

            // set current date
            calender.Run(year, month);

            // and display
            calender.Draw();
        }

        // add event
        if (ch == 'A') {
            cout << "Enter year : ";
            int year;
            cin >> year;
            cout << "Enter month : ";
            int month;
            cin >> month;
            cout << "Enter day : ";
            int day;
            cin >> day;
            cout << "Enter Description : ";
            string des;
            cin.ignore();
            getline(cin, des);
            Date date(day, month, year);

            // load event in vector
            calender.CreateEvent(date, des);
        }

        // display 4events
        if (ch == 'L') {
            // get all events
            vector<Event> eventlst = calender.getallEvents();

            cout << endl;

            for (int i = 0; i < eventlst.size(); i++) {

                // print each event
                cout << "Event " << (i + 1);
                Event event = eventlst[i];
                cout << "\tDate : " << event.getDate().GetDay() << "-" << event.getDate().GetMonth() << "-" << event.getDate().GetYear();
                cout << "\nDescription : " << event.getDescription() << "\n\n";
            }

        }

        // delete event
        if (ch == 'D') {
            cout << "Enter event ID : ";
            int id;
            cin >> id;

            // if id found
            if (calender.removeEvent(id)) {
                cout << "\nEvent removed \n\n";
            }
            // id not found
            else {
                cout << "\nEvent ID not found \n\n";
            }
        }

        // save event in file

        // day month year [line 1]
        // description [line 2]


        if (ch == 'S') {
            cout << "Enter File Name : ";
            string file;
            cin >> file;

            ofstream out;

            out.open(file.c_str());

            if (out.fail()) {
                cout << "File error.";
            }
            else {

                // get all events
                vector<Event> eventlst = calender.getallEvents();

                // write all event in file
                for (int i = 0; i < eventlst.size(); i++) {
                    Event event = eventlst[i];
                    out << event.getDate().GetDay() << " " << event.getDate().GetMonth() << " " << event.getDate().GetYear();
                    out << endl;
                    out << event.getDescription();
                    // ney line
                    out << "\n";
                }

                out.close();

                cout << "\nData save in file " << file << endl << endl;
            }
        }


        // read from file
        if (ch == 'R') {
            cout << "Enter File Name : ";
            string file;
            cin >> file;


            ifstream in;

            in.open(file.c_str());

            if (in.fail()) {
                cout << "\nFile not found.\n\n";
            }
            else {

                int a, b, c;
                string l;

                // read file until end of the file
                while (!in.eof()) {

                    // line for date
                    getline(in, l);

                    // store in string
                    stringstream ss;
                    ss << l;

                    // get date
                    ss >> a;// day
                    ss >> b;// month
                    ss >> c;// year

                    // get description from next line
                    getline(in, l);
                    Date date(a, b, c);

                    // load in vector
                    calender.CreateEvent(date, l);
                }

                // get last event id
                // which is error event
                int id = calender.getallEvents().size();

                // delete error event
                calender.removeEvent(id);

                in.close();

                cout << "\nData load from file " << file << endl << endl;
            }
        }
        if (ch == 'Q') {
            break;
        }

    }


    system("pause");
    return 0;
}

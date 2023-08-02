// HEADER FILES
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <unistd.h>
#include <cstdlib>

#include "flight.h"
#include "flight.cpp"

#include "passenger.h"
#include "passenger.cpp"

#include "ticket.h"
#include "ticket.cpp"

#include "user.h"
#include "user.cpp"

#include "menu.h"
#include "menu.cpp"

using namespace std;

// THE MAIN FUNCTION
int main()
{
    // system("Color 1");
    vector<Flight *> fly;

    fly.push_back(initial_flight("1001", "AirIndia", "India", "Dubai", "20/11/2022", "21/11/2022", "10:00 PM", "03:00 AM", 12000, 2, 7));
    fly.push_back(initial_flight("1002", "AirIndia", "India", "Japan", "20/11/2022", "21/11/2022", "10:00 PM", "03:00 AM", 8000, 2, 4));
    fly.push_back(initial_flight("1003", "AirIndia", "India", "Dubai", "22/11/2022", "23/11/2022", "10:00 PM", "03:00 AM", 12000, 2, 5));
    fly.push_back(initial_flight("1004", "AirIndia", "India", "Dubai", "21/11/2022", "22/11/2022", "10:00 PM", "03:00 AM", 12000, 2, 8));
    fly.push_back(initial_flight("1005", "AirIndia", "India", "Dubai", "20/11/2022", "21/11/2022", "12:00 PM", "05:00 AM", 12000, 2, 5));

    vector<User *> users;
    users.push_back(initial_user("1023", "Devansh_Sengar", "Male", "India", "8318522487", "devansh123@gmail.com", 20));
    users.push_back(initial_user("1049", "Pavithra", "Female", "India", "9876543210", "pavithra@gmail.com", 18));
    users.push_back(initial_user("1056", "Raavi_Jwalana", "Female", "India", "1234567890", "jwalana@gmail.com", 19));

    int choice;
    do
    {
        system("CLS");
        cout << endl
             << endl
             << "#####################################################################" << endl
             << "-- -- -- -- -- -- WELCOME TO AIRLINE BOOKING SYSTEM -- -- -- -- -- --" << endl
             << "#####################################################################" << endl
             << endl
             << "\tYou have follwing choices" << endl
             << endl
             << endl
             << "\t1. ADMIN MODE" << endl
             << endl
             << "\t2. USER MODE" << endl
             << endl
             << "\t3. Exit" << endl
             << endl
             << "\tEnter choice : ";
        cin >> choice;
        cout << endl;
        switch (choice)
        {
        case 1:
        {
            cout << endl
                 << " Entering ADMIN MODE...";
            sleep(1);
            admin_mode(fly);
            break;
        }
        case 2:
        {
            cout << endl
                 << " Entering USER MODE...";
            sleep(1);
            user_mode(fly, users);
            break;
        }
        case 3:
        {
            cout << " Exiting......" << endl;
            sleep(1);
            system("CLS");
            break;
        }
        default:
        {
            cout << " Enter any valid choice..." << endl
                 << endl;
            sleep(1);
            break;
        }
        }
    } while (choice != 3);

    return 0;
}

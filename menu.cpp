// HEADER FILES
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <unistd.h>
#include <cstdlib>

using namespace std;

#include "menu.h"

void user_menu(vector<Flight *> &fly, User *u)
{
    system("CLS");
    int choice;
    cout << endl
         << endl
         << "###################################################################" << endl
         << " -- -- -- -- -- -- " << u->get_name() << "'s Account -- -- -- -- -- -- " << endl
         << "###################################################################";
label5:
    cout << endl
         << endl
         << "\tYou have follwing choices :" << endl
         << endl
         << "\t\t1. Book Ticket" << endl
         << endl
         << "\t\t2. Display booked Tickets" << endl
         << endl
         << "\t\t3. Cancel booked Ticket" << endl
         << endl
         << "\t\t4. Back to previous menu" << endl
         << endl
         << "\tEnter choice : ";
    cin >> choice;
    cout << endl
         << endl;
    switch (choice)
    {
    case 1:
    {
        string s1, s2, s3;
        cout << "\tEnter the Boarding Location : ";
        cin >> s1;
        cout << "\tEnter the Destination : ";
        cin >> s2;
        cout << "\tEnter the date of arrival : ";
        cin >> s3;
        int flag = 0;
        cout << endl
             << endl;
        for (auto i : fly)
        {
            if (i->get_from() == s1 && i->get_destination() == s2 && i->get_startingdate() == s3)
            {
                flag = 1;
                i->display_flight();
                cout << endl
                     << endl;
            }
        }
        if (flag == 0)
            cout << " No Flights Available...";
        else
        {
            string id;
            cout << "\tEnter FlightID to book the Flight (or Enter -1 to exit): ";
            cin >> id;
            if (id == "-1")
                goto label5;
            else
            {
                Ticket *t = new Ticket;
                t->add_passenger();
                t->set_flightid(id);
                t->set_ticketid(rand());
                u->add_ticket(t);
                cout << endl
                     << " Your ticket has been booked successfully...\n Your TicketID is : " << t->get_ticketid()
                     << "\n Please remember this ID for furture use." << endl
                     << endl;
            }
        }
        sleep(1);
        goto label5;
    }
    case 2:
    {
        if ((*u->get_tickets()).size() == 0)
        {
            cout << " You don't have any booked tickets..." << endl;
        }
        else
        {
            cout << " Your booked tickets are : " << endl
                 << endl;
            for (auto i : *(u->get_tickets()))
            {
                cout << "TicketID : " << i->get_ticketid() << endl;
                i->show_passenger();
                for (auto j : fly)
                {
                    if (i->get_flightid() == j->get_flightid())
                    {
                        j->display_flight();
                    }
                }
                cout << endl;
            }
        }
        sleep(1);
        goto label5;
    }
    case 3:
    {
        int tid;
        cout << " Enter the TicketID : ";
        cin >> tid;
        int flag = 0;
        vector<Ticket *> *v = u->get_tickets();
        for (auto it = v->begin(); it != v->end(); it++)
        {
            if ((*it)->get_ticketid() == tid)
            {
                flag = 1;
                v->erase(it);
                break;
            }
        }
        if (flag == 0)
            cout << " Enter the valid TicketID... ";
        else
            cout << " Your ticket has been cancelled successfully..." << endl;

        sleep(1);
        goto label5;
    }
    case 4:
    {
        cout << " Exiting to previous menu..." << endl
             << endl;
        sleep(1);
        break;
    }
    default:
    {
        cout << " Enter any valid choice..." << endl
             << endl;
        sleep(1);
        goto label5;
    }
    }
}

// ADMIN MODE
void admin_mode(vector<Flight *> &fly)
{
    system("CLS");
    int ch;
    cout << endl
         << endl
         << "###################################################################" << endl
         << " -- -- -- -- -- -- -- -- -- ADMIN MODE -- -- -- -- -- -- -- -- -- " << endl
         << "###################################################################";
label1:
    cout << "\n\n\t\t1. Add new flight " << endl
         << "\n\t\t2. Show all flights" << endl
         << "\n\t\t3. Delete a flight" << endl
         << "\n\t\t4. Back to previous menu" << endl
         << "\n\n\tEnter your choice : ";
    cin >> ch;
    cout << endl;
    switch (ch)
    {
    case 1:
    {
        Flight *f = new Flight;
        string flightid;

        cout << "\tEnter Flight's ID : ";
        cin >> flightid;
        for (auto i : fly)
        {
            if (i->get_flightid() == flightid)
            {
                cout << endl
                     << " This FlightID has already been taken..." << endl;
                goto label1;
            }
        }
        f->set_flightid(flightid);
        f->add_flight();
        fly.push_back(f);
        cout << endl
             << " New Flight details added successfully..." << endl;
        sleep(1);
        goto label1;
    }
    case 2:
    {
        for (auto i : fly)
        {
            i->display_flight();
            cout << endl;
        }
        sleep(1);
        goto label1;
    }
    case 3:
    {
        string fid;
        cout << "\tEnter the FlightID : ";
        cin >> fid;
        for (auto it = fly.begin(); it != fly.end(); it++)
        {
            if ((*it)->get_flightid() == fid)
            {
                fly.erase(it);
                break;
            }
        }
        cout << endl
             << " Flight has been deleted successfully..." << endl;
        sleep(1);
        goto label1;
    }
    case 4:
    {
        cout << " Exiting to previous menu....." << endl
             << endl;
        sleep(1);
        break;
    }
    default:
        cout << " Enter any valid choice..." << endl
             << endl;
        sleep(1);
        goto label1;
    }
}

// USER MODE
void user_mode(vector<Flight *> &fly, vector<User *> &users)
{
label4:
    system("CLS");
    int ch;
    cout << endl
         << endl
         << "###################################################################" << endl
         << "- -- -- -- -- -- -- -- -- -- USER MODE -- -- -- -- -- -- -- -- -- -" << endl
         << "###################################################################";
label2:
    cout << "\n\n\t\t1. Create new user account" << endl
         << "\n\t\t2. Login into existing account" << endl
         << "\n\t\t3. Show users " << endl
         << "\n\t\t4. Delete user " << endl
         << "\n\t\t5. Back to previous menu " << endl
         << "\n\n\tEnter your choice : ";
    cin >> ch;
    cout << endl;
    switch (ch)
    {
    case 1:
    {
        User *u = new User;
        string userid;

        cout << "\tEnter UserID : ";
        cin >> userid;
        for (auto i : users)
        {
            if (i->get_userid() == userid)
            {
                cout << endl
                     << " This UserID has already been taken..." << endl;
                goto label2;
            }
        }
        u->set_userid(userid);
        u->add_user();
        users.push_back(u);
        cout << endl
             << " New user registerd successfully..." << endl;
        sleep(1.5);
        user_menu(fly, u);
        sleep(1);
        goto label4;
    }
    case 2:
    {
        string id;
        cout << "\tEnter the UserID : ";
        cin >> id;
        int flag = 0;
        for (auto i : users)
        {
            if (i->get_userid() == id)
            {
                flag = 1;
                cout << endl
                     << " Logging into " << i->get_name() << "'s account... " << endl;
                sleep(1);
                user_menu(fly, i);
                goto label4;
            }
        }
        if (flag == 0)
        {
            cout << " User Not Found.... Sign in as a new user...";
            sleep(1);
        }
        goto label2;
    }
    case 3:
    {
        if (users.size() == 0)
        {
            cout << " You do not have any registered users..." << endl;
            sleep(1);
        }
        else
        {
            cout << " Registered users are : " << endl
                 << endl;
            for (auto i : users)
            {
                i->show_user();
                cout << endl;
            }
        }
        sleep(1);
        goto label2;
    }
    case 4:
    {
        string uid;
        cout << "\tEnter the UserID : ";
        cin >> uid;
        for (auto it = users.begin(); it != users.end(); it++)
        {
            if ((*it)->get_userid() == uid)
            {
                users.erase(it);
                // delete *it;
                break;
            }
        }
        cout << " User has been deleted successfully..." << endl;
        sleep(1);
        goto label2;
    }
    case 5:
    {
        cout << "Exiting to previous menu..." << endl
             << endl;
        sleep(1);
        break;
    }
    default:
        cout << " Enter any valid choice..." << endl
             << endl;
        sleep(1);
        goto label2;
    }
}

Flight *initial_flight(string a, string b, string c, string d, string e, string g, string h, string i, double x, int m, int n)
{
    Flight *f = new Flight;
    f->flightID = a;
    f->airline = b;
    f->from = c;
    f->destination = d;
    f->startingdate = e;
    f->reachingdate = g;
    f->startingtime = h;
    f->reachingtime = i;
    f->price = x;
    f->totalbaggageallowed = m;
    f->seats_remaining = n;

    return f;
}

User *initial_user(string a, string b, string c, string d, string e, string g, int n)
{
    User *u = new User;
    u->user_id = a;
    u->name = b;
    u->gender = c;
    u->address = d;
    u->phonenumber = e;
    u->email = g;
    u->age = n;

    return u;
}
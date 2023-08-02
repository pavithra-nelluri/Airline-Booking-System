// HEADER FILES
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <unistd.h>
#include <cstdlib>

#include "flight.h"
using namespace std;

Flight::Flight()
{
    flightID = "";
    airline = "";
    from = "";
    destination = "";
    startingdate = "";
    reachingdate = "";
    startingtime = "";
    reachingtime = "";
    price = 0.0;
    totalbaggageallowed = 0;
    seats_remaining = 0;
}

void Flight::set_flightid(string id)
{
    flightID = id;
}

string Flight::get_flightid()
{
    return flightID;
}

string Flight::get_from()
{
    return from;
}

string Flight::get_destination()
{
    return destination;
}

string Flight::get_startingdate()
{
    return startingdate;
}

void Flight::add_flight()
{
    cout << "\tEnter Airline : ";
    cin >> airline;
    cout << "\tEnter boarding location : ";
    cin >> from;
    cout << "\tEnter destination : ";
    cin >> destination;
    cout << "\tEnter Starting Date (dd/mm/yyyy) : ";
    cin >> startingdate;
    cout << "\tEnter Arrival Date (dd/mm/yyyy) : ";
    cin >> reachingdate;
    cout << "\tEnter Boarding time : ";
    cin >> startingtime;
    cout << "\tEnter Reaching time: ";
    cin >> reachingtime;
    cout << "\tEnter Ticket price : ";
    cin >> price;
    cout << "\tEnter Total number of baggages allowed : ";
    cin >> totalbaggageallowed;
    cout << "\tEnter Total number of seats remaining : ";
    cin >> seats_remaining;
}

void Flight::display_flight()
{
    cout << "\tFlight's ID : " << flightID << endl;
    cout << "\tAirline : " << airline << endl;
    cout << "\tBoarding location : " << from << endl;
    cout << "\tDestination : " << destination << endl;
    cout << "\tStarting Date : " << startingdate << endl;
    cout << "\tArrival Date : " << reachingdate << endl;
    cout << "\tBoarding time : " << startingtime << endl;
    cout << "\tReaching time : " << reachingtime << endl;
    cout << "\tTicket price : " << price << endl;
    cout << "\tTotal number of baggages allowed : " << totalbaggageallowed << endl;
    cout << "\tTotal number of seats remaining : " << seats_remaining << endl;
}
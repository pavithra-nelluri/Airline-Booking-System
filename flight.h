#ifndef FLIGHT_HPP
#define FLIGHT_HPP

#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

class Flight
{
private:
    string flightID;
    string airline;
    string from;
    string destination;
    string startingdate;
    string reachingdate;
    string startingtime;
    string reachingtime;
    double price;
    int totalbaggageallowed;
    int seats_remaining;

public:
    Flight();

    void set_flightid(string id);

    string get_flightid();

    string get_from();

    string get_destination();

    string get_startingdate();

    void add_flight();

    void display_flight();

    friend Flight *initial_flight(string, string, string, string, string, string, string, string, double, int, int);
};

#endif
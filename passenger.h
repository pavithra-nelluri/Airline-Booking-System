#ifndef PASSENGER_HPP
#define PASSENGER_HPP

#include <bits/stdc++.h>
using namespace std;

class Passenger
{
private:
    string Passenger_name;
    int Passenger_age;
    string Passenger_gender;
    string Passenger_phno;

public:
    Passenger();

    void add_passenger();

    void show_passenger();
};

#endif
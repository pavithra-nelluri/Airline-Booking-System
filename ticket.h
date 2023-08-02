
#ifndef TICKET_HPP
#define TICKET_HPP

#include <bits/stdc++.h>
using namespace std;

class Ticket : public Flight, public Passenger
{
    int ticketID;

public:
    Ticket();

    void set_ticketid(int n);

    int get_ticketid();
};

#endif
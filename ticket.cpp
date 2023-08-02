#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <unistd.h>
#include <cstdlib>

#include "ticket.h"
using namespace std;

Ticket::Ticket()
{
    ticketID = 0;
}

void Ticket::set_ticketid(int n)
{
    ticketID = n;
}

int Ticket::get_ticketid()
{
    return ticketID;
}
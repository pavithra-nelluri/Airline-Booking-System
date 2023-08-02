#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <unistd.h>
#include <cstdlib>

#include "passenger.h"
using namespace std;

Passenger::Passenger()
{
    Passenger_name = "";
    Passenger_age = 0;
    Passenger_gender = "";
    Passenger_phno = "";
}
void Passenger::add_passenger()
{
    cin.ignore();
    cout << "\tEnter Passenger's name : ";
    getline(cin, Passenger_name);
    cout << "\tEnter Passenger's age : ";
    cin >> Passenger_age;
    cout << "\tEnter Passenger's gender : ";
    cin >> Passenger_gender;
    cout << "\tEnter Passenger's phone number : ";
    cin >> Passenger_phno;
}
void Passenger::show_passenger()
{
    cout << "\tPassenger's name : " << Passenger_name << endl;
    cout << "\tPassenger's age : " << Passenger_age << endl;
    cout << "\tPassenger's gender : " << Passenger_gender << endl;
    cout << "\tPassenger's phone number : " << Passenger_phno << endl;
}
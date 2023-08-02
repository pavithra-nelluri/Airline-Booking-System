#ifndef USER_HPP
#define USER_HPP

#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

class User
{
private:
    string user_id;
    string name;
    string gender;
    string address;
    string phonenumber;
    string email;
    int age;
    vector<Ticket *> tickets;

public:
    User();

    void set_userid(string u);

    string get_userid();

    string get_name();

    void add_user();

    void show_user();

    void add_ticket(Ticket *T);

    vector<Ticket *> *get_tickets();

    friend User *initial_user(string, string, string, string, string, string, int);
};

#endif
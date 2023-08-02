// HEADER FILES
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <unistd.h>
#include <cstdlib>

using namespace std;

Flight *initial_flight(string a, string b, string c, string d, string e, string g, string h, string i, double x, int m, int n);
User *initial_user(string a, string b, string c, string d, string e, string g, int n);
void user_menu(vector<Flight *> &fly, User *u);
void admin_mode(vector<Flight *> &fly);
void user_mode(vector<Flight *> &fly, vector<User *> &users);
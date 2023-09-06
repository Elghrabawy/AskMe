#pragma once
#include <iostream>
#include <string>
#include <map>
#include "Global_Functions_Variables.h"


using namespace std;

class User
{
private:
	int id;
	string username;
	string password;
	string name;
	string email;


public:
	User();

	User(const User& a);

	User(string line);

	User(int user_id);

	void print_user_info();

	int get_id();

	string get_username();

	string get_password();

	string get_email();

	string get_name();

	void set_id(int u_id);

	void set_username(string un);

	void set_password(string pas);

	void set_email(string e);

	void set_name(string n);
};
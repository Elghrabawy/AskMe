#include "User.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;
User::User()
{
	username = "Unknown";
	id = -1;
}
User::User(const User& a)
{
	id = a.id;
	username = a.username;
	password = a.password;
	name = a.name;
	email = a.email;
}
User::User(string line)
{
	stringstream user_info(line);

	string strid;
	getline(user_info, strid, ',');
	id = stoi(strid);
	getline(user_info, username, ',');
	getline(user_info, password, ',');
	getline(user_info, name, ',');
	getline(user_info, email, ',');
}

User::User(int user_id)
{

	vector <string> users_lines = ReadFileLines(users_path());
	for (auto line : users_lines) {
		vector <string> user_info = SplitString(line, ",");
		if (stoi(user_info[0]) == user_id) {
			User u(line);

			id = u.id;
			username = u.username;
			password = u.password;
			name = u.name;
			email = u.email;

			break;
		}
	}
}

void User::print_user_info()
{

	cout << "user id  : " << id << endl;
	cout << "username : " << username << endl;
	cout << "password : " << password << endl;
	cout << "email    : " << email << endl;
}

int User::get_id()
{
	return id;
}

string User::get_username()
{
	return username;
}

string User::get_password()
{
	return password;
}

string User::get_email()
{
	return email;
}

string User::get_name()
{
	return name;
}

void User::set_id(int u_id)
{
	id = u_id;
}

void User::set_username(string un)
{
	username = un;
}

void User::set_password(string pas)
{
	password = pas;
}

void User::set_email(string e)
{
	email = e;
}

void User::set_name(string n)
{
	name = n;
}

#include "UsersManager.h"

int UsersManager::get_current_user()
{
    return current_user;
}

map<string, User> UsersManager::get_users()
{
    return username_userinfo;
}

void UsersManager::load_db()
{
    username_userinfo.clear();

    vector <string> lines;

    lines = ReadFileLines(users_path());

    for (auto line : lines) {
        User user(line);
        username_userinfo[user.get_username()] = user;
        last_id = user.get_id();
    }
}

void UsersManager::sign_up()
{
    string username, password, name, email;
    while (true) {
        cout << "\n\tEnter your username : ";
        cin >> username;
        if (username_userinfo[username].get_username() == "Unknown") break;
        else {
            cout << "\n>> This username is already exists..\n\n";
            continue;
        }
    }
    cout << "\tEnter your password : ";
    cin >> password;

    cout << "\tEnter your name     : ";
    cin.ignore();
    getline(cin, name);

    cout << "\tEnter your email    : ";
    cin >> email;

    string line = to_string(last_id + 1) + "," + username + "," + password + "," + name + "," + email;
    WriteFileLine(line, users_path());

    cout << "\n>> Sign up complete successfully\n\n\n";

    load_db();
}

void UsersManager::login()
{
    string username, password;
    while (true) {
        cout << "\n\tEnter your username : ";
        cin >> username;
        if (username_userinfo[username].get_username() == "Unknown") {
            username_userinfo.erase(username);
            cout << "\n>> Sorry This username is not exists.\n";
            continue;
        }

        cout << "\tEnter your password : ";
        cin >> password;

        if (username_userinfo[username].get_password() != password) {
            cout << "\n>> Password not correct \n\n";
            continue;
        }

        break;
    }

    current_user = username_userinfo[username].get_id();
    cout << "\n ======= Welcome " << username_userinfo[username].get_name() << " ======= \n" << endl;
    load_db();
}

bool UsersManager::userIsExist(string un)
{
    if (username_userinfo[un].get_id() == -1) {
        username_userinfo.erase(un);
        return 0;
    }
    else {
        return 1;
    }
}

void UsersManager::ListUsers()
{
    int cnt_users = 0;
    for (auto user : username_userinfo) {
        cnt_users++;
        cout << "ID : " << user.second.get_id() << "\t\tName : " << user.second.get_name() << endl;
    }
    if (!cnt_users) {
        cout << "Can't find any user\n";
    }
}
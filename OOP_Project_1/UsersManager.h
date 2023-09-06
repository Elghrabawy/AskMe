#pragma once
#include "Global_Functions_Variables.h"

class UsersManager
{
private:
    int last_id = 0;
    int current_user;
    map <string, User> username_userinfo;
public:
    int get_current_user();

    map<string, User> get_users();

    void load_db();


    void sign_up();


    void login();


    bool userIsExist(string un);

    void ListUsers();
};


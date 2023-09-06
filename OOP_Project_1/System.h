#pragma once
#include "Global_Functions_Variables.h"
#include "UsersManager.h"
#include "PostsManager.h"

class System
{
private:
    UsersManager user_manager;
    PostsManager post_manager;

    int current_user;

public:
    void LoadDataBase();

    void AccessSystem();

    void run();
};


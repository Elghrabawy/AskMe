#pragma once
#include "Global_Functions_Variables.h"

class PostsManager
{
private:
    map <int, Post> postid_post;
    int last_id;

public:
    map<int, Post> get_posts();

    void load_db();

    void update_db();

    int delete_post(int post_id, int user_id);

    void add_post(string content, int user_id);

    int add_comment(int post_id, int user_id, string comment);

    void show_user_posts(int user_id, bool with_post_id = false, bool with_username = false, bool with_comments = false);

    void show_feeds(int user_id);

    bool postIsExist(int post_id);
};


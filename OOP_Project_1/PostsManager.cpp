#include "PostsManager.h"

map<int, Post> PostsManager::get_posts()
{
    return postid_post;
}

void PostsManager::load_db()
{

    postid_post.clear();

    vector <string> posts_lines = ReadFileLines(posts_path());


    for (auto line : posts_lines) {
        Post p(line);
        postid_post[p.get_post_id()] = p;
        last_id = p.get_post_id();
    }
}

void PostsManager::update_db()
{
    vector <string> posts_lines;

    for (auto post : postid_post) {

        string str_post_id = to_string(post.second.get_post_id());
        string str_user_id = to_string(post.second.get_user_id());

        string line = str_post_id + "," + str_user_id + "," + post.second.get_post_contnet();

        vector <pair<int, string>> comments = post.second.get_post_comments();

        for (auto comment : comments) {
            line += "," + to_string(comment.first) + "-" + comment.second;
        }

        posts_lines.push_back(line);
    }
    WriteFileLines(posts_path(), posts_lines, false);
}

int PostsManager::delete_post(int post_id, int user_id)
{
    Post post = postid_post[post_id];

    if (!postIsExist(post_id))
        return 1;

    else if (post.get_user_id() != user_id)
        return -1;

    else {
        postid_post.erase(post_id);
        update_db();
    }
}

void PostsManager::add_post(string content, int user_id)
{

    int new_post_id = last_id + 1;

    Post p(new_post_id, user_id, content);

    postid_post[new_post_id] = p;

    update_db();
}

int PostsManager::add_comment(int post_id, int user_id, string comment)
{

    Post& post = postid_post[post_id];

    if (!postIsExist(post_id))
        return -1;

    else {
        post.add_new_comment(comment, user_id);
        update_db();
    }
}

void PostsManager::show_user_posts(int user_id, bool with_post_id, bool with_username, bool with_comments)
{
    int cnt_posts = 0;
    for (auto post : postid_post) {
        if (post.second.get_user_id() == user_id) {
            cnt_posts++;

            post.second.print_post(with_post_id, with_username, with_comments);
        }
    }
    if (!cnt_posts) {
        cout << "\tNo posts published from this user\n\n";
    }
}

void PostsManager::show_feeds(int user_id)
{
    vector <string> menu;
    menu.push_back("Next.");
    menu.push_back("Add Comment.");
    menu.push_back("Comments.");
    menu.push_back("Back.");

    int posts_cnt = 0;
    for (auto& post : postid_post) {
        cout << endl;
        post.second.print_post(true, true);


        int ch = ReadMenu_2({ "next", "comments", "add comment", "go out" });

        if (ch == 1) {
            continue;
        }

        else if (ch == 2) {
            post.second.print_comments();
            int ch2 = ReadMenu_2({ "next", "go out" });

            if (ch2 == 1) continue;
            else {
                return;
            }

        }

        else if (ch == 3) {
            string comment;
            cout << "Enter the comment: ";

            cin.ignore();
            getline(cin, comment);

            add_comment(post.first, user_id, comment);
            update_db();

            int ch2 = ReadMenu_2({ "next", "go out" });

            if (ch2 == 1) continue;
            else {
                return;
            }

        }

        else if (ch == 4) {
            return;
        }

        cout << endl;
    }
    cout << "No more posts..\n\n";

}

bool PostsManager::postIsExist(int post_id)
{

    // post not exist
    if (postid_post[post_id].get_post_id() == -1) {
        postid_post.erase(post_id);
        return 0;
    }
    // post exist
    else {
        return 1;
    }
}

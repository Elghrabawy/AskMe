#include "System.h"

void System::LoadDataBase()
{
    user_manager.load_db();
    post_manager.load_db();
}

void System::AccessSystem()
{
    LoadDataBase();

    vector <string> menu = { "Login", "Signup" };

    int ch = ReadMenu(menu);

    switch (ch)
    {
    case 1:
        user_manager.login();
        current_user = user_manager.get_current_user();
        break;
    case 2:
        user_manager.sign_up();
        AccessSystem();
        break;
    }
}

void System::run()
{
    AccessSystem();

    while (true) {
        vector <string> menu;

        menu.push_back("My Messages");
        menu.push_back("My Posts");
        menu.push_back("New Post");
        menu.push_back("Delete Post");
        menu.push_back("Add Comment");
        menu.push_back("List System Users");
        menu.push_back("Feeds");
        menu.push_back("My Informations");
        menu.push_back("Logout");

        int ch = ReadMenu(menu);
        cout << endl << endl;
        if (ch == 1) {
            cout << "Will be added soon\n\n";
        }


        // show my posts
        else if (ch == 2) {
            post_manager.show_user_posts(current_user, true, false, true);
        }

        // add new post
        else if (ch == 3) {
            cout << "Enter post content : \n";

            string con;

            cin.ignore();
            getline(cin, con);

            post_manager.add_post(con, current_user);
        }

        // delete post
        else if (ch == 4) {

            post_manager.show_user_posts(current_user, true, false, false);

            int post_id;
            cout << "\nEnter post id : ";
            cin >> post_id;


            // this post not exist
            if (post_manager.delete_post(post_id, current_user) == 1) {
                cout << "Sorry but this post not exist\n";
            }

            // this post not for current user
            else if (post_manager.delete_post(post_id, current_user) == -1) {
                cout << "Sorry but this post not for you\n";
            }

            else {
                cout << "\nDeleted Successfully\n";
            }

        }

        // new comment
        else if (ch == 5) {
            int post_id;
            string comment;

            cout << "Enter The Post ID : ";
            cin >> post_id;

            cout << "Enter the comment : ";
            cin.ignore();
            getline(cin, comment);

            if (post_manager.add_comment(post_id, current_user, comment) == -1) {
                cout << "Sorry but this post not exist\n";
            }
            else {
                cout << "\nThe comment added successfully.\n";
            }
        }

        // list of users
        else if (ch == 6) {
            user_manager.ListUsers();
        }

        // show feeds
        else if (ch == 7) {
            post_manager.show_feeds(current_user);
        }
        else if (ch == 8) {
            User u(current_user);
            u.print_user_info();
            cout << endl;

        }
        else if (ch == 9) {
            break;
        }
        if (ifContinue())
        {
            cout << "\n#=========================================#\n\n";
            continue;
        }
        else
            break;

    }
    run();
}

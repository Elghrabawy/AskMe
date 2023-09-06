#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "Global_Functions_Variables.h"
#include "User.h"

using namespace std;

class Post
{
private:
	int post_id;
	int user_id;
	string post_content;
	vector <pair<int, string>> post_comments;

public:
	Post();
	Post(int p_id, int u_id, string con);
	Post(int p_id, int u_id, string con, vector <pair<int, string>> com);
	Post(string line);
	int get_post_id();
	void set_post_id(int id);
	int get_user_id();
	void set_user_id(int id);
	string get_post_contnet();
	void set_post_content(string con);
	vector <pair<int, string>> get_post_comments();
	void add_new_comment(string comment, int user_id);
	void set_post_comments(vector<pair<int, string>> com);
	string to_line();
	void print_post(bool with_post_id = false, bool with_username = false, bool with_comments = false);
	void print_comments();

};


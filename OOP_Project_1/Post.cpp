#include "Post.h"

Post::Post()
{
	post_id = -1;
}

Post::Post(int p_id, int u_id, string con)
{
	post_id = p_id;
	user_id = u_id;
	post_content = con;
}

Post::Post(int p_id, int u_id, string con, vector<pair<int, string>> com)
{
	post_id = p_id;
	user_id = u_id;
	post_content = con;
	post_comments = com;
}

Post::Post(string line)
{
	stringstream post_info(line);
	string str_post_id, str_user_id, content;

	getline(post_info, str_post_id, ',');
	getline(post_info, str_user_id, ',');
	getline(post_info, content, ',');

	vector <pair<int, string>> comments;
	string comment;

	while (getline(post_info, comment, ',')) {
		string str_id, content;

		stringstream line_comments(comment);

		getline(line_comments, str_id, '-');
		getline(line_comments, content, '-');

		comments.push_back({ stoi(str_id), content });
	}

	post_id = stoi(str_post_id);
	user_id = stoi(str_user_id);
	post_content = content;
	post_comments = comments;
}

int Post::get_post_id()
{
	return post_id;
}

void Post::set_post_id(int id)
{
	post_id = id;
}

int Post::get_user_id()
{
	return user_id;
}

void Post::set_user_id(int id)
{
	user_id = id;
}

string Post::get_post_contnet()
{
	return post_content;
}

void Post::set_post_content(string con)
{
	post_content = con;
}

vector<pair<int, string>> Post::get_post_comments()
{
	return post_comments;
}

void Post::add_new_comment(string comment, int user_id)
{
	pair <int, string> new_comment = { user_id, comment };

	post_comments.push_back(new_comment);
}

void Post::set_post_comments(vector<pair<int, string>> com)
{
	post_comments = com;
}

string Post::to_line()
{
	string str_post_id = to_string(post_id);
	string str_user_id = to_string(user_id);

	string line = str_post_id + "," + str_user_id + "," + post_content;

	vector <pair<int, string>> comments = post_comments;

	for (auto comment : comments) {
		line += "," + to_string(comment.first) + "-" + comment.second;
	}

	return line;
}

void Post::print_post(bool with_post_id, bool with_username, bool with_comments)
{
	User u1(user_id);

	cout << "Post ";
	if (with_post_id) {
		cout << "(" << post_id << ")";
	}

	if (with_username) {
		cout << " from user (" << u1.get_username() << ")\t";
	}
	cout << " : " << post_content << endl;

	vector <string> comments;
	if (with_comments) {
		for (auto comment : post_comments) {
			User u2(comment.first);
			comments.push_back(u2.get_username() + " : " + comment.second);
		}

		if (comments.size()) {
			for (auto comment : comments) {
				cout << "\t" << comment << endl;
			}
		}
		else {
			cout << "\tNo comments found\n";
		}
		cout << endl << endl;
	}
}

void Post::print_comments()
{
	vector <string> comments;

	for (auto comment : post_comments) {
		User u2(comment.first);
		comments.push_back(u2.get_username() + " : " + comment.second);
	}

	if (comments.size()) {
		for (auto comment : comments) {
			cout << "" << comment << endl;
		}
	}
	else {
		cout << "No comments found\n";
	}
	cout << endl;

}

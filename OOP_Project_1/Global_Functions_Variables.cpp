#include "Global_Functions_Variables.h"




string users_path()
{
    return "users.csv";
}

string posts_path()
{
    return "posts.csv";
}

vector<string> ReadFileLines(string path)
{

    vector <string> lines;

    fstream file_handler(path.c_str());

    if (file_handler.fail()) {
        cout << "\n\n\nError, Can't find file\n\n\n";
        return lines;
    }
    string line;
    while (getline(file_handler, line)) {
        if (line.size() == 0)
            continue;

        lines.push_back(line);
    }

    file_handler.close();

    return lines;
}

void WriteFileLine(string s, string path)
{
    auto status = ios::in | ios::out | ios::app;

    fstream file_handler(path.c_str(), status);

    if (file_handler.fail()) {
        cout << "\n\n\nError, Can't find file\n\n\n";
        return;
    }

    file_handler << '\n' << s;

    file_handler.close();
}

void WriteFileLines(string path, vector<string> lines, bool append) {
    auto status = ios::in | ios::out | ios::app;

    if (!append)
        status = ios::in | ios::out | ios::trunc;

    fstream file_handler(path.c_str(), status);

    if (file_handler.fail()) {
        cout << "\n\n\nError, Can't find file\n\n\n";
        return;
    }
    for (auto line : lines)
        file_handler << line << "\n";

    file_handler.close();
}


vector<string> SplitString(string s, string separator)
{
    vector <string> strs;

    int pos = 0;
    string substr;
    while ((pos = (int)s.find(separator)) != -1) {
        substr = s.substr(0, pos);
        strs.push_back(substr);
        s.erase(0, pos + separator.length());
    }
    strs.push_back(s);
    return strs;
}

int ReadInt(int low, int high)
{
    cout << "\nEnter number in range " << low << " - " << high << " : ";
    int value;
    cin >> value;

    if (value >= low && value <= high) {
        return value;
    }
    else {
        cout << "\n>> Wrong Input\n\n";
        ReadInt(low, high);
    }
}

int ReadMenu(vector<string> menu)
{
    cout << "Menu: \n";

    for (int ch = 0; ch < menu.size(); ch++) {
        cout << "\t" << ch + 1 << " : " << menu[ch] << endl;
    }
    return ReadInt(1, menu.size());
}


int ReadInt_2(int low, int high)
{
    cout << ">> ";
    int value;
    cin >> value;

    if (value >= low && value <= high) {
        return value;
    }
    else {
        cout << "\n>> Wrong Input\n\n";
        ReadInt(low, high);
    }
}

int ReadMenu_2(vector<string> menu)
{
    for (int ch = 0; ch < menu.size(); ch++) {
        cout << ch + 1 << ": " << menu[ch] << "    ";
    }
    cout << endl;
    return ReadInt_2(1, menu.size());
}


void to_lower(string& s)
{
    for (auto& c : s) {
        c = tolower(c);
    }
}

bool ifContinue()
{
    cout << "\nDo you want continue? (y/n) : ";

    string ch;
    cin >> ch;

    cout << endl;

    to_lower(ch);

    if (ch == "y" || ch == "yes") {
        return 1;
    }
    else if (ch == "n" || ch == "no") {
        return 0;
    }
    else {
        cout << ">> Wrong Input\n\n";
        ifContinue();
    }
}

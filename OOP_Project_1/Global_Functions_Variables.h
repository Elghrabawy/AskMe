#pragma once
#ifndef FUNCTIONS_H_INCLUDED
#define FUNFUNCTIONS_H_INCLUDED


#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <map>

#include "Post.h"
#include "User.h"

using namespace std;



string users_path();
string posts_path();

vector <string> ReadFileLines(string path);

void WriteFileLine(string s, string path);

void WriteFileLines(string path, vector<string> lines, bool app = true);

vector <string> SplitString(string s, string separator = ",");

int ReadInt(int low, int high);

int ReadMenu(vector <string> menu);

int ReadInt_2(int low, int high);

int ReadMenu_2(vector <string> menu);

void to_lower(string& s);

bool ifContinue();

#endif // !FUNCTIONS_H_INCLUDED
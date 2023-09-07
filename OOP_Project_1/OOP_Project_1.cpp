// OOP_Project_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "System.h"
#include "Global_Functions_Variables.h"

using namespace std;

int main()
{
    System s;

    s.LoadDataBase();

    s.run();
}

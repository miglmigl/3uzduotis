#ifndef MYLIB_H_INCLUDED
#define MYLIB_H_INCLUDED

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <stdio.h>
#include <sstream>

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::vector;
using std ::setw;
using std::fixed;
using std::left;
using std::right;
using std::setprecision;

struct studentas{
    string var, pav;
    vector <int> paz;
    int egz;
    float rez;
    string line;
};

vector<studentas> ivesk();

#endif //MYLIB_H_INCLUDED


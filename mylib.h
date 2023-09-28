#ifndef MYLIB_H_INCLUDED
#define MYLIB_H_INCLUDED

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <stdio.h>
#include <sstream>
#include <algorithm>
#include <random>
#include <cstdlib>
#include <ctime>

//using std::cout;
//using std::cin;
//using std::string;
//using std::endl;
//using std::vector;
//using std::setw;
//using std::fixed;
//using std::left;
//using std::right;
//using std::setprecision;
//using std:: rand;
using namespace std;

struct studentas{
    string var, pav;
    vector <int> paz;
    int egz;
    float vid;
    float med;
    string line;
};




vector<studentas> ivesk(int stud_sk, string gen);
void genPazEgz(studentas &student);


#endif //MYLIB_H_INCLUDED


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
#include <fstream>
#include <cctype>

using namespace std;

struct studentas
    {
        string var, pav;
        vector <int> paz;
        int egz;
        float vid;
        float med;
    };


vector<studentas> ivesk(int stud_sk, string gen);
void genPazEgz(studentas &student);
void isvedimas(vector<studentas> &grupe, string gen, string ats);
void pal_pav(vector<studentas> &grupe);


#endif //MYLIB_H_INCLUDED


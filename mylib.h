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
#include <stdexcept>

using namespace std;
struct studentas
    {
        string var, pav;
        vector <int> paz;
        int egz;
        float vid;
        float med;
    };

struct studentas_padalinimui
{
    string var, pav;
    vector<int> paz;
    int egz;
    float vid;
};


vector<studentas> ivesk(int stud_sk, string gen);
void isvedimas(vector<studentas> &grupe, string gen, string ats);
void pal_pav(vector<studentas> &grupe);
void gen_failas(int stud_gen_sk, int stud_gen_nd);
void padalinto_sapuzdinimas(vector<studentas_padalinimui>& studentai, string& failo_pav);

#endif //MYLIB_H_INCLUDED


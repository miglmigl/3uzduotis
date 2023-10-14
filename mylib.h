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
#include <chrono>

using namespace std;
struct studentas
    {
        string var, pav;
        vector <int> paz;
        int egz;
        float vid;
        float med;
        float galutinis;
    };


vector<studentas> ivesk(int stud_sk, string gen);
void isvedimas(vector<studentas> &grupe, string gen, string ats,string rus_index);
void pal_pav(vector<studentas> &grupe, string rus_index);
void gen_failas(int stud_gen_sk, int stud_gen_nd);
void padalinto_sapuzdinimas(const vector<studentas>& studentai, const string& failo_pav);
void nuskaitymas(const std::string& failas, std::vector<studentas>& grupe);
void skaiciavimas_2(int &suma, int paz_sk, studentas &temp, vector<studentas> &grupe);
void padalinimas(const vector<studentas>& grupe,vector<studentas>& kietiakai, vector<studentas>& vargsiukai);
int kiek_sk(const string& failas);
#endif //MYLIB_H_INCLUDED

#ifndef MYLIB_H_INCLUDED
#define MYLIB_H_INCLUDED

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
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



template <class I>
I ivesk(int stud_sk, std::string gen) {
    I grupe;

    for (int j = 0; j < stud_sk; j++) {
        studentas temp;
        std::cout << "Iveskite varda ir pavarde: ";
        std::cin >> temp.var >> temp.pav;

        if (gen == "T") {
            std::cout << "Iveskite namu darbu pazymius (baigti su dvigubu Enter): ";
            int num;
            while (std::cin >> num) {
                temp.paz.push_back(num);
                if (std::cin.get() == '\n' && temp.paz.size() > 0 && std::cin.peek() == '\n') {
                    std::cin.ignore();
                    break;
                }
            }
            std::cout << "Iveskite egzamino rezultata: ";
            std::cin >> temp.egz;
        }

        skaiciavimas(grupe, temp);
        grupe.push_back(temp);
    }

    return grupe;
}




template<class S>
void skaiciavimas(S &grupe, studentas &temp)
{

    // Skaiciuojame vidurki
    double suma = 0;
    for (int i = 0; i < temp.paz.size(); i++)
        {
            suma += temp.paz[i];
        }

    temp.vid = 0.4 * (suma / temp.paz.size()) + 0.6 * temp.egz;

    // Sukuriame vektoriu su visais gautais pazymiais ir egzaminu
    vector<int> visipaz = temp.paz; // vektorius saugos int tipo objektus, vadinsis visipaz, ji priliginam temp.paz (reiskaisi cia desim pazymius)
    visipaz.push_back(temp.egz);


    //Skaiciuojame mediana
    double med = 0.0;
    sort(visipaz.begin(), visipaz.end());
    if (visipaz.size() % 2 == 0)
        {
            med = (visipaz[(visipaz.size() / 2) - 1] + visipaz[visipaz.size() / 2]) / 2.0;
        }
    else
        {
            med = visipaz[visipaz.size() / 2];
        }

    temp.med = med;

    grupe.push_back(temp);
}









void isvedimas(vector<studentas> &grupe, string gen, string ats,string rus_index);
template <class P>
void pal_pav(P &grupe, string rus_index);
void gen_failas(int stud_gen_sk, int stud_gen_nd);
void padalinto_sapuzdinimas(const vector<studentas>& studentai, const string& failo_pav);
void skaiciavimas_2(int &suma, int paz_sk, studentas &temp, vector<studentas> &grupe);
void padalinimas(const vector<studentas>& grupe,vector<studentas>& kietiakai, vector<studentas>& vargsiukai);
int kiek_sk(const string& failas);


    template <class T>
void nuskaitymas(const string& failas, T& grupe) {
    std::ifstream in(failas);
    if (!in.is_open()) {
        std::cerr << "Klaida: Failas nerastas." << std::endl;
        return;
    }

    string pavadinimas, praleidziam;
    getline(in, pavadinimas);
    studentas temp;
    int laik_kint, suma = 0, m = 0;
    double paz_sk = 0;
    int raidziu_sk = 0;
    for (char ch : pavadinimas) {
        if (isalpha(ch)) {
            raidziu_sk++;
        }
    }

    paz_sk = (raidziu_sk - 6 - 7 - 3) / 2;


    while (in >> temp.var >> temp.pav) {

        for (int i = 0; i < paz_sk; i++) {
        in >> laik_kint;
            temp.paz.push_back(laik_kint);
            suma+=laik_kint;
        }

    in >> temp.egz;
    getline(in, praleidziam);

        skaiciavimas_2(suma,paz_sk,temp,grupe);
        m++;
    }

    in.close();
}




#endif //MYLIB_H_INCLUDED

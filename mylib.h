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

// Define the ContainerTypeTrait template
template <typename S>
struct ContainerTypeTrait;

// Specialize it for vector<studentas>
template <>
struct ContainerTypeTrait<vector<studentas>> {
    using type = vector<int>;
};

// Specialize it for list<studentas>
template <>
struct ContainerTypeTrait<list<studentas>> {
    using type = list<int>;
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




template <typename S>
void skaiciavimas(S &grupe, studentas &temp) {
    double suma = 0;

    for (int i = 0; i < temp.paz.size(); i++) {
        suma += temp.paz[i];
    }

    temp.vid = 0.4 * (suma / temp.paz.size()) + 0.6 * temp.egz;

    // Use the type trait to deduce the container type
    typename ContainerTypeTrait<S>::type visipaz;

    for (int i : temp.paz) {
        visipaz.push_back(i);
    }

    visipaz.push_back(temp.egz);

// Skaiciuojame mediana
double med = 0.0;
typename ContainerTypeTrait<S>::type::iterator it = visipaz.begin();
std::advance(it, visipaz.size() / 2);

if (visipaz.size() % 2 == 0)
{
    auto prev_it = std::prev(it);
    med = (*prev_it + *it) / 2.0;
}
else
{
    med = *it;
}

temp.med = med;

    grupe.push_back(temp);
}







void isvedimas(vector<studentas> &grupe, string gen, string ats,string rus_index);
void isvedimas_list(list<studentas> &grupe, string gen, string ats,string rus_index);
bool palyginimas(studentas &a, studentas &b, string rus_index);
template <class P>
void pal_pav(P &grupe, string rus_index) {
    sort(grupe.begin(), grupe.end(), [rus_index](studentas &a, studentas &b) {
        return palyginimas(a, b, rus_index);
    });
}
template <class P>
void pal_pav_list(P &grupe, string rus_index) {
    grupe.sort([rus_index](studentas &a, studentas &b) {
        return palyginimas(a, b, rus_index);
    });
}

void gen_failas(int stud_gen_sk, int stud_gen_nd);
//void padalinto_sapuzdinimas(const vector<studentas>& studentai, const string& failo_pav);
template <class S>
void skaiciavimas_2(int &suma, int paz_sk, studentas &temp, S &grupe);
//void padalinimas(const vector<studentas>& grupe,vector<studentas>& kietiakai, vector<studentas>& vargsiukai);
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





template <class S>
void skaiciavimas_2(int &suma, int paz_sk, studentas &temp, S &grupe) {

    temp.vid = static_cast<float>(suma)/paz_sk;


    // Mediana
    sort(temp.paz.begin(), temp.paz.end());

    double mediana = 0.0;
    int dydis = temp.paz.size();
    if (dydis % 2 == 0) {
        temp.med = static_cast<double>(temp.paz[(dydis - 1) / 2] + temp.paz[dydis / 2]) / 2.0;
    } else {
        temp.med = temp.paz[dydis / 2];
    }

    //Skaiciuojam galutinius balus
    temp.galutinis = static_cast<float>(temp.vid*0.4 + temp.egz*0.6);


    grupe.push_back(temp);
    temp.paz.clear();
    suma = 0;
}




template <class P>
void padalinimas(const P& grupe,P& kietiakai, P& vargsiukai) {

    for (auto &a: grupe) {
        if (a.galutinis >= 5) {
            kietiakai.push_back(a);
        } else {
            vargsiukai.push_back(a);
        }
    }
}





        ///Spauzdinimo funkcija vargsiuku ir kietiaku failams
        template <class P>
void padalinto_sapuzdinimas(const P& studentai, const string& failo_pav) {
    ofstream out(failo_pav);

    out << left << setw(20) << "Pavarde" << setw(20) << "Vardas" << setw(20) << "Galutinis" << endl;
    out << endl;

    for (const auto& stud : studentai) {
        out << left << setw(20) << stud.pav << setw(20) << stud.var << setw(20) << fixed << setprecision(2) << stud.galutinis << endl;


    }


    out.close();
    //cout << "Duomenys įrašyti į failą '" << failo_pav << "'" << endl;
}



#endif //MYLIB_H_INCLUDED

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
#include <numeric>
#include <iterator>


using namespace std;


#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

class Zmogus {
protected:
    string var_, pav_;


public:

    virtual void dummyFunction() const = 0;

    Zmogus(const string& var, const string& pav)
        : var_(var), pav_(pav) {}

    virtual ~Zmogus() {} //banglentininkas

    virtual string getVar() const { return var_; }
    virtual string getPav() const { return pav_; }

    virtual void setVar(const string& var) {
        var_ = var;
    }

    virtual void setPav(const string& pav) {
        pav_ = pav;
    }
};

class Studentas : public Zmogus {
private:
    int egz_;
    vector<int> paz;
    double vid_, galutinis_, med_;

public:
    Studentas() : Zmogus("", ""), egz_(0), med_(0), galutinis_(0), vid_(0) {}

    // Konstruktorius inicijuojantis bazine ir isvestine klases
    Studentas(const string& var, const string& pav, const std::vector <int> &paz, int egz)
        : Zmogus(var, pav), egz_(egz),  med_(0), galutinis_(0), vid_(0) {}



                /// Rule of three

    // Copy constructor
    Studentas(const Studentas& other)
        : Zmogus(other.getVar(), other.getPav()),
        egz_(other.egz_),
        paz(other.paz),
        vid_(other.vid_),
        galutinis_(other.galutinis_),
        med_(other.med_) {
        //cout << "Suveikė Copy konstruktorius" << endl;
    }

    // Copy assignment operator
    Studentas& operator=(const Studentas& other) {
        if (this != &other) {
            Zmogus::setVar(other.getVar());
            Zmogus::setPav(other.getPav());
            egz_ = other.egz_;
            paz = other.paz;
            vid_ = other.vid_;
            galutinis_ = other.galutinis_;
            med_ = other.med_;
            //cout << "Suveikė Copy assignment operatorius" << endl;
        }
        return *this;
    }

    // Destructorius
    ~Studentas() {
        //std::cout << "Suveikė destruktorius " << std::endl;
    }

    std::string getVar() const { return var_; }
    std::string getPav() const { return pav_; }
    vector<int> getPaz() const { return paz; }
    int getEgz() const { return egz_; }
    double getGalutinis() const { return galutinis_; }
    double getMed() const { return med_; }
    double getVid() const { return vid_; }
    int getPazSize() const { return paz.size(); }
    int getPazEl(int i) const { return paz[i]; }

    //Išvesties operatorius
    friend std::ostream& operator<<(std::ostream& out, const Studentas& a) {
        out << left << setw(20) << a.getPav() << setw(20) << a.getVar() << setw(20);
        return out;
    }

    //Įvesties operatorius
    friend std::istream& operator>>(std::istream& in, Studentas& a) {
        std::string vardas, pavarde;
        in >> vardas >> pavarde;
        a.setVar(vardas);
        a.setPav(pavarde);
        return in;
    }

    void setVar(std::string);
    void setPav(std::string);
    void setEgz(int);
    void setGalutinis(double);
    void setMed(double);
    void setVid(double);
    void setPaz(int);
    void emptyPaz();
    void sortPaz();


    virtual void dummyFunction() const {
        // Empty implementation
    }


    template <typename S>
    struct ContainerTypeTrait;

    template <>
    struct ContainerTypeTrait<std::vector<Studentas>> {
        using type = std::vector<Studentas>;
    };

    template <>
    struct ContainerTypeTrait<std::list<Studentas>> {
        using type = std::list<Studentas>;
    };


};

bool palyginimas(Studentas& a, Studentas& b, std::string rus_index);

template <class T>
void nuskaitymas(const std::string& failas, T& grupe);


template <class S>
void skaiciavimas_2(int& suma, int paz_sk, Studentas& temp, S& grupe) {

    temp.setVid(static_cast<float>(suma) / paz_sk);


    // Mediana
    temp.sortPaz();

    int dydis = temp.getPazSize();

    if (dydis % 2 == 0) {
        temp.setMed((static_cast<double>(temp.getPazEl((dydis - 1) / 2)) + temp.getPazEl(dydis / 2)) / 2.0);

    }
    else {
        temp.setMed(temp.getPazEl(dydis / 2));
    }

    //Skaiciuojam galutinius balus
    temp.setGalutinis(static_cast<float>(temp.getVid() * 0.4 + temp.getEgz() * 0.6));


    grupe.push_back(temp);
    temp.emptyPaz();
    suma = 0;
}





template <class S>
void isvedimas(S& grupe, std::string gen, std::string ats) {
    if (gen == "T")
    {

        std::cout << endl << "    Grupės objekto saugojimo atmintyje adresas: " << &grupe << "    " << endl << endl;
        std::cout << left << setw(20) << "Pavarde" << setw(20) << "Vardas" << setw(20);
        if (ats == "M") {
            std::cout << "Galutinis (Med.)" << setw(80) << "Studento objekto saugojimo atmintyje adresass" << endl;
            std::cout << "--------------------------------------------------------------------------------------------------------------\n";
            for (auto& a : grupe) {
                std::cout << a << fixed << setprecision(2) << a.getMed() << setw(80) << &a << endl; //pritaikytas išvesties operatoriaus persidengimas

            }
        }
        else if (ats == "V") {
            std::cout << "Galutinis (Vid.)" << setw(80) << "Studento objekto saugojimo atmintyje adresass" << endl;
            std::cout << "--------------------------------------------------------------------------------------------------------------\n";
            // Imame po elementa is "grupe" vektoriaus (po studenta)
            for (auto& a : grupe) {
                std::cout << a << fixed << setprecision(2) << a.getGalutinis() << setw(80) << &a << endl; //pritaikytas išvesties operatoriaus persidengimas

            }
        }
    }
    else if (gen == "F") {
        ofstream out("rezultatai.txt");
        out << left << setw(20) << "Pavarde" << setw(20) << "Vardas" << setw(20) << "Galutinis (Vid.)" << setw(20) << "Galutinis (Med.)" << endl;
        out << "-----------------------------------------------------------------------\n";


        for (auto& a : grupe) {

            out << a << fixed << setprecision(2) << a.getGalutinis() << setw(20) << fixed << setprecision(2) << a.getMed() << endl; //pritaikytas išvesties operatoriaus persidengimas
        }
        out.close();
        //cout << "Isvesti duomenys irasyti i faila 'rezultatai.txt' "<< endl;
    }
}



template <class T>
void nuskaitymas(const std::string& failas, T& grupe) {
    std::ifstream in(failas);
    if (!in.is_open()) {
        std::cerr << "Klaida: Failas nerastas." << std::endl;
        return;
    }

    string pavadinimas, praleidziam;
    getline(in, pavadinimas);
    Studentas temp;
    int laik_kint, suma = 0, m = 0;
    int paz_sk = 0;
    int raidziu_sk = 0;
    for (char ch : pavadinimas) {
        if (isalpha(ch)) {
            raidziu_sk++;
        }
    }

    paz_sk = (raidziu_sk - 6 - 7 - 3) / 2;


    int egz;



    while (in >> temp) {  // įvesties persidengimo operatorius
        for (int i = 0; i < paz_sk; i++) {
            in >> laik_kint;
            temp.setPaz(laik_kint);
            suma += laik_kint;
        }



        in >> egz;
        temp.setEgz(egz);

        getline(in, praleidziam);

        skaiciavimas_2(suma, paz_sk, temp, grupe);
        m++;
    }

    in.close();
}




template <class P>
void padalinimas(P& grupe, P& vargsiukai) {
    auto partitionPoint = std::partition(grupe.begin(), grupe.end(), [](const Studentas& a) {
        return a.getGalutinis() < 5;
        });

    // Visus studentus, kuriu galutinis < 5 dedame i vargsiukus
    vargsiukai.insert(vargsiukai.end(), grupe.begin(), partitionPoint);

    // Is grupes istriname studentus, kurie buvo ideti i vargsiukus
    grupe.erase(grupe.begin(), partitionPoint);
}






template <class P>
void padalinto_sapuzdinimas(const P& studentai, const std::string& failo_pav) {
    ofstream out(failo_pav);

    out << left << setw(20) << "Pavarde" << setw(20) << "Vardas" << setw(20) << "Galutinis" << endl;
    out << endl;

    for (auto& stud : studentai) {
        out << stud << setw(20) << fixed << setprecision(2) << stud.getGalutinis() << endl; //pritaikytas išvesties operatoriaus persidengimas
    }
    out.close();
    //cout << "Duomenys įrašyti į failą '" << failo_pav << "'" << endl;
}




template <class I>
I ivesk(int stud_sk, std::string gen) {
    I grupe;

    for (int j = 0; j < stud_sk; j++) {
        Studentas temp;
        std::cout << "Iveskite varda ir pavarde: ";
        std::cin >> temp; // įvesties persidengimo operatorius


        int suma = 0;
        if (gen == "T") {
            std::cout << "Iveskite namu darbu pazymius (baigti su dvigubu Enter): ";
            int num;
            while (std::cin >> num) {
                temp.setPaz(num);
                suma += num;
                if (std::cin.get() == '\n' && temp.getPazSize() > 0 && std::cin.peek() == '\n') {
                    std::cin.ignore();
                    break;
                }
            }
            int a = 0;
            std::cout << "Iveskite egzamino rezultata: ";
            std::cin >> a;
            temp.setEgz(a);
        }
        int paz_sk = temp.getPazSize();
        skaiciavimas_2(suma, paz_sk, temp, grupe);

    }

    return grupe;
}


template <class S>
void isvedimas(S& grupe, std::string gen, std::string ats);

bool palyginimas(Studentas& a, Studentas& b, std::string rus_index);
int kiek_sk(const std::string& failas);
void gen_failas(int stud_gen_sk, int stud_gen_nd);

template <class I>
I ivesk(int stud_sk, std::string gen);


void pal_pav(std::vector<Studentas>& grupe, std::string rus_index);
void pal_pav_list(std::list<Studentas>& grupe, std::string rus_index);


template <class S>
void skaiciavimas_2(int& suma, int paz_sk, Studentas& temp, S& grupe);

template <class P>
void padalinimas(P& grupe, P& vargsiukai);

template <class P>
void padalinto_sapuzdinimas(const P& studentai, const std::string& failo_pav);



template <typename S>
struct ContainerTypeTrait;

template <>
struct ContainerTypeTrait<std::vector<Studentas>> {
    using type = std::vector<Studentas>;
};

template <>
struct ContainerTypeTrait<std::list<Studentas>> {
    using type = std::list<Studentas>;
};


#endif

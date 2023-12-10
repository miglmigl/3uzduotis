#include "mylib.h"



void Studentas::setVar(std::string var) {
    var_ = var;
}

void Studentas::setPav(std::string pav) {
    pav_ = pav;
}

void Studentas::setEgz(int egz) {
    egz_ = egz;
}
void Studentas::setGalutinis(double galutinis) {
    galutinis_ = galutinis;
}
void Studentas::setMed(double med) {
    med_ = med;
}

void Studentas::setVid(double vid) {
    vid_ = vid;
}

void Studentas::setPaz(int Score)
{
    paz.push_back(Score);
}

void Studentas::emptyPaz()
{
    paz.clear();
}
void Studentas::sortPaz() {
    sort(paz.begin(), paz.end());
}




bool palyginimas(Studentas& a, Studentas& b, std::string rus_index) {
    if (rus_index == "P") {
        return a.getPav() < b.getPav();
    }
    else if (rus_index == "V") {
        return a.getVar() < b.getVar();
    }
    else if (rus_index == "G") {
        return a.getGalutinis() < b.getGalutinis();
    }
    else {
        // Automatinis nustatymas, kai rus_index neatpazintas
        return false;
    }
}




int kiek_sk(const std::string& failas) {
    int kiekis = 0;
    string numberPart;
    bool rastas_sk = false;

    for (char c : failas) {
        if (rastas_sk) {
            if (std::isdigit(c)) {
                numberPart += c;
            }
            else {
                break;  // Sustoja kai suranda ne skaiciu
            }
        }
        else if (std::isdigit(c)) {
            rastas_sk = true;
            numberPart += c;
        }
    }

    if (!numberPart.empty()) {
        // Surinktas skaicius is eilutes paverciamas i sveikajo skaiciu
        std::istringstream(numberPart) >> kiekis;
    }

    return kiekis;
}




void gen_failas(int stud_gen_sk, int stud_gen_nd) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> rand_score(1, 10);



    ofstream out("Kursiokai" + to_string(stud_gen_sk) + ".txt");
    out << left << setw(20) << "Vardas" << setw(20) << "Pavarde";

    for (int m = 1; m <= stud_gen_nd; m++) {
        out << setw(7) << "ND" + to_string(m);
    }

    out << setw(7) << "Egz." << setw(15) << endl;
    out << endl;

    for (int i = 1; i <= stud_gen_sk; i++) {
        Studentas stud;
        stud.setVar("Vardas" + to_string(i));
        stud.setPav("Pavarde" + to_string(i));
        out << left << setw(20) << stud.getVar() << setw(20) << stud.getPav();
        stud.setEgz(rand_score(gen));

        double suma = 0;

        for (int j = 0; j < stud_gen_nd; j++) {
            int pazymys = rand_score(gen);
            out << setw(7) << pazymys;
        }
        out << setw(7) << stud.getEgz() << endl;
    }
    out.close();
}




void pal_pav(std::vector<Studentas>& grupe, std::string rus_index) {
    sort(grupe.begin(), grupe.end(), [rus_index](Studentas& a, Studentas& b) {
        return palyginimas(a, b, rus_index);
        });
}


void pal_pav_list(std::list<Studentas>& grupe, std::string rus_index) {
    grupe.sort([rus_index](Studentas& a, Studentas& b) {
        return palyginimas(a, b, rus_index);
        });
}

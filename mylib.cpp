#include "mylib.h"



int kiek_sk(const string& failas) {
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









///Failo generavimas
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
        studentas stud;
        stud.var = "Vardas" + to_string(i);
        stud.pav = "Pavarde" + to_string(i);
        out << left << setw(20) << stud.var << setw(20) << stud.pav;
        stud.egz = rand_score(gen);

        double suma = 0;

        for (int j = 0; j < stud_gen_nd; j++) {
            int pazymys = rand_score(gen);
            stud.paz.push_back(pazymys);
            suma += pazymys;

            out << setw(7) << pazymys;
        }
        out << setw(7) << stud.egz << endl;
    }
    out.close();
}




///Palyginimas pagal P, V arba G
bool palyginimas(studentas& a, studentas& b, string rus_index) {
    if (rus_index == "P") {
        return a.pav < b.pav;
    }
    else if (rus_index == "V") {
        return a.var < b.var;
    }
    else if (rus_index == "G") {
        return a.galutinis < b.galutinis;
    }
    else {
        // Automatinis nustatymas, kai rus_index neatpazintas
        return false;
    }
}



///Isvedimo funkcija

void isvedimas(vector<studentas>& grupe, string gen, string ats, string rus_index) {
    if (gen == "T")
    {
        // Rusiuojame pagal pavardes
        rus_index = "P";
        pal_pav(grupe, rus_index);
        cout << endl << "    Grupės objekto saugojimo atmintyje adresas: " << &grupe << "    " << endl << endl;
        cout << left << setw(20) << "Pavarde" << setw(20) << "Vardas" << setw(20);
        if (ats == "M") {
            cout << "Galutinis (Med.)" << setw(80) << "Studento objekto saugojimo atmintyje adresass" << endl;
            cout << "--------------------------------------------------------------------------------------------------------------\n";
            for (auto& a : grupe) {
                cout << left << setw(20) << a.pav << setw(20) << a.var << setw(20) << fixed << setprecision(2) << a.med << setw(80) << &a << endl;
            }
        }
        else if (ats == "V") {
            cout << "Galutinis (Vid.)" << setw(80) << "Studento objekto saugojimo atmintyje adresass" << endl;
            cout << "--------------------------------------------------------------------------------------------------------------\n";
            // Imame po elementa is "grupe" vektoriaus (po studenta)
            for (auto& a : grupe) {
                cout << left << setw(20) << a.pav << setw(20) << a.var << setw(20) << fixed << setprecision(2) << a.vid << setw(80) << &a << endl;
            }
        }
    }
    else if (gen == "F") {
        ofstream out("rezultatai.txt");
        out << left << setw(20) << "Pavarde" << setw(20) << "Vardas" << setw(20) << "Galutinis (Vid.)" << setw(20) << "Galutinis (Med.)" << endl;
        out << "-----------------------------------------------------------------------\n";

        // Rusiuojame pagal pavardes
        pal_pav(grupe, rus_index);

        for (auto& a : grupe) {

            out << left << setw(20) << a.pav << setw(20) << a.var << setw(20) << fixed << setprecision(2) << a.galutinis << setw(20) << fixed << setprecision(2) << a.med << endl;
        }
        out.close();
        //cout << "Isvesti duomenys irasyti i faila 'rezultatai.txt' "<< endl;
    }
}




void isvedimas_list(list<studentas>& grupe, string gen, string ats, string rus_index) {
    if (gen == "T") {
        // Rusiuojame pagal pavardes
        rus_index = "P";
        pal_pav_list(grupe, rus_index);
        cout << endl << "    Grupės objekto saugojimo atmintyje adresas: " << &grupe << "    " << endl << endl;
        cout << left << setw(20) << "Pavarde" << setw(20) << "Vardas" << setw(20);
        if (ats == "M") {
            cout << "Galutinis (Med.)" << setw(80) << "Studento objekto saugojimo atmintyje adresass" << endl;
            cout << "--------------------------------------------------------------------------------------------------------------\n";
            for (auto& a : grupe) {
                cout << left << setw(20) << a.pav << setw(20) << a.var << setw(20) << fixed << setprecision(2) << a.med << setw(80) << &a << endl;
            }
        }
        else if (ats == "V") {
            cout << "Galutinis (Vid.)" << setw(80) << "Studento objekto saugojimo atmintyje adresass" << endl;
            cout << "--------------------------------------------------------------------------------------------------------------\n";
            // Imame po elementa is "grupe" vektoriaus (po studenta)
            for (auto& a : grupe) {
                cout << left << setw(20) << a.pav << setw(20) << a.var << setw(20) << fixed << setprecision(2) << a.vid << setw(80) << &a << endl;
            }
        }

    }
    else if (gen == "F") {
        ofstream out("rezultatai.txt");
        out << left << setw(20) << "Pavarde" << setw(20) << "Vardas" << setw(20) << "Galutinis (Vid.)" << setw(20) << "Galutinis (Med.)" << endl;
        cout << "--------------------------------------------------------------------------------------------------------------\n";

        // Rusiuojame pagal pavardes
        pal_pav_list(grupe, rus_index);

        for (auto& a : grupe) {

            out << left << setw(20) << a.pav << setw(20) << a.var << setw(20) << fixed << setprecision(2) << a.galutinis << setw(20) << fixed << setprecision(2) << a.med << endl;
        }
        out.close();
        //cout << "Isvesti duomenys irasyti i faila 'rezultatai.txt' "<< endl;
    }
}

#include "mylib.h"
#include <fstream>

int main() {
    int stud_sk;
    string gen;
    cout << "Kiek studentu yra kurse? ";
    cin >> stud_sk;
    cout << "Norite patys vesti pazymius ir egzamino rezultata? T/N? " << endl;
    cin >> gen;

    vector<studentas> grupe = ivesk(stud_sk, gen);
    string ats;

    cout << "Norite medianos ar vidurkio? M/V " << endl;
    cin >> ats;

    // Atidarome failą duomenų įvedimui
    ofstream isvedimas("kursiokai.txt");

    isvedimas << left << setw(15) << "Vardas" << setw(15) << "Pavarde";
    for (int i = 1; i <= 5; i++) {
        isvedimas << left<< setw(2) << "Nd" << setw(6) << i;
    }
    isvedimas << left << setw(10) << "Egzaminas" << endl;

    for (auto &a : grupe) {
        isvedimas << left << setw(15) << a.var << setw(15) << a.pav;
        for (int i = 0; i < 5; i++) {
            isvedimas << left << setw(8) << a.paz[i];
        }
        isvedimas << left << setw(10) << a.egz << endl;
    }

    isvedimas.close();

    cout << "Duomenys įrašyti į failą 'kursiokai.txt'." << endl;

    return 0;
}







/*
int main()
{
    int stud_sk;
    string gen;
    cout << "Kiek studentu yra kurse? ";
    cin >> stud_sk;
    cout << "Norite patys vesti pazymius ir egzamino rezultata? T/N? " << endl;
    cin >> gen;

    vector<studentas> grupe = ivesk(stud_sk, gen);
    string ats;



    cout<< "Norite medianos ar vidurkio? M/V "<< endl;
    cin>>ats;

    cout << left << setw(20) << "Pavarde" << setw(20) << "Vardas" << setw(20);
    if (ats == "M")
    {
        cout << "Galutinis (Med.)" <<endl;
        cout<<"--------------------------------------------------------\n";
        for (auto &a : grupe)
        {
            cout << left << setw(20) << a.pav << setw(20) << a.var << setw(20) << fixed << setprecision(2) << a.med << endl;
        }


    }
    else if (ats == "V")
    {
        cout<< "Galutinis (Vid.)" << endl;
        cout<<"--------------------------------------------------------\n";
        for (auto &a : grupe)
        {
            cout << left << setw(20) << a.pav << setw(20) << a.var << setw(20) << fixed << setprecision(2) << a.vid << endl;
        }

    }
    else
    {
        cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nNeteisinga ivestis"<<endl;
        return 0;
    }


    return 0;
}
*/



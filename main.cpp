#include "mylib.h"

int main()
{
    int stud_sk;
    string gen;
    cout << "Norite patys vesti pazymius ir egzamino rezultata (T), generuoti automatiskai (G), ar nuskaityti is failo(F)? T/G/F? " << endl;
    cin >> gen;
    vector<studentas> grupe;
    string ats;

    if (gen == "T" || gen == "G")
        {
            cout << "Kiek studentu yra kurse? ";
            cin >> stud_sk;
            grupe = ivesk(stud_sk, gen);
            cout << "Norite medianos ar vidurkio? M/V " << endl;
    cin >> ats;
        }
    else if (gen == "F")
        {
            stud_sk=0;
            grupe = ivesk(stud_sk,gen);
             cout << left << setw(20) << "Pavarde" << setw(20) << "Vardas" << setw(20)<<"Galutinis (Vid.)" << setw(20) << "Galutinis (Med.)" << endl;
            cout << "-----------------------------------------------------------------------\n";
            for (auto &a : grupe)
                {
                    cout << left << setw(20) << a.pav << setw(20) << a.var << setw(20) << fixed << setprecision(2) << a.vid << setw(20) << fixed << setprecision(2) << a.med << endl;
                }
                return 0;
        }




    cout << left << setw(20) << "Pavarde" << setw(20) << "Vardas" << setw(20);
    if (ats == "M")
        {
            cout << "Galutinis (Med.)" << endl;
            cout << "--------------------------------------------------------\n";
            for (auto &a : grupe)
                {
                    cout << left << setw(20) << a.pav << setw(20) << a.var << setw(20) << fixed << setprecision(2) << a.med << endl;
                }
        }
    else if (ats == "V")
        {
            cout << "Galutinis (Vid.)" << endl;
            cout << "--------------------------------------------------------\n";
            for (auto &a : grupe)
                {
                    cout << left << setw(20) << a.pav << setw(20) << a.var << setw(20) << fixed << setprecision(2) << a.vid << endl;
                }
        }
    else{
        cout<< "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nNeteisinga ivestis"<<endl;
        return 0;
    }



    return 0;
}










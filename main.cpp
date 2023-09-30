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
            stud_sk = 0;
            grupe = ivesk(stud_sk, gen);
        }

    //Isvedame duomenis
    isvedimas(grupe, gen, ats);

    return 0;
}

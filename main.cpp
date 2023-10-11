

#include "mylib.h"

int main() {
    int stud_sk;
    string gen;
    vector<studentas> grupe; // sukuriame tuscia vektoriu, pavadinta "grupe", kuris saugos objektus "studentas"
    string ats;

    while (true) {
        try {
            cout << "Norite patys vesti pazymius ir egzamino rezultata (T), generuoti automatiskai (G), ar nuskaityti is failo(F)? T/G/F? " << endl;
            cin >> gen;

            // Tikriname ar irasytas gen yra T, G arba F
            if (gen != "T" && gen != "G" && gen != "F") {
                throw invalid_argument("Neteisinga ivestis. Iveskite T, G arba F.");
            }

               if (gen == "T") {
        cout << "Kiek studentu yra kurse? ";
        cin >> stud_sk;
        grupe = ivesk(stud_sk, gen);

        // Tikriname ar pasirinkta tarp V ir M
        while (ats != "M" && ats != "V") {
            cout << "Norite medianos ar vidurkio? M/V " << endl;
            cin >> ats;

            if (ats != "M" && ats != "V") {
                cerr << "Klaida: Neteisinga ivestis. Pasirinkite M arba V." << endl;
            }
        }
    }
     else if (gen == "G")
     {

        int stud_gen_sk, stud_gen_nd;
        cout << "Kiek studentu bus jusu generuojamame faile?\n";
        cin >> stud_gen_sk;
        cout << "Kiek tarpiniu namu darbu pazymiu vesite kiekviem studentui?\n";
        cin >> stud_gen_nd;

            gen_failas(stud_gen_sk, stud_gen_nd);
     }



    else if (gen == "F") {
                stud_sk = 0;
                grupe = ivesk(stud_sk, gen);
            }

            //Isvedame duomenis
            isvedimas(grupe, gen, ats);

            break; // Iseiname is ciklo, jei nesugavome nieko su "try"
        }
        // Jei gauname "invalid_argument" tada suveikia si funkcija ir pasako, kad buvo padaryta klaida
        catch (invalid_argument& e) {
            cerr << "Klaida: " << e.what()<<endl;
        }
    }
    return 0;
}


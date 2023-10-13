
#include "mylib.h"

int main() {
    int stud_sk;
    string gen;
    vector<studentas> grupe; // sukuriame tuscia vektoriu, pavadinta "grupe", kuris saugos objektus "studentas"
    string ats;
    string rus_index;

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
        isvedimas(grupe, gen, ats,rus_index);
    }
     else if (gen == "G")
     {

        int stud_gen_sk, stud_gen_nd;
        cout << "Kiek studentu bus jusu generuojamame faile?\n";
        cin >> stud_gen_sk;
        cout << "Kiek tarpiniu namu darbu pazymiu vesite kiekviem studentui?\n";
        cin >> stud_gen_nd;
                        auto start = std::chrono::high_resolution_clock::now();
                gen_failas(stud_gen_sk, stud_gen_nd);
                auto end = std::chrono::high_resolution_clock::now();
                std::chrono::duration<double> diff = end - start;
        cout << " Studentu failo 'Kursiokai"<<to_string(stud_gen_sk)<<".txt' generavimas uztruko: "<< diff.count() << " s;" << endl;


            cout << "Duomenys irasyti i faila 'Kursiokai" << stud_gen_sk << ".txt'" << endl;

     }



    else if (gen == "F") {
    string failas;
    system("dir *.txt");
    cout << "Iveskite failo, kuri norite nuskaityti pavadinima (formatas: pavadinimas.txt): ";
    cin >> failas;


    nuskaitymas(failas, grupe);
            vector<studentas> vargsiukai;
       vector<studentas> kietiakai;
       padalinimas(grupe, kietiakai, vargsiukai);
       padalinto_sapuzdinimas(kietiakai, "kietiakai.txt");
        padalinto_sapuzdinimas(vargsiukai, "vargsiukai.txt");
cout << "Pagal ka noresite rusiuoti rezultatus: P - pavardes, V - vardus, G - galutini bala?/n";
cin >> rus_index;
            //Isvedame duomenis
            isvedimas(grupe, gen, ats,rus_index);
            }





            break; // Iseiname is ciklo, jei nesugavome nieko su "try"
        }
        // Jei gauname "invalid_argument" tada suveikia si funkcija ir pasako, kad buvo padaryta klaida
        catch (invalid_argument& e) {
            cerr << "Klaida: " << e.what()<<endl;
        }
    }
    return 0;
}

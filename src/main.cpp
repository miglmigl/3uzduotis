#include "mylib.h"

int main() {
    int stud_sk;
    string gen;
    string struktura;
    string ats;
    string rus_index;


    std::cout << "Norite atlikti veiksmus su vector<studentas> (V) ar list <studentas> (L)" << endl;
    cin >> struktura;

    if (struktura == "V")
    {
        vector<Studentas> grupe;


        while (true) {
            try {
                std::cout << "Norite patys vesti pazymius ir egzamino rezultata (T), generuoti automatiskai (G), nuskaityti is failo(F), pademostruoti Trijų taisyklę (R) ar pademonstruoti kaip klases Zmogus objektas, negali buti sukurtas(Z)? T/G/F/R/Z? " << endl;
                cin >> gen;

                // Tikriname ar irasytas gen yra T, G arba F
                if (gen != "T" && gen != "G" && gen != "F" && gen != "R" && gen != "Z") {
                    throw invalid_argument("Neteisinga ivestis. Iveskite T, G , F, R arba Z");
                }


                if (gen == "Z") {

                    /*Zmogus zmogelis;

                    zmogelis.setVar("Zmogvardas");
                    zmogelis.setPav("Pavardzmogas");
                    string a = zmogelis.getVar();
                    string b = zmogelis.getPav();
                    std::cout << a << " " << b;*/

                    Studentas zmogeliukas;

                    zmogeliukas.setVar("Zmogvardas");
                    zmogeliukas.setPav("Pavardzmogas");
                    cout << zmogeliukas.getPav() << zmogeliukas.getVar() << endl;

                    string asdf;
                    cout << "Iveskite bet ka noredami baigti\n";
                    cin >> asdf;
                    return 0;
                }

                else if (gen == "R") {



                    Studentas s1;
                    s1.setEgz(100);
                    std::cout << "Pirmo studento įvertinimas: " << s1.getEgz() << endl;
                    auto s2{ s1 }; // Copy constructor
                    std::cout << "Antro studento įvertinimas: " << s2.getEgz() << endl;
                    Studentas s3;
                    s3.setEgz(92);
                    std::cout << "Trečio studento įvertinimas: " << s3.getEgz() << endl;
                    s3 = s2; // Copy 
                    std::cout << "Trečio studento įvertinimas: " << s3.getEgz() << endl;


                    string asdf;
                    cout << "Iveskite bet ka noredami baigti\n";
                    cin >> asdf;
                    return 0;
                } // Destruktorius iškviečiamas čia





                else if (gen == "T") {
                    std::cout << "Kiek studentu yra kurse? ";
                    cin >> stud_sk;
                    vector<Studentas> grupe = ivesk<vector<Studentas>>(stud_sk, gen);

                    std::cout << "Grupės objekto saugojimo atmintyje adresas: " << &grupe << endl;
                    for (auto& student : grupe) { std::cout << "Studento objekto saugojimo atmintyje adresas: " << &student << endl; }

                    // Tikriname ar pasirinkta tarp V ir M
                    while (ats != "M" && ats != "V") {
                        std::cout << "Norite medianos ar vidurkio? M/V " << endl;
                        cin >> ats;

                        if (ats != "M" && ats != "V") {
                            cerr << "Klaida: Neteisinga ivestis. Pasirinkite M arba V." << endl;

                        }
                    }
                    std::string rus_index;
                    rus_index = "P";
                    pal_pav(grupe, rus_index);
                    isvedimas(grupe, gen, ats);

                    string asdf;
                    cout << "Iveskite bet ka noredami baigti\n";
                    cin >> asdf;
                    return 0;

                }


                else if (gen == "G") {
                    int stud_gen_sk, stud_gen_nd;
                    std::cout << "Kiek studentu bus jusu generuojamame faile?\n";
                    cin >> stud_gen_sk;
                    std::cout << "Kiek tarpiniu namu darbu pazymiu vesite kiekviem studentui?\n";
                    cin >> stud_gen_nd;

                    for (int i = 0; i < 5; i++) {
                        auto Generavimo_start = chrono::high_resolution_clock::now();
                        vector<Studentas> studentai;
                        gen_failas(stud_gen_sk, stud_gen_nd);
                        auto Generavimo_end = chrono::high_resolution_clock::now();
                        chrono::duration<double> Generavimo_laikas = Generavimo_end - Generavimo_start;
                        std::cout << to_string(stud_gen_sk) << " irasu generavimas uztruko: " << Generavimo_laikas.count() << " s;" << endl;
                        std::cout << "Duomenys irasyti i faila 'Kursiokai" << stud_gen_sk << ".txt'" << endl;
                    }
                    string asdf;
                    cout << "Iveskite bet ka noredami baigti\n";
                    cin >> asdf;
                    return 0;

                }


                else if (gen == "F") {
                    string failas;
                    system("dir *.txt");
                    std::cout << "Iveskite failo, kuri norite nuskaityti pavadinima (formatas: pavadinimas.txt): ";
                    cin >> failas;
                    std::cout << "Pagal ka noresite rusiuoti rezultatus: P - pavardes, V - vardus, G - galutini bala?\n";
                    cin >> rus_index;

                    int kiekis = kiek_sk(failas);

                    for (int i = 0; i < 5; i++) {

                        std::cout << endl << endl;
                        std::cout << i + 1 << " nuskaitymas" << endl;

                        auto Nuskaitymo_start = chrono::high_resolution_clock::now();
                        nuskaitymas(failas, grupe);
                        auto Nuskaitymo_end = chrono::high_resolution_clock::now();
                        chrono::duration<double> Nuskaitymo_laikas = Nuskaitymo_end - Nuskaitymo_start;
                        std::cout << kiekis << " irasu nuskaitymas uztruko: " << Nuskaitymo_laikas.count() << " s;" << endl;


                        auto Rusiavimas_start = chrono::high_resolution_clock::now();
                        pal_pav(grupe, rus_index);
                        auto Rusiavimas_end = chrono::high_resolution_clock::now();
                        chrono::duration<double> Rusiavimas_laikas = Rusiavimas_end - Rusiavimas_start;
                        std::cout << kiekis << " irasu rusiavimas pagal " << rus_index << " uztruko: " << Rusiavimas_laikas.count() << " s;" << endl;


                        auto Padalinimo_start = chrono::high_resolution_clock::now();
                        vector<Studentas> vargsiukai;
                        vector<Studentas> kietiakai;
                        padalinimas(grupe, vargsiukai);
                        kietiakai = grupe;
                        auto Padalinimo_end = chrono::high_resolution_clock::now();
                        chrono::duration<double> Padalinimo_laikas = Padalinimo_end - Padalinimo_start;
                        std::cout << kiekis << " irasu surusiavimas i dvi grupes uztruko: " << Padalinimo_laikas.count() << " s;" << endl;


                        pal_pav(kietiakai, rus_index);
                        pal_pav(vargsiukai, rus_index);


                        auto Kietiaku_sp_start = chrono::high_resolution_clock::now();
                        padalinto_sapuzdinimas(kietiakai, "kietiakai.txt");
                        auto Kietiaku_sp_end = chrono::high_resolution_clock::now();
                        chrono::duration<double> Kietiaku_sp_laikas = Kietiaku_sp_end - Kietiaku_sp_start;
                        std::cout << kiekis << " irasu kietiaku irasymas i faila uztruko: " << Kietiaku_sp_laikas.count() << " s;" << endl;


                        auto Vargsiuku_sp_start = chrono::high_resolution_clock::now();
                        padalinto_sapuzdinimas(vargsiukai, "vargsiukai.txt");
                        auto Vargsiuku_sp_end = chrono::high_resolution_clock::now();
                        chrono::duration<double> Vargsiuku_sp_laikas = Vargsiuku_sp_end - Vargsiuku_sp_start;
                        std::cout << kiekis << " irasu vargsiuku irasymas i faila uztruko: " << Vargsiuku_sp_laikas.count() << " s;" << endl;
                        double visas_laikas = Nuskaitymo_laikas.count() + Rusiavimas_laikas.count() + Padalinimo_laikas.count() + Kietiaku_sp_laikas.count() + Vargsiuku_sp_laikas.count();
                        std::cout << kiekis << " irasu testo laikas: " << visas_laikas << " s;" << endl;

                        grupe.clear();

                    }
                    //Isvedame duomenis
                    //isvedimas(grupe, gen, ats,rus_index);
                }


                break; // Iseiname is ciklo, jei nesugavome nieko su "try"
            }
            // Jei gauname "invalid_argument" tada suveikia si funkcija ir pasako, kad buvo padaryta klaida
            catch (invalid_argument& e) {
                cerr << "Klaida: " << e.what() << endl;
            }
        }
        string asdf;
        cout << "Iveskite bet ka noredami baigti\n";
        cin >> asdf;
        return 0;
    }




    /// Su list<studentas>


    else if (struktura == "L") {
        list<Studentas> grupe;


        while (true) {
            try {
                std::cout << "Norite patys vesti pazymius ir egzamino rezultata (T), generuoti automatiskai (G), nuskaityti is failo(F), pademostruoti Trijų taisyklę (R) ar pademonstruoti kaip klases Zmogus objektas, negali buti sukurtas(Z)? T/G/F/R/Z? " << endl;
                cin >> gen;

                // Tikriname ar irasytas gen yra T, G arba F
                if (gen != "T" && gen != "G" && gen != "F" && gen != "R" && gen != "Z") {
                    throw invalid_argument("Neteisinga ivestis. Iveskite T, G , F, R arba Z");
                }

                if (gen == "Z") {

                    /*Zmogus zmogelis;

                    zmogelis.setVar("Zmogvardas");
                    zmogelis.setPav("Pavardzmogas");
                    string a = zmogelis.getVar();
                    string b = zmogelis.getPav();
                    std::cout << a << " " << b;*/

                    Studentas zmogeliukas;

                    zmogeliukas.setVar("Zmogvardas");
                    zmogeliukas.setPav("Pavardzmogas");
                    cout << zmogeliukas.getPav() << endl;

                    string asdf;
                    cout << "Iveskite bet ka noredami baigti\n";
                    cin >> asdf;
                    return 0;
                }

                else if (gen == "R") {

                    Studentas s1;
                    s1.setEgz(100);
                    std::cout << "Pirmo studento įvertinimas: " << s1.getEgz() << endl;
                    auto s2{ s1 }; // Copy constructor
                    std::cout << "Antro studento įvertinimas: " << s2.getEgz() << endl;
                    Studentas s3;
                    s3.setEgz(92);
                    std::cout << "Trečio studento įvertinimas: " << s3.getEgz() << endl;
                    s3 = s2; // Copy 
                    std::cout << "Trečio studento įvertinimas: " << s3.getEgz() << endl;

                    string asdf;
                    cout << "Iveskite bet ka noredami baigti\n";
                    cin >> asdf;
                    return 0;
                } // Destruktorius iškviečiamas čia



                else if (gen == "T") {
                    std::cout << "Kiek studentu yra kurse? ";
                    cin >> stud_sk;
                    list<Studentas> grupe = ivesk<list<Studentas>>(stud_sk, gen);
                    std::cout << "Grupės objekto saugojimo atmintyje adresas: " << &grupe << endl;
                    for (auto& student : grupe) { std::cout << "Studento objekto saugojimo atmintyje adresas: " << &student << endl; }

                    // Tikriname ar pasirinkta tarp V ir M
                    while (ats != "M" && ats != "V") {
                        std::cout << "Norite medianos ar vidurkio? M/V " << endl;
                        cin >> ats;

                        if (ats != "M" && ats != "V") {
                            cerr << "Klaida: Neteisinga ivestis. Pasirinkite M arba V." << endl;

                        }
                    }

                    std::string rus_index;
                    rus_index = "P";
                    pal_pav_list(grupe, rus_index);
                    isvedimas(grupe, gen, ats);
                    string asdf;
                    cout << "Iveskite bet ka noredami baigti\n";
                    cin >> asdf;
                    return 0;

                }

                else if (gen == "G")
                {

                    int stud_gen_sk, stud_gen_nd;
                    std::cout << "Kiek studentu bus jusu generuojamame faile?\n";
                    cin >> stud_gen_sk;
                    std::cout << "Kiek tarpiniu namu darbu pazymiu vesite kiekviem studentui?\n";
                    cin >> stud_gen_nd;
                    for (int i = 0; i < 5; i++) {
                        auto Generavimo_start = chrono::high_resolution_clock::now();
                        list<Studentas> studentai;
                        gen_failas(stud_gen_sk, stud_gen_nd);
                        auto Generavimo_end = chrono::high_resolution_clock::now();
                        chrono::duration<double> Generavimo_laikas = Generavimo_end - Generavimo_start;
                        std::cout << to_string(stud_gen_sk) << " irasu generavimas uztruko: " << Generavimo_laikas.count() << " s;" << endl;


                        std::cout << "Duomenys irasyti i faila 'Kursiokai" << stud_gen_sk << ".txt'" << endl;
                    }
                    string asdf;
                    cout << "Iveskite bet ka noredami baigti\n";
                    cin >> asdf;
                    return 0;

                }


                else if (gen == "F") {
                    string failas;
                    system("dir *.txt");
                    std::cout << "Iveskite failo, kuri norite nuskaityti pavadinima (formatas: pavadinimas.txt): ";
                    cin >> failas;

                    std::cout << "Pagal ka noresite rusiuoti rezultatus: P - pavardes, V - vardus, G - galutini bala?\n";
                    cin >> rus_index;

                    int kiekis = kiek_sk(failas);

                    for (int i = 0; i < 5; i++) {
                        std::cout << endl << endl;
                        std::cout << i + 1 << " nuskaitymas" << endl;

                        auto Nuskaitymo_start = chrono::high_resolution_clock::now();
                        nuskaitymas(failas, grupe);
                        auto Nuskaitymo_end = chrono::high_resolution_clock::now();
                        chrono::duration<double> Nuskaitymo_laikas = Nuskaitymo_end - Nuskaitymo_start;
                        std::cout << kiekis << " irasu nuskaitymas uztruko: " << Nuskaitymo_laikas.count() << " s;" << endl;


                        auto Rusiavimas_start = chrono::high_resolution_clock::now();
                        pal_pav_list(grupe, rus_index);
                        auto Rusiavimas_end = chrono::high_resolution_clock::now();
                        chrono::duration<double> Rusiavimas_laikas = Rusiavimas_end - Rusiavimas_start;
                        std::cout << kiekis << " irasu rusiavimas pagal " << rus_index << " uztruko: " << Rusiavimas_laikas.count() << " s;" << endl;



                        auto Padalinimo_start = chrono::high_resolution_clock::now();
                        list<Studentas> vargsiukai;
                        list<Studentas> kietiakai;
                        padalinimas(grupe, vargsiukai);
                        kietiakai = grupe;
                        auto Padalinimo_end = chrono::high_resolution_clock::now();
                        chrono::duration<double> Padalinimo_laikas = Padalinimo_end - Padalinimo_start;
                        std::cout << kiekis << " irasu surusiavimas i dvi grupes uztruko: " << Padalinimo_laikas.count() << " s;" << endl;

                        pal_pav_list(kietiakai, rus_index);
                        pal_pav_list(vargsiukai, rus_index);

                        auto Kietiaku_sp_start = chrono::high_resolution_clock::now();
                        padalinto_sapuzdinimas(kietiakai, "kietiakai.txt");
                        auto Kietiaku_sp_end = chrono::high_resolution_clock::now();
                        chrono::duration<double> Kietiaku_sp_laikas = Kietiaku_sp_end - Kietiaku_sp_start;
                        std::cout << kiekis << " irasu kietiaku irasymas i faila uztruko: " << Kietiaku_sp_laikas.count() << " s;" << endl;


                        auto Vargsiuku_sp_start = chrono::high_resolution_clock::now();
                        padalinto_sapuzdinimas(vargsiukai, "vargsiukai.txt");
                        auto Vargsiuku_sp_end = chrono::high_resolution_clock::now();
                        chrono::duration<double> Vargsiuku_sp_laikas = Vargsiuku_sp_end - Vargsiuku_sp_start;
                        std::cout << kiekis << " irasu vargsiuku irasymas i faila uztruko: " << Vargsiuku_sp_laikas.count() << " s;" << endl;
                        double visas_laikas = Nuskaitymo_laikas.count() + Rusiavimas_laikas.count() + Padalinimo_laikas.count() + Kietiaku_sp_laikas.count() + Vargsiuku_sp_laikas.count();
                        std::cout << kiekis << " irasu testo laikas: " << visas_laikas << " s;" << endl;

                        grupe.clear();

                    }
                    //Isvedame duomenis
                    //isvedimas_list(grupe, gen, ats, rus_index);
                }

                break; // Iseiname is ciklo, jei nesugavome nieko su "try"
            }
            // Jei gauname "invalid_argument" tada suveikia si funkcija ir pasako, kad buvo padaryta klaida
            catch (invalid_argument& e) {
                cerr << "Klaida: " << e.what() << endl;
            }
        }
        string asdf;
        cout << "Iveskite bet ka noredami baigti\n";
        cin >> asdf;
      
        return 0;

    }

}
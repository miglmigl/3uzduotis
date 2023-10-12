#include "mylib.h"

void padalinto_sapuzdinimas(vector<int>& studentai, string&& failo_pav) {
   ofstream out(failo_pav);
        for (int a : studentai) {
            out << "Vardas" << a << " Pavarde" << a << "\n";
        }
        out.close();
}



        /// Pazymiu ir egzamino rezultato generavimo funkcija

void gen_failas(int stud_gen_sk, int stud_gen_nd)
{
    int laikinas;
    // Kad kiekviena karta leidziant koda butu skirtingi sakaiciai generuojami
    srand(static_cast<unsigned>(time(nullptr)));

    ofstream out ("Kursiokai"+to_string(stud_gen_sk)+".txt");
    out<< setw(20) << "Vardas"<< setw(20) << "Pavarde";
    for (int m=1; m <= stud_gen_nd; m++)
    {
         out<< setw(7) << "ND"+to_string(m);
    }
   out << setw(10) << "Egz.";
   out << setw(15) << "Galutinis\n\n";

    vector<int> kietiakai;
    vector<int> vargsiukai;

    for (int i = 1; i <= stud_gen_sk; i++)
    {
        out << setw(20) << "Vardas" + to_string(i) << setw(20) << "Pavarde" + to_string(i);
        double suma = 0;
        for (int j = 0; j < stud_gen_nd; j++) {
            laikinas=(rand() % 10) + 1; // Dedam pazymi i vektoriu (Cia ima atsitiktinius sveikus sakicius daliname is 10, imame liekana (ji bus 0-9, pridedame 1) )
            out << setw(7) << laikinas;
            suma += laikinas;
        }


        double galutinis = 0;
        laikinas = (rand() % 10) + 1;
        out << setw(7) << laikinas;
        galutinis = 0.4*(suma/stud_gen_nd) + 0.6*laikinas;
        if (galutinis >= 5)
        {
            kietiakai.push_back(i);
        }
        else
        {
            vargsiukai.push_back(i);
        }
        out << setw(15) << fixed << setprecision(2) << galutinis << endl;
    }
    out.close();
    cout << "Duomenys irasyti i faila 'Kursiokai"<< stud_gen_sk <<".txt'";
        // Spauzdinami kietiakai ir vargsiukai i failus
    padalinto_sapuzdinimas(kietiakai, "kietiakai.txt");
    padalinto_sapuzdinimas(vargsiukai, "vargsiukai.txt");
}






            // Vidurkio ir medianos skaiciavimo funkcija

void skaiciavimas(vector<studentas> &grupe, studentas &temp)
{

    // Skaiciuojame vidurki
    double suma = 0;
    for (int i = 0; i < temp.paz.size(); i++)
        {
            suma += temp.paz[i];
        }

    temp.vid = 0.4 * (suma / temp.paz.size()) + 0.6 * temp.egz;

    // Sukuriame vektoriu su visais gautais pazymiais ir egzaminu
    vector<int> visipaz = temp.paz; // vektorius saugos int tipo objektus, vadinsis visipaz, ji priliginam temp.paz (reiskaisi cia desim pazymius)
    visipaz.push_back(temp.egz);


    //Skaiciuojame mediana
    double med = 0.0;
    sort(visipaz.begin(), visipaz.end());
    if (visipaz.size() % 2 == 0)
        {
            med = (visipaz[(visipaz.size() / 2) - 1] + visipaz[visipaz.size() / 2]) / 2.0;
        }
    else
        {
            med = visipaz[visipaz.size() / 2];
        }

    temp.med = med;

    grupe.push_back(temp);
}




        //Rikiavimo pagal pavardes funkcija

bool palyginimas(studentas &a, studentas &b)
    {
    return a.pav < b.pav;
    }
// Pavardziu lyginimo funkcija
void pal_pav(vector<studentas> &grupe) {
    sort(grupe.begin(), grupe.end(), palyginimas);
}




// Iskvieciama funkcija "ivesk", kuri kaip argumentus ima "stud_sk" ir "gen" kintamuosius
//ir grazina vektoriu sudaryta is objektu "studentas"

vector<studentas> ivesk(int stud_sk, string gen) {
    vector<studentas> grupe;

// Vykdomos visos galimos ivestys
if(gen =="T")
    {
        // For ciklas vykdomas tiek kartu, kiek yra ivedama studentu
    for (int j = 0; j < stud_sk; j++)
        {
        studentas temp;
        cout << "Iveskite varda ir pavarde: ";
        cin >> temp.var >> temp.pav;


        if (gen == "T")
            {
            cout << "Iveskite namu darbu pazymius (baigti su dvigubu Enter): ";
            int num;
            while (cin >> num)
                {
                    temp.paz.push_back(num); // pridedame ivesta pazimi i vektoriu, kuriame bus irasomi visi pazymiai
                    if (cin.get() == '\n' && temp.paz.size() > 0 && cin.peek() == '\n') // Tikrinama ar baigiama ivestis (Enter paspaudzaima 2 kartus)
                        {
                            cin.ignore(); // Su sia eilute ignoruojami ivesti naujos eilutes simboliai (Enter)
                            break;
                        }
                }
            cout << "Iveskite egzamino rezultata: ";
            cin >> temp.egz;
            }


        skaiciavimas(grupe, temp); // Iskvieciame vidurkio ir medianos skaiciavimo funkcija
        }
    }



// Vykdoma si dalis, jei pasirenkama duomenis skaityti is failo (F)
else if (gen == "F")
    {
        system("dir *.txt");
    string failo_pav;
    cout << "Iveskite failo, kuri norite nuskaityti pavadinima (formatas: pavadinimas.txt)";
    cin >> failo_pav;
    ifstream in(failo_pav); // Atidaromas ivesties failas

    // Praleidziame pirma eilute su stulpeliu pavadinimais
    string pavadinimas;
    getline(in, pavadinimas);


    int raidziu_sk = 0;
    //Susirandame kiek raidziu yra pirmoje eiluteje
    for (char ch : pavadinimas)
    {
        if (isalpha(ch))
            {
                raidziu_sk++;
            }
    }

    double paz_sk;
    // Atimame "Vardas", "Pavarde", "Egz" raides ir padalinam is 2, nes "ND" yra 2 raides
    //Taip suskaiciuojame kiek tarpiniu namu darbu pazymiu yra vienam studentui
    paz_sk =(raidziu_sk -6-7-3)/2;


    studentas temp;
    int laik_kint;
    while (in >> temp.var >> temp.pav)
        {
            //Istrina buvusias temp.paz vertes
            temp.paz.clear();
            //Nuskaitome is eiles einancius namu darbu pazymius
            for (int i = 0; i < paz_sk; i++)
                {
                in >> laik_kint;
                temp.paz.push_back(laik_kint);
                }
            //Nuskaitome egzmaino rezultata
            in >> temp.egz;
            //Iskvieciame vidurkio ir medijanos sakiciavimo funkcija
            skaiciavimas(grupe, temp);
        }
    in.close();
    }
    return grupe;
}




        //Isvedimo funkcija

void isvedimas(vector<studentas> &grupe, string gen, string ats) {
    if (gen == "T" /*|| gen == "G"*/)
        {
            // Rusiuojame pagal pavardes
            pal_pav(grupe);

        cout << left << setw(20) << "Pavarde" << setw(20) << "Vardas" << setw(20);
        if (ats == "M") {
                cout << "Galutinis (Med.)" << endl;
                cout << "--------------------------------------------------------\n";
                for (auto &a : grupe) {
                    cout << left << setw(20) << a.pav << setw(20) << a.var << setw(20) << fixed << setprecision(2) << a.med << endl;
                    }
                        } else if (ats == "V") {
            cout << "Galutinis (Vid.)" << endl;
            cout << "--------------------------------------------------------\n";
            // Imame po elementa is "grupe" vektoriaus (po studenta)
            for (auto &a : grupe) {
                cout << left << setw(20) << a.pav << setw(20) << a.var << setw(20) << fixed << setprecision(2) << a.vid << endl;
            }
        }
        } else if (gen == "F") {
         ofstream out ("rezultatai.txt");
        out << left << setw(20) << "Pavarde" << setw(20) << "Vardas" << setw(20) << "Galutinis (Vid.)" << setw(20) << "Galutinis (Med.)" << endl;
        out << "-----------------------------------------------------------------------\n";

        // Rusiuojame pagal pavardes
        pal_pav(grupe);

        for (auto &a : grupe) {

            out << left << setw(20) << a.pav << setw(20) << a.var << setw(20) << fixed << setprecision(2) << a.vid << setw(20) << fixed << setprecision(2) << a.med << endl;
        }
        out.close();
        cout << "Isvesti duomenys irasyti i faila 'rezultatai.txt' "<< endl;
    }
}




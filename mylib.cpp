#include "mylib.h"


void genPazEgz(studentas &student)
{
    // Kad kiekviena karta leidziant koda butu skirtingi sakiciai generuojami
    srand(static_cast<unsigned>(time(nullptr)));

    int n;
    cout << "Kiek tarpiniu namu darbu pazymiu vesate siam studentui? " << endl;
    cin >> n;
    // Generuojame pazymius (1-10)
    cout << "Pazymiai:";
    for (int i = 0; i < n; i++)
        {
            student.paz.push_back((rand() % 10) + 1);
            cout << setw(3) << student.paz[i];
        }
    cout << endl;

    // Generuojame egz reiksme (1-10)
    student.egz = (rand() % 10) + 1;
    cout << "Egzamino rezultatas: " << student.egz << endl;
}





void skaiciavimas(vector<studentas> &grupe, studentas &temp)
{
    double suma = 0;
    for (int i = 0; i < temp.paz.size(); i++)
        {
            suma += temp.paz[i];
        }

    temp.vid = 0.4 * (suma / temp.paz.size()) + 0.6 * temp.egz;

    vector<int> visipaz = temp.paz;
    visipaz.push_back(temp.egz);

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





bool palyginimas(studentas &a, studentas &b) {
    return a.pav < b.pav;
}
// Pavardziu lyginimo funkcija
void pal_pav(vector<studentas> &grupe) {
    sort(grupe.begin(), grupe.end(), palyginimas);
}





vector<studentas> ivesk(int stud_sk, string gen) {
    vector<studentas> grupe;
if(gen =="T" || gen == "G")
    {
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
                    temp.paz.push_back(num);
                    if (cin.get() == '\n' && temp.paz.size() > 0 && cin.peek() == '\n')
                        {
                            cin.ignore();
                            break;
                        }
                }
            cout << "Iveskite egzamino rezultata: ";
            cin >> temp.egz;
            }

        else if (gen == "G")
            {
            genPazEgz(temp);
            }

        skaiciavimas(grupe, temp);
        }
    }


else if (gen == "F")
    {
    ifstream in("kursiokai.txt");

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
            //Nuskaitome 5 is eiles einancius namu darbu pazymius
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





void isvedimas(vector<studentas> &grupe, string gen, string ats) {
    if (gen == "T" || gen == "G")
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
            for (auto &a : grupe) {
                cout << left << setw(20) << a.pav << setw(20) << a.var << setw(20) << fixed << setprecision(2) << a.vid << endl;
            }
        } else {
            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nNeteisinga ivestis" << endl;
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




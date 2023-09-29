#include "mylib.h"

void genPazEgz(studentas &student);


vector<studentas> ivesk(int stud_sk, string gen) {
    vector<studentas> grupe;

    for (int j = 0; j < stud_sk; j++) {
        studentas temp;
        cout << "Iveskite varda ir pavarde: ";
        cin >> temp.var >> temp.pav;


        if (gen == "T") {
 cout << "Iveskite namu darbu pazymius (baigti su dvigubu Enter): ";
    int num;
    while (cin >> num) {
        temp.paz.push_back(num);
        if (cin.get() == '\n' && temp.paz.size() > 0 && cin.peek() == '\n'){
        cin.ignore();
                break;
           }}
        cout << "Iveskite egzamino rezultata: ";
        cin >> temp.egz;
        }

        else if (gen == "N"){
            genPazEgz(temp);}



        vector<int> visipaz = temp.paz;
        visipaz.push_back(temp.egz);

        double suma = 0;
        for (int i = 0; i < visipaz.size() - 1; i++) {
            suma = visipaz[i] + suma;}

        temp.vid = 0.4 * (suma) / (visipaz.size() - 1) + 0.6 * temp.egz;

        sort(visipaz.begin(), visipaz.end());
        if (visipaz.size() % 2 == 0) {
            temp.med = (visipaz[(visipaz.size() / 2) - 1] + visipaz[visipaz.size() / 2]) / 2.0;}
         else {
            temp.med = visipaz[visipaz.size() / 2];}
        grupe.push_back(temp);
    }
    return grupe;
}

void genPazEgz(studentas &student) {
    // Kad kiekviena karta leidziant koda butu skirtingi sakiciai generuojami
    srand(static_cast<unsigned>(time(nullptr)));

    int n;
    cout << "Kiek tarpiniu namu darbu pazymiu vesite siam studentui? "<<endl;
    cin >> n;
    // Generuojame pazymius (1-10)
    cout << "Pazymiai:" << endl;
    for (int i = 0; i < n; i++) {
        student.paz.push_back((rand() % 10) + 1); // Random number between 1 and 10
        cout << student.paz[i] << endl;
    }
    cout << endl;

    //Generuojame egz reiksme (1-10)
    student.egz = (rand() % 10) + 1;
    cout << "Egzamino rezultatas: " << endl << student.egz << endl;
}

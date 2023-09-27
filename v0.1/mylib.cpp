#include "mylib.h"

vector<studentas> ivesk() {
    vector<studentas> grupe;

    for (int j = 0; j < 2; j++) {
        studentas temp;
        cout << "Iveskite varda ir pavarde: ";
        cin >> temp.var >> temp.pav;

        cout << "Iveskite namu darbu tarpinius rezultatus: ";
        int num;
        int count = 0;

        while (count < 5 && cin >> num) {
            temp.paz.push_back(num);
            count++;
        }

        cout << "Iveskite egzamino rezultata: ";
        cin >> temp.egz;


        double suma = 0;
        for (int i = 0; i < 5; i++) {
            suma = temp.paz[i] + suma;
        }
        temp.rez = (suma + temp.egz) / 6;

        grupe.push_back(temp);
    }

    return grupe;
}


#include "mylib.h"

vector<studentas> ivesk(int stud_sk, int n) {
    vector<studentas> grupe;

    for (int j = 0; j < stud_sk; j++) {
        studentas temp;
        cout << "Iveskite varda ir pavarde: ";
        cin >> temp.var >> temp.pav;

        cout << "Iveskite namu darbu tarpinius rezultatus: ";
        int num;
        int count = 0;

        while (count < n && cin >> num) {
            temp.paz.push_back(num);
            count++;
        }

        cout << "Iveskite egzamino rezultata: ";
        cin >> temp.egz;

        vector<int> visipaz = temp.paz;
        visipaz.push_back(temp.egz);

        double suma = 0;
        for (int i = 0; i < visipaz.size()-1; i++) {
            suma = visipaz[i] + suma;
                }
        temp.vid = 0.4*(suma)/(visipaz.size()-1)+0.6*temp.egz;

        sort(visipaz.begin(), visipaz.end());

        if (visipaz.size() % 2 == 0) {
            temp.med = (visipaz[(visipaz.size() / 2) - 1] + visipaz[visipaz.size() / 2]) / 2.0;
        } else {
            temp.med = visipaz[visipaz.size() / 2];
        }

        grupe.push_back(temp);
    }

    return grupe;
}


#include "mylib.h"

vector<studentas> ivesk(int stud_sk) {
    vector<studentas> grupe;

    for (int j = 0; j < stud_sk; j++) {
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

                // Calculate the median for both paz and egz
        vector<int> visipaz = temp.paz; // Create a vector with paz values
        visipaz.push_back(temp.egz); // Add the egz value

        double suma = 0;
        for (int i = 0; i < visipaz.size(); i++) {
            suma = visipaz[i] + suma;
                }
        temp.vid = suma / visipaz.size();

        sort(visipaz.begin(), visipaz.end());

        //mediana

        if (visipaz.size() % 2 == 0) {
            temp.med = (visipaz[(visipaz.size() / 2) - 1] + visipaz[visipaz.size() / 2]) / 2.0;
        } else {
            temp.med = visipaz[visipaz.size() / 2];
        }

        grupe.push_back(temp);
    }

    return grupe;
}


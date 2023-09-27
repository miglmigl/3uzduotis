#include "mylib.h"

int main() {
    vector<studentas> grupe = ivesk();


    cout << left << setw(20) << "Pavarde" << setw(20) << "Vardas" << setw(20) << "Galutinis (Vid.)" << endl;
    cout<<"--------------------------------------------------------\n";

    for (auto &a : grupe) {
        cout << left << setw(20) << a.pav << setw(20) << a.var << setw(20) << fixed << setprecision(2) << a.rez << endl;
    }

    return 0;
}




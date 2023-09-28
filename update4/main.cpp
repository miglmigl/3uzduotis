#include "mylib.h"

int main()
{
    //int n;
    //cout << "Kiek tarpiniu namu darbu pazymiu vesite vienam studentui? "<<endl;
    //cin >> n;
    int stud_sk;
    cout << "Kiek studentu yra kurse? ";
    cin >> stud_sk;
    vector<studentas> grupe = ivesk(stud_sk);//, n);
    string ats;



    cout<< "Noritet medianos ar vidurkio? M/V "<< endl;
    cin>>ats;

    cout << left << setw(20) << "Pavarde" << setw(20) << "Vardas" << setw(20);
    if (ats == "M")
    {
        cout << "Galutinis (Med.)" <<endl;
        cout<<"--------------------------------------------------------\n";
        for (auto &a : grupe)
        {
            cout << left << setw(20) << a.pav << setw(20) << a.var << setw(20) << fixed << setprecision(2) << a.med << endl;
        }


    }
    else if (ats == "V")
    {
        cout<< "Galutinis (Vid.)" << endl;
        cout<<"--------------------------------------------------------\n";
        for (auto &a : grupe)
        {
            cout << left << setw(20) << a.pav << setw(20) << a.var << setw(20) << fixed << setprecision(2) << a.vid << endl;
        }

    }
    else
    {
        cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nNeteisinga ivestis"<<endl;
        return 0;
    }


    return 0;
}




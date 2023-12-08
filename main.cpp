#include <stdio.h>
#include <math.h>
#include <iostream>
#include <string>
#include "trace.h"
#include "source.h"
#include "circuits.h"
using namespace std;

int main(){
    int choix;
    choix = 10;
    source *s;
    while(choix > 0){
        system("clear");
        cout << "Choisissez une source : \n" << endl;
        cout << "1. Sinusoïdale" << endl;
        cout << "2. Triangulaire" << endl;
        cout << "3. Créneau" << endl;
        cout << "4. Rectangulaire" << endl;
        cout << "5. Échelon" << endl;
        cout << "0. Quitter" << endl;
        cin >> choix;

        switch (choix)
        {
        case 1:
            s = new source_sin();
            break;

        case 2:
            s = new source_triangulaire();
            break;

        case 3:
            s = new creneau();
            break;

        case 4:
            s = new source_rectangulaire();
            break;

        case 5:
            s = new echelon();
            break;

        case 0:
            delete(s);
            return 0;

        default:
            choix=10;
            cout << "Choix invalide" << endl;
            break;
        }
        choix += -5;
    }

    choix =10;
    circuits *circuit;
    while (choix>0){
        system("clear");
        cout << "Choisissez un type de circuit : \n" << endl;
        cout << "1. Type A" << endl;
        cout << "2. Type B" << endl;
        cout << "3. Type C" << endl;
        cout << "4. Type D" << endl;
        cout << "0. Quitter" << endl;
        cin>>choix;

    switch (choix)
    {
        float R;
        float C;
        float L;

    case 1 :
        cout << "valeur R"<<endl;
        cin>> R;
        cout << "valeur C"<<endl;
        cin>> C;
        circuit = new circuit_A(s,R,C);
        break;
    case 2 :
        float R1;
        float R2;
        float VBE;
        cout << "valeur R1"<<endl;
        cin>> R1;
        cout << "valeur R2"<<endl;
        cin>> R2;
        cout << "valeur C"<<endl;
        cin>> C;
        circuit = new circuit_B(s, R1, R2, C);
        break;
    case 3 :
        cout << "valeur R"<<endl;
        cin>> R;
        cout << "valeur C"<<endl;
        cin>> C;
        cout << "valeur L"<<endl;
        cin>> L;
        circuit = new circuit_C(s, R, C, L);
        break;
    case 4 :
        cout << "valeur R"<<endl;
        cin>> R;
        cout << "valeur C"<<endl;
        cin>> C;
        cout << "valeur L"<<endl;
        cin>> L;
        circuit = new circuit_D(s, R, C, L);
        break;
    case 0 :
        return 0;

    default :
        choix = 10;
        break;
    }
    choix += -4;

    }
    double npas = 1000000;
    double tfin = 5e-7;
    circuit->resolution(npas, tfin);
    cout<<"Simulation terminee"<<endl;
    delete(s);
    delete(circuit);
    return 0;
}
//Ce code ne change pas par rapport à la dernière partie.


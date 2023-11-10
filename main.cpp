#include <stdio.h>
#include <math.h>
#include <iostream>
#include <string>
#include "source.h"
#include "trace.h"
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
            s = new source_sin(100, 2 ,0);
            break;
        
        case 2:
            s = new source_triangulaire(1, 1 , 1);
            break;

        case 3:
            s = new creneau(1, 1, 1,1);
            break;

        case 4:
            s = new source_rectangulaire(1, 1, 3);
            break;

        case 5:
            s = new echelon(1, 1);
            break;
        
        case 0:
            delete(s);
            return 0;

        default:
            cout << "Choix invalide" << endl;
            break;
        }
        choix = -1;
    }
    
    choix = 10;
    while(choix > 0){
        system("clear");
        cout << "Choisissez une action : \n" << endl;
        cout << "1. Tracer" << endl;
        cout << "0. Quitter" << endl;
        cin >> choix;
        switch (choix)
        {
        case 1:
            trace(s);
            break;
    
        case 0:
            break;
        default:
            break;
        }
}
    choix =10;

    float R1;
    float R2;
    float C;
    float VBE;
    circuits *circuit;
    while (choix>0){
        cout << "Choisissez un type de circuit : \n" << endl;
        cout << "1. Type A" << endl;
        cout << "2. Type B" << endl;
        cout << "0. Quitter" << endl;
        cin>>choix;
    
    switch (choix)
    {
    case 1 :
        cout << "valeur R1"<<endl;
        cin>> R1;
        cout << "valeur C"<<endl;
        cin>> C;
        circuit = new circuit_A(s,R1,C);
        break;
    case 2 :
        cout << "valeur R1"<<endl;
        cin>> R1;
        cout << "valeur R2"<<endl;
        cin>> R2;
        cout << "valeur C"<<endl;
        cin>> C;
        cout << "valeur VBE"<<endl;
        cin>> VBE;
        circuit = new circuit_B(s, R1, R2, C);
        break;
    default : 
        break;
    }
    }
    int npas = 10000;
    float tfin = 15;
    circuit->resolution(npas, tfin);
       
    delete(s);
    return 0;
}

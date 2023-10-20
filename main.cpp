#include <stdio.h>
#include <math.h>
#include <iostream>
#include <string>
#include "source.h"
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
            //s = new source_triangulaire(1, 1, 1);
            break;

        case 3:
            //s = new creneau(1, 1, 1,1);
            break;

        case 4:
            //s = new source_rectangulaire(1, 1, 1);
            break;

        case 5:
            //s = new echelon(1, 1);
            break;
        
        case 0:
            delete(s);
            return 0;

        default:
            cout << "Choix invalide" << endl;
            break;
        }
        string x;
        cout<<endl;
        float v;
        v = s->ve(0);
        cout<<v<<endl;
        cin>>x;

    }
    delete(s);
    return 0;
}
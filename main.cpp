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
        system("cls");
        cout << "Choisissez une source : \n" << endl;
        cout << "1. Sinusoïdale \n" << endl;
        cout << "2. Triangulaire \n" << endl;
        cout << "3. Créneau \n" << endl;
        cout << "4. Rectangulaire \n" << endl;
        cout << "5. Échelon \n" << endl;
        cout << "0. Quitter \n" << endl;
        cin >> choix;

        switch (choix)
        {
        case 1:
            s = new source_sin(1, 1, 1);
            break;
        
        case 2:
            s = new source_triangulaire(1, 1, 1);
            break;

        case 3:
            s = new creneau(1, 1, 1);
            break;

        case 4:
            s = new source_rectangulaire(1, 1, 1);
            break;

        case 5:
            s = new source_echelon(1, 1, 1);
            break;
        
        case 0:
            return 0;

        default:
            cout << "Choix invalide" << endl;
            break;
        }

    }
    return 0;
}
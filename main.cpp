#include <stdio.h>
#include <math.h>
#include <iostream>
#include <string>
#include "source.h"
using namespace std;

int main(){
    int choix;
    choix = 10;
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
        case /* constant-expression */:
            /* code */
            break;
        
        default:
            break;
        }
    }
}
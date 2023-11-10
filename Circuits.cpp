#include <stdio.h>
#include <math.h>
#include <iostream>
#include <string>
#include "source.h"
#include "Circuits.h"
using namespace std;

circuits :: circuits(int n){
    nb_composants=n;
    cout << "nombre de composants dans le circuit"<<endl;
    cin >> n;
};

composants::composants(float C, float L, float R, float D){
    cout<<"capacité"<<endl;
    cin >> C;
    condensateur= C;
    cout<<"inductance"<<endl;
    cin >> L;
    inductance=L;
    cout<<"resistance"<<endl;
    cin >> R;
    resistance=R;
    diode=D;
    
};

grandeurs::grandeurs(float v, float i){
    tension=v;
    courant=i;
};

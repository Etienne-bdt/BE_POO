#include <iostream>
#include <string>
#include <stdio.h>
#include <math.h>


class circuits {
    public :
        int nb_composants;
        circuits(int n);
};

class composants : public circuits {
    public : 
        float condensateur; 
        float inductance;
        float resistance;
        float diode;
    public : 
        composants(float C, float L, float R, float D);
};

class grandeurs : public circuits {
    protected : 
        float tension;
        float courant;
        
    public : 
        grandeurs(float v, float i);
};

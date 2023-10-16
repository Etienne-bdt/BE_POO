#include <iostream>
#include <string>
#include <stdio.h>
#include <math.h>

using namespace std;

class source {
    public:
        source();
        virtual float ve(float t){
            return;
        };    
    protected:
        float tension;
        float amplitude;
        float phase;
};

class source_periodique: source {
    
    protected:
        float periode;
};

class source_aperiodique: source {
    
    protected:
        float duree;
};

class source_sin: source_periodique {
    public:
        source_sin(float t, float a, float p);
        float ve(float t);
    
};

class source_triangulaire : source_periodique{
    public:
        source_triangulaire(float t, float a, float p);
        float ve(float t);
};

class creneau : source_periodique{
    public:
        creneau(float t, float a, float p);
        float ve(float t);
    protected:
        float largeur;
};

class source_rectangulaire: source_aperiodique{
    public:
        source_rectangulaire(float t, float a, float p);
        float ve(float t);
    protected:
        float rapport_cyclique;
};

class echelon: source_aperiodique{
    public:
        echelon(float t, float a, float p);
        float ve(float t);
};
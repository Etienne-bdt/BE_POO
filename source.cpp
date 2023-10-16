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

class source_periodique: public source {
    
    protected:
        float periode;
};

class source_aperiodique: public source {
    
    protected:
        float duree;
};

class source_sin: public source_periodique {
    public:
        source_sin(float t, float a, float p);
        float ve(float t){
            return amplitude*sin(2*M_PI*t/periode + phase);
        };
    
};

class source_triangulaire : public source_periodique{
    public:
        source_triangulaire(float t, float a, float p);
        float ve(float t);
};

class creneau : public source_periodique{
    public:
        creneau(float t, float a, float p);
        float ve(float t);
    protected:
        float largeur;
};

class source_rectangulaire: public source_aperiodique{
    public:
        source_rectangulaire(float t, float a, float p);
        float ve(float t);
    protected:
        float rapport_cyclique;
};

class echelon: public source_aperiodique{
    public:
        echelon(float t, float a, float p);
        float ve(float t){
            if(t > phase){
                return amplitude;
            }
            else{
                return 0;
            }
        };
};
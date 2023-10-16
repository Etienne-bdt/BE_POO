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
        float frequence;
};

class source_aperiodique: public source {
    
    protected:
        float duree;
};

class source_sin: public source_periodique {
    public:
        source_sin(float a, float p, float f);
        float ve(float t){
            return amplitude*sin(2*M_PI*t*frequence + phase);
        };
    
};

class source_triangulaire : public source_periodique{
    public:
        source_triangulaire(float a, float p, float f);
        float ve(float t);
};

class creneau : public source_periodique{
    public:
        creneau(float a, float p, float f, float rc);
        float ve(float t);
    protected:
        float rapport_cyclique;
};

class source_rectangulaire: public source_aperiodique{
    public:
        source_rectangulaire(float a, float p, float d);
        float ve(float t){
            if( t>phase && t<phase+duree){
                return amplitude;
            }
            else{
                return 0;
            }
        };
    private:
        float duree;
};

class echelon: public source_aperiodique{
    public:
        echelon(float a, float p);
        float ve(float t){
            if(t > phase){
                return amplitude;
            }
            else{
                return 0;
            }
        };
};
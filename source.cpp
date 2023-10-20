#include <iostream>
#include <string>
#include <stdio.h>
#include <math.h>
#include "source.h"

using namespace std;

class source {
    public:
        source();
        virtual float ve(float t){
            return 0;
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
        float source_sin :: ve(float t){
            return amplitude*sin(2*M_PI*t*frequence + phase);
        };
    
};

class source_triangulaire : public source_periodique{
    public:
        source_triangulaire(float a, float p, float f);
        float source_triangulaire::ve(float t){
            int k,N;
            for (k==0;k<N;k++){
                if(t>(1/(2*frequence)+k*(1/frequence)) && t<(1/(2*frequence)+k*(1/frequence))){
                    return amplitude*frequence*2*t;
                }
                else {
                    return -amplitude*frequence*2*t;
                }
            }
        }
};

class creneau : public source_periodique{
    protected:
        float rapport_cyclique;
    public:
        creneau(float a, float p, float f, float rc);
        float creneau::ve(float t){
            int k,N;
            for (k==0;k<N;k++){
                if(t>phase+k*(1/frequence) && t<phase+(rapport_cyclique/frequence)+k*(1/frequence)){
                    return amplitude;
                }
            else{
                return 0;
            }
            }
        }  
};

class source_rectangulaire: public source_aperiodique{
    public:
        source_rectangulaire(float a, float p, float d);
        float source_rectangulaire::ve(float t){
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
        float echelon::ve(float t){
            if(t > phase){
                return amplitude;
            }
            else{
                return 0;
            }
        };
};
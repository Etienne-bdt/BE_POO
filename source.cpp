#include <stdio.h>
#include <math.h>
#include <iostream>
#include <string>
#include "source.h"
using namespace std;

float source::ve(float t){
    return 0;
};

source::source(){
    return;
};

source_sin::source_sin(float f, float a, float p){
    amplitude = a;
    phase = p;
    frequence = f;
};

source_periodique::source_periodique(){
    amplitude =0;
    frequence = 0;
    phase = 0;
};

source_periodique::source_periodique(float f, float a, float p){
    amplitude = a;
    phase=p;
    frequence=f;
};

source_aperiodique::source_aperiodique(){
    return;
};

source_rectangulaire::source_rectangulaire(float a, float p, float d){
    amplitude = a;
    phase = p;
    duree = d;
};

source_triangulaire::source_triangulaire(float a,float p, float f){
    amplitude = a;
    phase = p;
    frequence = f;
};

echelon::echelon(float a, float p){
    amplitude =a;
    phase = p;
};

creneau::creneau(float a, float p, float f, float rc){
    amplitude = a;
    frequence = f;
    phase = p;
    rapport_cyclique = rc;
};
float source_sin::ve(float t){
    return amplitude*sin(2*M_PI*t*frequence + phase);
};

float source_rectangulaire::ve(float t){
    if(t>phase && t < phase+duree){
        return amplitude;
    }
    else{
        return 0;
    }
};

float echelon::ve(float t){
    if(t>phase){
        return amplitude;
    }
    else{
        return 0;
    }
};

float creneau::ve(float t){
    float t1 = phase + rapport_cyclique/frequence;
    float tr = fmod(t,1/frequence);

    if(tr>phase && tr<t1){
        return amplitude;
    }
    else{
        return 0;
    }
}

float source_triangulaire::ve(float t){
    float t1 = phase + 1/(2*frequence);
    float t2 = phase + 1/frequence;
    float tr = fmod(t,1/frequence);
    float pr = fmod(phase, 1/frequence);
    float coeff_dir = 2*amplitude/(1/frequence);
    if(tr>phase && tr<t1){
        return coeff_dir*tr + amplitude*2*pr;
    }
    else if(tr>t1&&tr<t2){
        return -coeff_dir*tr + amplitude*2*pr;
    }
    else{
        return 0;
    }
}
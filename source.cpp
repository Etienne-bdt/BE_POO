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

source_sin::source_sin(){
    return;
};

source_periodique::source_periodique(){
    float a,f,p;
    cout<<"Veuillez saisir une amplitude"<<endl;
    cin>>a;
    cout<<"Veuillez saisir une fréquence"<<endl;
    cin>>f;
    cout<<"Veuillez saisir une phase"<<endl;
    cin>>p;
    amplitude =a;
    frequence = f;
    phase = p;
};


source_aperiodique::source_aperiodique(){
    return;
};

source_rectangulaire::source_rectangulaire(){
    float a,p,d;
    cout<<"Veuillez saisir une amplitude"<<endl;
    cin>>a;
    cout<<"Veuillez saisir une phase"<<endl;
    cin>>p;
    cout<<"Veuillez saisir une durée"<<endl;
    cin>>d;
    amplitude = a;
    phase = p;
    duree = d;
};

source_triangulaire::source_triangulaire(){return;
};

echelon::echelon(){
    float a,p;
    cout<<"Veuillez saisir une amplitude"<<endl;
    cin>>a;
    cout<<"Veuillez saisir une phase"<<endl;
    cin>>p;
    amplitude =a;
    phase = p;
};

creneau::creneau(){
    float rc;
    cout<<"Veuillez saisir le rapport cyclique"<<endl;
    cin>>rc;
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

float triangle(float t, float amplitude, float frequence){
    float t1 = 1/(2*frequence);
    float t2 = 1/frequence;
    float tr = fmod(t,1/frequence);
    float coeff_dir = 2*amplitude/(1/frequence);
    if(tr>0 && tr<t1){
        return coeff_dir*(tr);
    }
    else if(tr>t1&&tr<t2){
        return -coeff_dir*(tr) + 2*amplitude;
    }
    else{
        return 0;
    };
}

float source_triangulaire::ve(float t){
    float pt = fmod(phase/(frequence*2*M_PI),1/frequence);
    if(t>=0){
        return triangle(t+pt,amplitude,frequence);
    }
    else{
        return 0;
    };
}

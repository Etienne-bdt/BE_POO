#include <stdio.h>
#include <math.h>
#include <iostream>
#include <string>
#include "source.h"
using namespace std;

double source::ve(double t){
    return 0;
};

source::source(){
    return;
};

source_sin::source_sin(){
    double a;
    cout<<"Veuillez saisir une amplitude"<<endl;
    cin>>a;
    amplitude = a;
};

source_periodique::source_periodique(){
    return;
};


source_aperiodique::source_aperiodique(){
    return;
};

source_rectangulaire::source_rectangulaire(){
    double a,p,d;
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

source_triangulaire::source_triangulaire(){
    double a,f,p;
    cout<<"Veuillez saisir une amplitude"<<endl;
    cin>>a;
    cout<<"Veuillez saisir une fréquence"<<endl;
    cin>>f;
    cout<<"Veuillez saisir une phase"<<endl;
    cin>>p;
    frequence = f;
    phase = p;
    amplitude = a;
};

echelon::echelon(){
    double a,p;
    cout<<"Veuillez saisir une amplitude"<<endl;
    cin>>a;
    cout<<"Veuillez saisir une phase"<<endl;
    cin>>p;
    amplitude =a;
    phase = p;
};

creneau::creneau(){
    double a,f,p,rc;
    cout<<"Veuillez saisir une amplitude"<<endl;
    cin>>a;
    cout<<"Veuillez saisir une fréquence"<<endl;
    cin>>f;
    cout<<"Veuillez saisir une phase"<<endl;
    cin>>p;
    cout<<"Veuillez saisir le rapport cyclique"<<endl;
    cin>>rc;
    amplitude =a;
    frequence = f;
    phase = p;
    rapport_cyclique = rc;

};
double source_sin::ve(double t){
    return amplitude*sin(2*M_PI*t*frequence + phase);
};

double source_rectangulaire::ve(double t){
    if(t>phase && t < phase+duree){
        return amplitude;
    }
    else{
        return 0;
    }
};

double echelon::ve(double t){
    if(t>phase){
        return amplitude;
    }
    else{
        return 0;
    }
};

double creneau::ve(double t){
    double t1 = phase + rapport_cyclique/frequence;
    double tr = fmod(t,1/frequence);
    if(tr>phase && tr<t1){
        return amplitude;
    }
    else{
        return 0;
    }
}

double triangle(double t, double amplitude, double frequence){
    double t1 = 1/(2*frequence);
    double t2 = 1/frequence;
    double tr = fmod(t,1/frequence);
    double coeff_dir = 2*amplitude/(1/frequence);
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

double source_triangulaire::ve(double t){
    double pt = fmod(phase/(frequence*2*M_PI),1/frequence);
    if(t>=0){
        return triangle(t+pt,amplitude,frequence);
    }
    else{
        return 0;
    };
}

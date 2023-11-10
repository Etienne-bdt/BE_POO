#include <stdio.h>
#include <math.h>
#include <iostream>
#include <string>
#include "source.h"
#include "circuits.h"
using namespace std;

circuits::circuits(){
    source *source;
    s = source;
};

circuit_A::circuit_A(source *source, float res, float cond){
    s = source;
    R=res;
    C=cond;
};

float circuit_A::f(float t, float vs){
    return (1/(R*C))*(s->ve(t)-vs);
};

void circuit_A::resolution(int npas, float tfin){
    //Définition de vs et vsf qui correspond à l'état futur, vs(t_n+1) selon la méthode explicite
    float t,vs,vsf = 0;
    float h = tfin/float(npas);
    FILE * fich;
    fich=fopen("vs","wt");
    fprintf(fich,"%f %f %f\n",t,s->ve(t),vs);
    for (t; t < tfin; t+=h)
    {
        vsf = h*f(t,vs)+vs;
        vs = vsf;
        fprintf(fich,"%f %f %f\n",t,s->ve(t),vs);
    }
    fclose(fich);
};

circuit_B::circuit_B(source *source, float res1, float res2, float cond){
    s = source;
    R1 = res1;
    R2 = res2;
    C = cond;
    VBE = 0.6;
};

float circuit_B::f(float t,float vs){
    return ((s->ve(t)-VBE)/(R1*C) - ((1/(R1*C)) + (1/(R2*C)))*vs);
};

void circuit_B::resolution(int npas, float tfin){
//Définition de vs et vsf qui correspond à l'état futur, vs(t_n+1) selon la méthode explicite
    float t,vs,vsf = 0;
    float h = tfin/float(npas);
    FILE * fich;
    fich=fopen("vs","wt");
    fprintf(fich,"%f %f %f\n",t,s->ve(t),vs);
    for (t; t < tfin; t+=h)
    {
        vsf = h*f(t,vs) + vs;
        vs = vsf;
        fprintf(fich,"%f %f %f\n",t,s->ve(t),vs);
    }
    fclose(fich);
};
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

prem_ordre::prem_ordre(){
    float Cond;
    C = Cond;
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
    if (s->ve(t)>VBE){
        return (s->ve(t)-VBE)/(R1*C) - ((1/(R1*C)) + (1/(R2*C)))*vs;
    }else{
        return -vs/(R2*C);
    }
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

void circuits::resolution(int npas, float tfin){
    return;
};
float circuits::f(float t, float vs){
    return 0;
};

void prem_ordre::resolution(int npas, float tfin){
    return;
};

float prem_ordre::f(float t, float vs){
    return 0;
};

sec_ordre::sec_ordre(){
    float Cond;
    C = Cond;
};

void sec_ordre::solver_select(){
    int choix;
    solver = "";
    while(solver == ""){
    system("clear");
    cout << "Veuillez choisir un solver : \n" << endl;
    cout << "1. Euler explicite" << endl;
    cout << "2. Heun" << endl;
    cout << "3. Runge-Kutta 4" << endl;
    cin>>choix;
    switch (choix)
    {
    case 1:
        solver = "Euler explicite";
        break;
    case 2:
        solver = "Heun";
        break;
    case 3:
        solver = "Runge-Kutta 4";
        break;
    default:
        break;
    }
    }
};

circuit_C::circuit_C(source *source,float res, float cap, float bob){
    s= source;
    R = res;
    L = bob;
    C = cap;
    solver_select();
    
};

float circuit_C::F(float t, float vs, float vsp){
    return -(R/L)*vsp + ((vs-s->ve(t))/(L*C));
};

void circuit_C::resolution(int npas, float tfin){
    float t,U,Uf,V,Vf = 0;
    float h = tfin/float(npas);
    FILE * fich;
    fich=fopen("vs","wt");
    fprintf(fich,"%f %f %f\n",t,s->ve(t),U);
    for (t; t < tfin; t+=h)
    {
        Vf = h*F(t,U,V)+V;
        Uf = h*V+U;   
    }
    fclose(fich);
};

circuit_D::circuit_D(source *source,float res, float cap, float bob){
    s = source;
    R = res;
    L = bob;
    C = cap;
    solver_select();
};

float circuit_D::F(float t, float vs, float vsp,float h){
    float vep = (s->ve(t+h)-s->ve(t))/h;
    return -vs/(L*C) + (vep-vsp)/(R*C);
};

void circuit_D::resolution(int npas, float tfin){
    float t,U,Uf,V,Vf = 0;
    float h = tfin/float(npas);
    FILE * fich;
    fich=fopen("vs","wt");
    fprintf(fich,"%f %f %f\n",t,s->ve(t),U);
    for (t; t < tfin; t+=h)
    {
        Vf = h*F(t,U,V,h)+V;
        Uf = h*V+U;
    }
    fclose(fich);
};

#include <stdio.h>
#include <math.h>
#include <iostream>
#include <string>
#include "source.h"
#include "circuits.h"
using namespace std;

//La majorite du code ne change pas ici sauf la fin du fichier

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
    solver = 0;
    while(solver == 0){
    system("clear");
    cout << "Veuillez choisir un solver : \n" << endl;
    cout << "1. Euler explicite" << endl;
    cout << "2. Heun" << endl;
    cout << "3. Runge-Kutta 4" << endl;
    cin>>choix;
    switch (choix)
    {
    case 1:
        //solver Euler explicite
        solver = 1;
        break;
    case 2:
        //solver Heun
        solver = 2;
        break;
    case 3:
        //solver Runge-Kutta 4
        solver = 3;
        break;
    default:
        break;
    }
    }
};

circuit_C::circuit_C(source *source,float res, double cap, double bob){
    s= source;
    R = res;
    L = bob;
    C = cap;
    //Definition des sources et composants ET choix du solver
    solver_select();

};

double circuit_C::F(double t, double vs, double vsp){
    return -(R/L)*vsp + ((s->ve(t)-vs)/(L*C));
};

void circuit_C::resolution(int npas, float tfin){
    double t,U,Uf,V,Vf,Uf1,Uf2 = 0;
    double h = tfin/double(npas);
    FILE * fich;
    fich=fopen("vs","wt");
    U=0;
    V=0;
    fprintf(fich,"%.15f %.15f %.15f\n",t,s->ve(t),U);
    for(double t=0;t<tfin;t+=h){
        Vf = h*F(t,U,V)+V;
        //On utilise l'equation differentielle pour calculer Vf puis, en fonction du solveur (switch) on pondere la valeur de Vf que l'on utilise dans Uf
        switch (solver)
        {
        case 1:
            Uf = h*V+U;
            break;
        case 2:
            Uf = U+ (h/2)*(V+Vf);
            break;
        case 3:
            float Vf2,Vf3 = 0;
            Vf2 = h*F(t+h,U+h*V,Vf)+Vf;
            Vf3 = h*F(t+2*h,U+2*h*V,Vf2)+Vf2;
            Uf = U+ (h/6)*(V+2*Vf+2*Vf2+Vf3);
            break;
        }
        V = Vf;
        U = Uf;
        fprintf(fich,"%.15f %.15f %.15f\n",t,s->ve(t),U);
    }
    fclose(fich);
};

circuit_D::circuit_D(source *source,float res, double cap, double bob){
    s = source;
    R = res;
    L = bob;
    C = cap;
    solver_select();
};

double circuit_D::F(double t, double vs, double vsp, double h){
    double vep = (s->ve(t+h)-s->ve(t))/h;
    return -vs/(L*C) + (vep-vsp)/(R*C);
};

void circuit_D::resolution(int npas, float tfin){
    double t,U,Uf,V,Vf = 0;
    double h = tfin/double(npas);
    FILE * fich;
    fich=fopen("vs","wt");
    U=0;
    V=0;
    //on affiche des valeurs tres faibles d'ou la precision a 15 decimales
    fprintf(fich,"%.15f %.15f %.15f\n",t,s->ve(t),U);
    for(double t=0;t<tfin;t+=h){
        Vf = h*F(t,U,V,h)+V;
        //On utilise l'equation differentielle pour calculer Vf puis, en fonction du solveur (switch) on pondere la valeur de Vf que l'on utilise dans Uf
        switch (solver)
        {
        case 1:
            Uf = h*V+U;
            break;
        case 2:
            Uf = U+ (h/2)*(V+Vf);
            break;
        case 3:
            float Vf2,Vf3 = 0;
            Vf2 = h*F(t+h,U+h*V,Vf,h)+Vf;
            Vf3 = h*F(t+2*h,U+2*h*V,Vf2,h)+Vf2;
            Uf = U+ (h/6)*(V+2*Vf+2*Vf2+Vf3);
            break;
        }
        V = Vf;
        U = Uf;
        fprintf(fich,"%.15f %.15f %.15f\n",t,s->ve(t),U);
    }
    fclose(fich);
};

#include <iostream>
#include <string>
#include <stdio.h>
#include <math.h>
using namespace std;


class circuits {
    public :
        circuits();
        source *s;
        virtual void resolution(int npas, float tfin);
        virtual float f(float t, float vs);
};

class prem_ordre : public circuits{
    protected: float C; 
    public:
        prem_ordre();
        virtual void resolution(int npas, float tfin);
        virtual float f(float t, float vs);
};

class circuit_A : public prem_ordre{
    private: float R;
    public:
        circuit_A(source *source, float res, float cond);
        float f(float t, float vs);
        void resolution(int npas, float tfin);
};

class circuit_B : public prem_ordre{
    private: 
        float R1;
        float R2;
        float VBE;
    public:
        circuit_B(source *source, float res1, float res2, float cond);
        float f(float t, float vs);
        void resolution(int npas, float tfin);
};

class sec_ordre : public circuits{
    protected: 
        float R;
        double C;
        double L;
        int solver;
    public:
        sec_ordre();
        void solver_select();
        
};

class circuit_C : public sec_ordre{
    public : 
        circuit_C(source *source, float res, double cap, double bob);
        void resolution(int npas, float tfin);
        double F(double t, double vs, double vsp);
};

class circuit_D : public sec_ordre{
    public : 
        circuit_D(source *source,float res, double cap, double bob);
        void resolution(int npas, float tfin);
        double F(double t, double vs, double vsp, double h);
};
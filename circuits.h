#include <iostream>
#include <string>
#include <stdio.h>
#include <math.h>


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
    private: 
        float R;
        float C;
        float L;

};
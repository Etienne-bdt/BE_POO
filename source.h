#include <iostream>
#include <string>
#include <stdio.h>
#include <math.h>

class source
{
public:
    source();
    virtual float ve(float t);
};

class source_periodique: public source {
    source_periodique();
};

class source_aperiodique: public source {
    source_aperiodique();
};

class source_sin: public source_periodique {
    public:
        source_sin(float a, float p, float f);
};

class source_triangulaire : public source_periodique{
    public:
        source_triangulaire(float a, float p, float f);
};

class creneau : public source_periodique{
    public:
        creneau(float a, float p, float f, float rc);
    private:
        float rapport_cyclique;
};

class source_rectangulaire: public source_aperiodique{
    public:
        source_rectangulaire(float a, float p, float d);
    private:
        float duree;
};

class echelon: public source_aperiodique{
    public:
        echelon(float a, float p);
};


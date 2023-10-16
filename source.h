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
        source_sin(float t, float a, float p);
};

class source_triangulaire : public source_periodique{
    public:
        source_triangulaire(float t, float a, float p);
};

class creneau : public source_periodique{
    public:
        creneau(float t, float a, float p);
};

class source_rectangulaire: public source_aperiodique{
    public:
        source_rectangulaire(float t, float a, float p);
};

class echelon: public source_aperiodique{
    public:
        echelon(float t, float a, float p);
};


#ifndef SOURCE_H_
#define SOURCE_H_

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
    public:
        source_periodique();
    protected:
        float frequence;
        float amplitude;
        float phase;
};

class source_aperiodique: public source {
public:
    source_aperiodique();
};

class source_sin: public source_periodique {
public:
    source_sin();
    float ve(float t);

};

class source_triangulaire : public source_periodique{
public:
    source_triangulaire();
    float ve(float t);
private:
    float amplitude;
    float phase;
    float frequence;
};

class creneau : public source_periodique{
public:
    creneau();
    float ve(float t);
private:
    float amplitude;
    float phase;
    float frequence;
    float rapport_cyclique;
};

class source_rectangulaire: public source_aperiodique{
public:
    source_rectangulaire();
    float ve(float t);
private:
    float amplitude;
    float phase;
    float duree;
};

class echelon: public source_aperiodique{
public:
    echelon();
    float ve(float t);
private:
    float amplitude;
    float phase;
};

#endif // SOURCE_H


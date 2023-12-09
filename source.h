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
    virtual double ve(double t);
};

class source_periodique: public source {
    public:
        source_periodique();
    protected:
        double frequence;
        double amplitude;
        double phase;
};

class source_aperiodique: public source {
public:
    source_aperiodique();
};

class source_sin: public source_periodique {
public:
    source_sin();
    double ve(double t);

};

class source_triangulaire : public source_periodique{
public:
    source_triangulaire();
    double ve(double t);
private:
    double amplitude;
    double phase;
    double frequence;
};

class creneau : public source_periodique{
public:
    creneau();
    double ve(double t);
private:
    double amplitude;
    double phase;
    double frequence;
    double rapport_cyclique;
};

class source_rectangulaire: public source_aperiodique{
public:
    source_rectangulaire();
    double ve(double t);
private:
    double amplitude;
    double phase;
    double duree;
};

class echelon: public source_aperiodique{
public:
    echelon();
    double ve(double t);
private:
    double amplitude;
    double phase;
};

#endif // SOURCE_H


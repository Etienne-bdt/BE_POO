#include <stdio.h>
#include <math.h>
#include "source.h"
using namespace std;

int trace(source *s){
FILE * fich;
int npas=1000;
float t,dt=1./float(npas);
fich=fopen("ve","wt");
for(int i=0;i<npas+1;i++)
{
t=float(i)*3.141519265*dt;
fprintf(fich,"%f %f \n",t,s->ve(t));
}
fclose(fich);
return 0;
}


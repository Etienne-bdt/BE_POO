#include <stdio.h>
#include <math.h>
using namespace std;

int main()
{
FILE * fich;
int npas=100;
float t,dt=1./float(npas);
fich=fopen("ve","wt");
for(int i=0;i<npas+1;i++)
{
t=float(i)*3.141519265*dt;
fprintf(fich,"%f %f \n",t,sin(2*t));
}
fclose(fich);
return 0;
}


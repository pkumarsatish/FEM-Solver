#include "aloc.h"

void loca(double a11[], double a12[], double a21[], double a22[], double h){
  
   double w1=0.5, w2=0.5, x1=0.5-(1 / (2*sqrt(3))), x2 = 0.5+(1 / (2*sqrt(3)));  // quad
   double phi1_1, phi1_2, phi2_1, phi2_2;
   int i;
   phi1_1 = 1 - x1;
   phi1_2 = 1 - x2;
   phi2_1 = x1;
   phi2_2 = x2;

   for(i=0;i<N-1;i++) {

   a11[i] = (1/h)*(eps* (w1*-1*-1 + w2*-1*-1));  // B(i,i)
   a11[i] += (w1*-1*phi1_1 + w2*-1*phi1_2);

   a12[i] = (1/h)*(eps* (w1*-1*1 + w2*-1*1));   // B(i,i+1)
   a12[i] += (w1*-1*phi2_1 + w2*-1*phi2_2);

   a21[i] = (1/h)*(eps* (w1*1*-1 + w2*1*-1));
   a21[i] += (w1*1*phi1_1 + w2*1*phi1_2);

   a22[i] = (1/h)*(eps* (w1*1*1 + w2*1*1));
   a22[i] += (w1*1*phi2_1 + w2*1*phi2_2);

   }

}

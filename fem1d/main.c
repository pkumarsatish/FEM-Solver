#include "aloc.h"
#include "solver.h"
#include "fplot.h"

int main()
{
   //int N=SIZE;			// Total Nodes, N-1 elemnts(edge)
   double xi=0, xf=1;  	// bounry points
   //double eps=1e-5;		// parameter 1
   
   double h = (xf - xi)/(N-1);
   double x[N]; // global dof   

   double u[N], ui[N], us[N], f[N];
   double val[3*N-4];
   int colI[3*N-4], rowP[N+1];
 
   int i, j=1;

   double a11[N-1], a12[N-1], a21[N-1], a22[N-1];  // Local Matrix 

	/* Global DoF */
   for (i=0;i<N;i++)	x[i] = xi + i*h;    // DoF


///////////////////////////////////////////////////
/*          Local A       */
   loca(a11, a12, a21, a22, h);

//////////////////////////////////////////////////////

/* Constructing f vector - No. integration require
	Only dirichlet boundries specification!!!
*/
   for (i=1; i<N; i++)	f[i] = 0;
   f[0] = 1;


/* A -System  Matrix */

   rowP[0] = 0;
   rowP[1] = 1;
   val[0] = 1;    /// BC1
   colI[0] = 0;

   for(i=1;i<N-1;i++){
      rowP[i+1] = rowP[i] + 3;
      colI[j] = i-1;
      val[j++] = a12[i-1]; //(-1*eps/h)-0.5; 
      colI[j] = i;
      val[j++] = a22[i-1]+a11[i];  //2*eps/h;
      colI[j] = i+1;
      val[j++] = a21[i];   //(-1*eps/h)+0.5;
   }

   rowP[N] = rowP[N-1] + 1;
   val[3*N-5] = 1;
   colI[3*N-5] = N-1;


//printf("%lf %lf %lf %lf",val[0],val[1],val[2],val[3]);
//printf("%d %d %d %d",rowP[N],colI[1],colI[2],colI[3]);

/* Solver Step */

   // Exact Solution and Initial Sol
   for(i=0;i<N;i++){
      ui[i] = 0;
      u[i] = ui[i];
      us[i] = (1 - exp((x[i]-1)/eps))/(-exp(-1/eps) + 1);
   }

   dj(val,colI,rowP,f,ui,us,u);	// Damped Jacobi
   fplot(u,"FEM-1D Solution");
   fplot(us,"Exact Solution");

   return 0;
}

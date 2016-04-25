#include "solver.h"

void dj(double val[],int col[],int rowp[],double f[],double ui[], double us[], double u[])
{
	int n = N;  // Size of matrix
	// Jacobi Parameter
	double omega = 2.0/3.0;
	
	// Stoping Parameters
	double rm[n],rnorm=0.0,rnorm_min=1e-6;  	// Residual
	double em[n],enorm=0.0,enorm_min=0.0; 	 	// Error 
	// double e1m[n],e1norm=0.0,e1norm_min=0.0;    // um+1 - um = wD^-1(rm);
	int itr=0, itr_max = 10000;			// No. of iterations performed

	int i=0;
	//char s2;

	multi(val,col,rowp,ui,rm); // rm = au - multiply A and ui
	for (i=0;i<n;i++){	
		rm[i]=f[i]-rm[i];
		em[i]=us[i]-u[i];
		// e1m[i]=(omega/val[0])*(rm[i]);
		
		u[i]=ui[i];	// Initilizing u, just in case for redundant u 
	}
	rnorm = linfnorm(rm);
	enorm = linfnorm(em);
	// e1norm = linfnorm(e1m);

	
// Computations involved in iterations 
	
	while (itr<=itr_max && rnorm>=rnorm_min && enorm>=enorm_min){	// e1norm>=e1norm_min						
		for(i=1;i<n-1;i++){
			u[i] = u[i] + (omega/val[2])*rm[i];     // val[0] for aii
		}


		u[0] = u[0] + (omega)*rm[0];
		u[n-1] = u[n-1] + (omega)*rm[n-1];
		multi(val,col,rowp,u,rm); // rm = au - multiply a and u-new
		for (i=0;i<n;i++)
		{
			em[i]=us[i]-u[i];		
			rm[i]=f[i]-rm[i];
			// e1m[i]=(omega/val[0])*(rm[i]);
		}
		rnorm = linfnorm(rm);
		enorm = linfnorm(em);
		// e1norm = linfnorm(e1m);
		itr++;	
	}
	
//	printf("No. of Iteration: %d\n",itr-1);
//	printf("Residual rm: %lf\n",rnorm);
//	printf("Error em: %lf\n",enorm);
	// printf("Improvement in last iteration: %lf\n",e1norm);
}

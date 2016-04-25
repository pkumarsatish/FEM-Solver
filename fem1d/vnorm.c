#include "vnorm.h"

double l1norm(double v[])
{
	int n;
	n = N;
	int i=0;
	double l1=0.0;
	for (i=0;i<n;i++)
	{
		l1+=fabs(v[i]);
	}
	
	return l1;
}

double linfnorm(double v[])
{
	int n;
	n = N;
	int i=0;
	double linf=0.0;
	for (i=0;i<n;i++)
	{
		if(linf<fabs(v[i]))
		{
			linf = fabs(v[i]);
		}
	}	
	return linf;
}

double lpnorm(double v[],int p)
{
	int n;
	n = N;
	int i=0;
	double lp=0.0;
	double p1;
	for (i=0;i<n;i++)
	{
		lp+=pow(fabs(v[i]),p);
	}
	p1 = 1.0/p;
	lp=pow(lp,p1);
	return lp;
}

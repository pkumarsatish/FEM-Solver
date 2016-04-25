#include "csrmv.h"

void multi(double val[], int col[], int rowp[], double u[], double au[])
{
	int n = N;
	int i=0, j=0;
	
	for(i=0;i<n;i++)
	{	
		au[i] = 0;
		for (j=rowp[i];j<rowp[i+1];j++)
		{
			au[i]+=(val[j]*u[(col[j])]);
		}
	}
}

#include "fplot.h"

void fplot(double v[], char s[])
{
	int n=N,i;
	char dig[10];
	snprintf(dig,10,"%d",n);		//dig = (char)(((int)'0')+n);
	char *plots=malloc(strlen(s)+24),*titles=malloc(strlen(s)+25);
	
	strcpy(plots,"plot \'");
	strcat(plots,s);
	strcat(plots,"\' with line");
	
	strcpy(titles,"set title \"");
	strcat(titles,s);
	strcat(titles," with N = ");
	strcat(titles,dig);

	FILE *fp,*gnuplotPipe;
	char *commandsForGnuplot[]= {titles,plots};
	int NUM_COMMANDS = 2;
	double x;

	fp = fopen(s,"w+");
	for (i=0;i<n;i++){
		x=(i+1.0)/(n+1.0);
		fprintf(fp,"%lf %lf \n",x,v[i]);
	}
	fclose(fp);
	gnuplotPipe = popen ("gnuplot -persistent", "w");
	for (i=0; i < NUM_COMMANDS; i++){
    		fprintf(gnuplotPipe, "%s \n", commandsForGnuplot[i]); //Send commands to gnuplot one by one.
    	}
}

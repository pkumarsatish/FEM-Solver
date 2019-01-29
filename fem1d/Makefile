all: main.o aloc.o solver.o csrmv.o vnorm.o fplot.o
	gcc -Wall main.o aloc.o solver.o csrmv.o vnorm.o fplot.o -o fem1 -lm
main.o:
	gcc -Wall -c main.c -o main.o
aloc.o:
	gcc -Wall -c aloc.c -o aloc.o
solver.o:
	gcc -Wall -c solver.c -o solver.o
csrmv.o:
	gcc -Wall -c csrmv.c -o csrmv.o
vnorm.o:
	gcc -Wall -c vnorm.c -o vnorm.o
fplot.o:
	gcc -Wall -c fplot.c -o fplot.o
clean:
	rm -rf *.o

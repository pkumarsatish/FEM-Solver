## FEM 1D 
### Program to solve one-dimensional boundry value problems using Galerkin FEM. 
### READ se291h2.pdf for an specific example.

### Requirment 
gcc, gnuplot

### Compiling and building the executable
Use the following steps:

1. open aloc.h to change eps and N values for the problem

2. make: to compile the program, It generates 'fem1' executable.

3. ./fem1: to execute the program


### Description of C-Files
1. **main.c:** It contains various problem parameters. Main task of this file is to,
Assamle golbal A from local A, in sparse formate and serves as script file.

2. **solver.c:** *Input:* A-in CSR formate. *Output:* u := Au=f. *Function:* Usase Damped-Jacobi iterative technique to solve Au=f.

3. **csrmv.c:** *Input:* A-matrix in csr, x-vector. *Output:* b = A*x. *Function:* Matrix-vector multiplication for matrix in CSR formate.

4. **vnorm.c:** *Input:* a vector. *Ouput:* various norm of the vector. *Function:* L1, L2 and L-inf norm.

5. **aloc.c:** *Input:* Basis Functions, Refrence Element, Gauss Quad points, weights. *Output:* Local System matrix *Functions:* Constructs local system matrix with values computed for reference element.

6. **fplot.c:** *Input:* an array and a string. *Output:* Plots the array and saves the array data into file named as the string. *Function:* GNU-Plot and File Writting task.

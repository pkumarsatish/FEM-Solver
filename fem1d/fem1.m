clc;
clear all;
close all;

eps = 1e-2;
xi = 0;
xf = 1;
N = 100;

h = (xf - xi)/(N-1);

a = (-eps/h) - 1/2;
b = 2*eps/h;
c = (-eps/h) + 1/2;

A = zeros(N,N);
f = zeros(N,1);
%u = zeros(N,1);

A(1,1) = 1;
f(1) = 1;

A(N,N) = 1;
f(N) = 0;

for i = 2 : N-1
    A(i,i-1) = a;
    A(i,i) = b;
    A(i,i+1) = c;
end

x = xi : h : xf;
yexact = (exp(1/eps) - exp(x/eps));
yexact = yexact/ (exp(1/eps) -1);
%yexact

u = A\f;

plot(x,yexact,'r');
hold on
plot(x,u,'bo')

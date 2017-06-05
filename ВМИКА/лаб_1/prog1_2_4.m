clear;
clc;
t=-1:0.1:1;
[x,y]=meshgrid(t,t);
z=fun1(x,y);
mesh(x,y,z);
grid on;
z1=fun7(x,y);
meshc(x,y,z1);
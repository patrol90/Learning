clear;
clc;
t=-1:0.1:1;
[x,y]=meshgrid(t,t);
z1=fun7(x,y);
v=[0 0];
contour(x,y,z1,v);
grid on;
hold on;
z2=fun8(x,y);
contour(x,y,z2,v);
hold off;
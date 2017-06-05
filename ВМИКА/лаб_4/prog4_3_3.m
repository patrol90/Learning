clear;
clc;
a=0.01;
b=10;
x=a:0.01:b;
y=fun10(x);
disp('Метод левых прямоугольников');
leftp(x,y)
disp('Метод правых прямоугольников');
rightp(x,y)
disp('Метод трапеций');
trap(x,y)
disp('Метод Симпсона');
sima(x,y)
disp('При помощи средств MatLab');
quad('fun',a,b)
disp('По формуле Гаусса-Лежандра');
[res1,res2]=gauslej3('fun',a,b)
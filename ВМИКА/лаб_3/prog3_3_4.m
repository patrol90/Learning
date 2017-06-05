clc;
clear;
fig1=figure;
fig2=figure;
a=0.01;
b=2;
notr=4;  % Число отрезков
h=(b-a)/notr;
h1=h/5;
x=a:h:b; % задание узлов интерполирования 
xc=1;   %контрольная точка
y=fun9(x);  % подсчёт значений в узлах интерполирования
disp('Значение интреполяционного полинома в контрольной точке')
pol(x,y,xc)
disp('Значение интерполяционной функции в контрольной точке') 
fun9(xc)
disp('При помощи средств MatLab')
a1=polyfit(x,y,notr);
polyval(a1,xc)
%%%%%%%%%%%%%%%%Постоение графиков%%%%%%%%%%%%%
xf=a:h1:b;
figure(fig1);
grid on;
hold on;
% Построение графика интреполяционного полинома
n=length(xf)-1;
for k=0:n
    yp(k+1)=pol(x,y,xf(k+1));  
end
plot(xf,yp,'k-o');
%%%%%%%%%%%%%%%%%При помощи средст MatLab'a%%%%%%%%%%%%%%%%
for k=0:n
    yp(k+1)=polyval(a1,xf(k+1));
end
plot(xf,yp,'b- *');
%%%%%%%%%%%%%C выбором узлов%%%%%%%%%%
for k=0:notr
    xv(k+1)=(b-a)/2*cos(((2*k+1)*pi)/(2*notr+2))+(b+a)/2;
end
yv=fun3(xv);
disp('Значение полученное при выборе узлов интерполирования')
pol(xv,yv,xc)
for k=0:notr
    xf(n+k+2)=xv(k+1);
end
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
m=numel(xf);                             % 
for k=1:m-1                              %
    for i=k+1:m                          %Сортировка 
        if xf(k)>=xf(i) 
            p=xf(k);
            xf(k)=xf(i);
            xf(i)=p;
        end
    end
end
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
for k=1:n+2+notr
    yf(k)=pol(xv,yv,xf(k));
end
figure(fig2);
hold on;
grid on;
plot(xf,yf,'b- *');    % График с наилучшим выбором
yf=fun3(xf);
figure(fig1);
plot(xf,yf,'r.-'); % Построение графика исходной фунцкии в fig1
plot(x,0,'g- .'); % Построение узлов с равномерной сеткой
legend('Equalent','MatLab','Function','Nodes',2);
figure(fig2);
plot(xf,yf,'r- .'); % Построение графика исходной фунцкии в fig2
plot(xv,0,'g.-');  %  Узлы (наилучший выбор)
legend('Best','Function','Nodes',2);
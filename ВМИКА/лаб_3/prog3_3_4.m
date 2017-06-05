clc;
clear;
fig1=figure;
fig2=figure;
a=0.01;
b=2;
notr=4;  % ����� ��������
h=(b-a)/notr;
h1=h/5;
x=a:h:b; % ������� ����� ���������������� 
xc=1;   %����������� �����
y=fun9(x);  % ������� �������� � ����� ����������������
disp('�������� ����������������� �������� � ����������� �����')
pol(x,y,xc)
disp('�������� ���������������� ������� � ����������� �����') 
fun9(xc)
disp('��� ������ ������� MatLab')
a1=polyfit(x,y,notr);
polyval(a1,xc)
%%%%%%%%%%%%%%%%��������� ��������%%%%%%%%%%%%%
xf=a:h1:b;
figure(fig1);
grid on;
hold on;
% ���������� ������� ����������������� ��������
n=length(xf)-1;
for k=0:n
    yp(k+1)=pol(x,y,xf(k+1));  
end
plot(xf,yp,'k-o');
%%%%%%%%%%%%%%%%%��� ������ ������ MatLab'a%%%%%%%%%%%%%%%%
for k=0:n
    yp(k+1)=polyval(a1,xf(k+1));
end
plot(xf,yp,'b- *');
%%%%%%%%%%%%%C ������� �����%%%%%%%%%%
for k=0:notr
    xv(k+1)=(b-a)/2*cos(((2*k+1)*pi)/(2*notr+2))+(b+a)/2;
end
yv=fun3(xv);
disp('�������� ���������� ��� ������ ����� ����������������')
pol(xv,yv,xc)
for k=0:notr
    xf(n+k+2)=xv(k+1);
end
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
m=numel(xf);                             % 
for k=1:m-1                              %
    for i=k+1:m                          %���������� 
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
plot(xf,yf,'b- *');    % ������ � ��������� �������
yf=fun3(xf);
figure(fig1);
plot(xf,yf,'r.-'); % ���������� ������� �������� ������� � fig1
plot(x,0,'g- .'); % ���������� ����� � ����������� ������
legend('Equalent','MatLab','Function','Nodes',2);
figure(fig2);
plot(xf,yf,'r- .'); % ���������� ������� �������� ������� � fig2
plot(xv,0,'g.-');  %  ���� (��������� �����)
legend('Best','Function','Nodes',2);
clear;
clc;
a=0.01;
b=10;
x=a:0.01:b;
y=fun10(x);
disp('����� ����� ���������������');
leftp(x,y)
disp('����� ������ ���������������');
rightp(x,y)
disp('����� ��������');
trap(x,y)
disp('����� ��������');
sima(x,y)
disp('��� ������ ������� MatLab');
quad('fun',a,b)
disp('�� ������� ������-��������');
[res1,res2]=gauslej3('fun',a,b)
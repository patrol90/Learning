function [res1,res2]=gauslej3(ff,a,b);
% Формула Гаусса-Лежандра
f = fcnchk(ff);
t=[-0.774597,0,0.774597];
c=[5/9,8/9,5/9];
n=numel(t);
res1=0;
for i=1:n
    res1=res1+feval(f,(b-a)/2*t(i)+(a+b)/2)*c(i);
end
res1=res1*(b-a)/2;
t=[0.339981,-0.339981,0.861136,-0.861136];
c=[0.652145,0.652145,0.347855,0.347855];
n=numel(t);
res2=0;
for i=1:n
    res2=res2+feval(f,(b-a)/2*t(i)+(a+b)/2)*c(i);
end
res2=res2*(b-a)/2;
return
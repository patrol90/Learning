function res=trap(x,y);
% Метод трапеций
h=x(2)-x(1);
n=numel(x);
s=0;
for i=1:n-1
    s=s+(h/2)*(y(i)+y(i+1));
end
res=s;
return
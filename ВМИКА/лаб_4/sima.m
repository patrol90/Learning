function res=sima(x,y);
% Метод Симпсона
h=x(2)-x(1);
n=numel(x);
s=0;
for i=1:(n-1)/2
    s=s+(h/3)*(y(2*i-1)+4*y(2*i)+y(2*i+1));    
end
res=s;
return
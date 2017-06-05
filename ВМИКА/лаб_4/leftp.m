function res=leftp(x,y);
% Метод левых прямоугольников
h=x(2)-x(1);
n=numel(x);
s=0;
for i=1:n-1
    s=s+h*y(i);
end
res=s;
return
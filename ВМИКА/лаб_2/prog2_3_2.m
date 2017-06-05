clear;
clc;
a=[-5 5 -2;-2 3 -3;0 2 2]
b=[-28;-12;-8]
n=3;
for k=1:n-1
        for i=k+1:n
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
l=k;
amax=abs(a(l,k));
for v=k+1:n
    if abs(a(v,k))>amax
        l=v;
        amax=abs(a(v,k));
    end
end
if l~=k
    for j=k:n
        p=a(k,j);
        a(k,j)=a(l,j);
        a(l,j)=p;
    end
  p=b(k);
  b(k)=b(l);
  b(l)=p;
end
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
            m=a(i,k)/a(k,k);
            a(i,k)=0;
                for j=k+1:n
                    a(i,j)=a(i,j)-m*a(k,j);
                end
            b(i)=b(i)-m*b(k);
        end
end
x(n)=b(n)/a(n,n);
for i=n-1:-1:1
    s=0;
    for j=i+1:n
        s=s+a(i,j)*x(j);
    end
x(i)=(b(i)-s)/a(i,i);
end
disp('Решение получено c помощью метода Гаусса с выбором главного элемента');
x=x'
disp('Решение получено с помощью средств MatLab');
x1=(a^-1)*b


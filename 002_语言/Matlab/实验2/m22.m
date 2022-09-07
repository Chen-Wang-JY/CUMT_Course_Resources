syms x
f(x)=x^3-x^2-1;
g(x)=diff(f,x);

x0=input('请输入初值1:');
x1=input('请输入初值2:');
tol=input('请输入精度：');
ites=input('请输入迭代次数：');

k=0;
while k<ites
    k=k+1;
    xk=x1-f(x1)*(x1-x0)/(f(x1)-f(x0));
    temp=double(f(xk));
    if abs(temp)<tol
        x0=xk;
        break;
    end
    x0=xk;
end
temp=double(f(x0));
if temp>tol
    disp('迭代次数过少，未收敛');
elseif x0==inf
    disp('发散')
else
    fprintf('经过%d次迭代，求出的根是%.4f\n',k,x0);
end
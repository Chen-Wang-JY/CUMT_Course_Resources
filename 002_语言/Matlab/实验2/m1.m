x0=input('迭代初值：');
tol=input('精度:');
maxit=input('最大迭代次数:');
choice=menu('请选择方法','Method1','Method2','Method3','Method4','Method5','退出');
flag=0;
while 1
    if choice==1
        [x,y]=Method1(x0,tol,maxit);
        flag=1;
        break;
    elseif choice==2
        [x,y]=Method2(x0,tol,maxit);
        flag=1;
        break;
    elseif choice==3
        [x,y]=Method3(x0,tol,maxit);
        flag=1;
        break;
    elseif choice==4
        [x,y]=Method4(x0,tol,maxit);
        flag=1;
        break;
    elseif choice==5
        [x,y]=Method5(x0,tol,maxit);
        flag=1;
        break;
    else
        flag=0;
        choice=menu('请选择方法','Method1','Method2','Method3','Method4','Method5','退出');
    end
end
if flag==1
    f=x^3-x^2-1;
    if x==inf
        disp('发散')
    elseif f>tol
        disp('迭代次数过少，未收敛')
    else
        fprintf('经过%d次迭代，得到方程根是%.4f\n',y,x);
    end
end


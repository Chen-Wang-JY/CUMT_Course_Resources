function [r,ites] = Method1(x0,tol,maxit)
    k=0;
    while k<maxit
        k=k+1;
        if x0-1<0
            r=inf;
            ites=k;
            return;
        end
        xk=1/sqrt(x0-1);
        f=xk^3-xk^2-1;
        if abs(f)<tol
            x0=xk;
            break;
        end
        x0=xk;
    end
    r=x0;
    ites=k;
end
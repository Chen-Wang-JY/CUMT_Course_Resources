function [r,ites] = Method2(x0,tol,maxit)
    k=0;
    while k<maxit
        k=k+1;
        xk=1/x0/x0+1;
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
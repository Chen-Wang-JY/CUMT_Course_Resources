function [r,ites] = Method4(x0,tol,maxit)
    k=0;
    while k<maxit
        k=k+1;
        xk=(x0^2+1)^(1/3);
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
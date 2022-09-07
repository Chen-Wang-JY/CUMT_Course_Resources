function[mycell] = builtstr(ch,n)
    strcell={};
    mych=ch;
    for i=1:n
        strcell=[strcell,mych];
        mych=[mych,char(ch+i)];
    end
    mycell=cellstr(strcell);
end


line(2)=struct('From',struct('X',5,'Y',6),'To',struct('X',2,'Y',10));
line(1)=struct('From',struct('X',3,'Y',5),'To',struct('X',4,'Y',7));
K=fun(line);
disp(K);

function [K]=fun(line)
    K=[];
    len=length(line);
    for i=1:len
        dy=line(i).To.Y-line(i).From.Y;
        dx=line(i).To.X-line(i).From.X;
        K=[K,dy/dx];
    end
end
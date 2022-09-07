% Write the file named xypts.dat
fp=fopen('xypts.dat','w');
if(fp==-1)
    disp('File does not open!');
    return
end
for i=1:10
    x=randi(9);
    y=randi(9);
    fprintf(fp,'x %d y %d\n',x,y);
end
if(fclose(fp)==-1)
    disp('File does not close!');
    return 
end

% Read the file named xypts.dat
fp=fopen('xypts.dat','r');
if(fp==-1)
    disp('File does not open!');
    return
end
X=[];
Y=[];
for i=1:10
    line=fgetl(fp);    
    X=[X,str2double(line(3))];
    Y=[Y,str2double(line(7))];
end
if(fclose(fp)==-1)
    disp('File does not close!');
    return 
end
disp(X);
disp(Y);
plot(X,Y);

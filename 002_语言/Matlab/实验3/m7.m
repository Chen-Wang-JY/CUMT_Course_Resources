fp=fopen('data7.dat','r');
if(fp==-1)
    disp('File does not open!');
    return
end

data=textscan(fp,'%c %.1f');

nums=data{1,2};
sum=0;
for i=1:length(nums)
    sum=sum+nums(i);
end
fprintf('Sum:%f\n',sum);



if(fclose(fp)==-1)
    disp('File does not close!');
    return 
end
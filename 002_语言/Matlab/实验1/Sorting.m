function [] = Sorting(vector)
len=length(vector);
for i=len:-1:1
    for j=1:i-1
        if vector(j)<vector(j+1);
            temp=vector(j);
            vector(j)=vector(j+1);
            vector(j+1)=temp;
        end
    end
end
disp(vector)
end


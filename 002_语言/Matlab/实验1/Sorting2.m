function [] = Sorting2(vec)
len=numel(vec);
for i=1:len
    indexmin=i;
    for j=i+1:len
        if vec(j)<vec(indexmin)
            indexmin=j;
        end
    end
    temp=vec(i);
    vec(i)=vec(indexmin);
    vec(indexmin)=temp;
end
disp(vec);
end
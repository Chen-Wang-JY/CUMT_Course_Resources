function[x]=linearEquation(A,b)
    mat=[A,b];  %增广矩阵
    [row,column]=size(mat);  %求出合并向量的行，列值
    x=zeros(row,1);  %解向量的初始化
    temp=zeros(row,column);  %阶梯形矩阵的初始化
    
    %阶梯形矩阵的第一行与原矩阵相同
    for i=1:column
        temp(1,i)=mat(1,i);
    end
    
    %每一行都与第k-1行消去，使得当前行的第一个非零元素为0，同时更新mat矩阵
    for k=2:row
        for j=k:row
            temp(j,:)=mat(j,:)-mat(j,k-1)/mat(k-1,k-1)*mat(k-1,:);
            mat(j,:)=temp(j,:);
        end
    end
    
    %开始回代
    
    x(row)=temp(row,column)/temp(row,column-1);  %得到解向量的最后一个分量
    %从下向上回代求出其余分量
    for i=row-1:-1:1
        %先将该分量的系数化为1
        x(i)=temp(i,column)/temp(i,i);
        for j=row:-1:i+1 
            x(i)=x(i)-temp(i,j)*x(j)/temp(i,i);          %回代第i列的解
        end
    end
end
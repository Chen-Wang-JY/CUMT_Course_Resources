function [] = maxInMatrix(matrix)
[row,colume]=size(matrix);
row_index=1;
colume_index=1;
for i=1:row
    for j=1:colume
        if matrix(i,j)>matrix(row_index,colume_index)
            row_index=i;
            colume_index=j;
        end
    end
end
fprintf('The random matrix is\n');
disp(matrix);
fprintf('The max number in matrix is %.4f at row %d and colume %d\n',matrix(row_index,colume_index),row_index,colume_index)
end


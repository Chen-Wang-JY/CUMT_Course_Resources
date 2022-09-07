function[]=maxInMatrix2(matrix)
[row,colume]=size(matrix);
target=max(max(matrix));
max_row=[];
max_col=[];
for i=1:row
    for j=1:colume
        if matrix(i,j)==target
            max_row=[max_row,i];
            max_col=[max_col,j];
        end
    end
end
fprintf('The matrix is:\n');
disp(matrix);
fprintf('The row of the max number is\n');
disp(max_row);
fprintf('The colume of the max number is\n');
disp(max_col);
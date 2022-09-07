%
%  main.m 主函数文件
%
clear; close all; clc;


% Part 1 加载数据，将训练集导入 %

fprintf('Part 1 加载数据，将训练集导入\n');
data = load('trainingdata.txt');
X = data(:, 1:2);   % 特征矩阵
y = data(:, 3);     % 标签向量
X = X/100;  

% 先看一下样本数据 %
pos = find(y==1); neg = find(y == 0); % 找到正样本与负样本

% 在子图1中绘制样本分布图
subplot(2, 2, 1);
plot(X(pos,1), X(pos,2), 'k+', X(neg,1), X(neg,2), 'ko', 'MarkerFaceColor', 'y');
xlabel('科目一成绩');
ylabel('科目二成绩');
title('样本分布', 'fontname', '仿宋', 'Color', 'b', 'FontSize', 15);

% 在子图2中绘制样本分布，在完成拟合后，再添加决策边界方程
subplot(2, 2, 2);
plot(X(pos,1), X(pos,2), 'k+', X(neg,1), X(neg,2), 'ko', 'MarkerFaceColor', 'y');
hold on;


% Part 2 拟合模型前的准备工作 %

fprintf('\nPart 2 拟合模型前的准备工作\n');
[m, n] = size(X);       % m是训练集样本数，n是特征数
X = [ones(m, 1) X];     % 特征矩阵加入第一列常数1
theta = zeros(1,n+1);   % 初始化拟合参数，全部为0


% Part 3 梯度下降 %

fprintf('\nPart 3 梯度下降\n');
cost1 = costFunction(theta,X,y); % 先看一下训练前的代价函数值
fprintf('训练前的代价函数值：%f\n', cost1);

learn_rate = 0.05;  % 学习率
iter = 150000;        % 迭代次数
vector_cost = zeros(iter, 1);   % 存储每一次迭代后的代价函数值

for i=1:iter    % 进行iter次迭代
    % theta参数矩阵中的每一个参数值都应该在当前次的梯度下降之后更新，故设置一临时变量保存theta的值。
    % 在对n+1个参数更新的时候，只需要更新temp矩阵，最后将temp重新赋给theta
    temp = theta;   
    for j=1:n+1   % 更新每一个theta的值
        temp(j) = temp(j)-learn_rate/m*sum( (sigmoid(X*theta')-y).*X(:,j) );
    end
    theta = temp;   % 将临时变量temp的值重新赋给theta
    vector_cost(i) = costFunction(theta, X, y); % 记录当前参数对应的代价函数值
end


% Part 4 打印输出 %

fprintf('\nPart 4 打印输出\n');
fprintf('\n最终代价函数收敛于值：%f\n', vector_cost(iter));
fprintf('得到的参数theta：\n');
disp(theta);

% 得到决策边界方程的字符串表示，并打印
fin_equation = string(theta(1))+'+'+string(theta(2))+'*x1+'+string(theta(3))+'*x2';
fprintf('拟合得到的决策边界方程：%s\n', fin_equation);

subplot(2, 2, 2);
equation = @(x1,x2)theta(1)+theta(2)*x1+theta(3)*x2;    % 决策边界的隐函数方程
fimplicit(equation, [0.3 1 0.3 1]); % 训练集中，特征一最小值为0.30588，特征值二的最小值为30.6033，故绘图的边界设置为0.3
xlabel('科目一成绩');
ylabel('科目二成绩');
title('决策边界的直线方程', 'fontname', '仿宋', 'Color', 'b', 'FontSize', 15);

subplot(2, 2, 3);
plot(vector_cost);
title('梯度下降中，代价函数的收敛趋势', 'fontname', '仿宋', 'Color', 'b', 'FontSize', 15);
xlabel('迭代次数');
ylabel('代价函数值');

% Part 5 验证模型准确性 %
fprintf('\nPart 5 验证模型准确性\n');

test_data = load('testdata.txt'); % 加载测试集数据
[test_m, test_n] = size(test_data); % m代表测试集数据的样本数量
% 取出测试集样本的两个特征列向量及标签列向量
test_X1 = test_data(:, 1);
test_X2 = test_data(:, 2);
test_Y = test_data(:, 3);
% 两个特征值均缩小100倍
test_X1 = test_X1./100;
test_X2 = test_X2./100;

% 写出建立的预测模型方程
syms x1 x2
predict_function(x1, x2) = sigmoid(theta(1)+theta(2)*x1+theta(3)*x2);
% 储存预测结果的列向量
predict_tags = zeros(test_m, 1);
% 开始预测
for i=1:test_m
    temp = predict_function(test_X1(i), test_X2(i));
    % 预测值大于0.5，则认为该样本属于正样本
    if temp >= 0.5
        predict_tags(i) = 1;
    % 否则，认为该样本属于负样本
    else
        predict_tags(i) = 0;
    end
end
flags = predict_tags == test_Y; % 相同则为1，预测成功；不同则为0，预测失败

% 打印预测结果
for i=1:test_m
    temp = '预测成功';
    if flags(i)==0
        temp = '预测失败';
    end
    fprintf('第%d个样本的预测结果是：%s\n', i, temp);
end
fprintf('该预测模型在测试集上预测成功的准确率为%f\n', sum(flags)/test_m);

subplot(2, 2, 4);
pos = find(test_Y==1); neg = find(test_Y == 0); % 找到正样本与负样本
plot(X(pos,1), X(pos,2), 'k+', X(neg,1), X(neg,2), 'ko', 'MarkerFaceColor', 'y');
plot(test_X1(pos), test_X2(pos), 'k+', test_X1(neg), test_X2(neg), 'ko', 'MarkerFaceColor', 'y');
hold on;
fimplicit(equation, [0.3 1 0.3 1]);
xlabel('科目一成绩');
ylabel('科目二成绩');
title('预测模型的准确度可视化', 'fontname', '仿宋', 'Color', 'b', 'FontSize', 15);


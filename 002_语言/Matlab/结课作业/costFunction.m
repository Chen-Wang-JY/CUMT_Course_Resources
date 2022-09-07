function J = costFunction(theta, X, y)
% 返回代价函数值
   m = length(y);
   % 逻辑回归的代价函数有两部分相加组成
   first = -y.*log(sigmoid(X*theta'));          % 第一部分
   second = -(1-y).*log(1-sigmoid(X*theta'));   % 第二部分
   J = sum(first+second)/m;
end


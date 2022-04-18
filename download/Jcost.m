function J = Jcost(X,y,theta)
m = size(X,1); %计算样本个数
predictions = X*theta; %计算预测值
sqrErrors = (predictions - y).^2; %计算误差
J = 1/(2*m) * sum(sqrErrors); %计算损失

function J = Jcost(X,y,theta)
m = size(X,1); %������������
predictions = X*theta; %����Ԥ��ֵ
sqrErrors = (predictions - y).^2; %�������
J = 1/(2*m) * sum(sqrErrors); %������ʧ

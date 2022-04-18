%plot(x,y,".");
%hold on;
x1 = [ones(size(y)),x];
theta = zeros(size(x1,2),1);
count = 0; 
iterations = 10000;
m = size(x1,1);
k = size(theta,1);
a = 0.00001;
while(count < iterations)
    
    for i = 1:k,
        A(i) = (1/m)*sum((x1*theta-y).*x1(:,i));
    end
    theta = theta - a*A';
    disp(count);
    %disp(A);
    %disp(theta');
    %plot(count,theta(1,1));
    count = count + 1;
end
plot(x,x*theta(2)+theta(1));
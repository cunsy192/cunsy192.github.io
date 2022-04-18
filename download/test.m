theta = [0;0];
count = 0; 
iterations = 1000;
m = size(x,1);
k = size(theta,1);
while(count < iterations)
      plot(x,x*theta(2)+theta(1));  
    for i = 1:k,
        A(i) = (1/m)*sum((x*theta-y).*x(:,i));
    end
    theta = theta - 0.00001*A';
    disp(count);
    %disp(A);
    disp(theta');
    %plot(count,theta(1,1));
    count = count + 1;
end

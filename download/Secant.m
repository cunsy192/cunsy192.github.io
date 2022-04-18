it = 1:20;

%cosx-x=0
x1 = 1;
x2 = 0.99;
y1 = cos(x1)-x1;
y2 = cos(x2)-x2;
i = 0;
while i < 5,
    i = i + 1;
    x3 = x2 - (y2*(x1-x2))/(y1-y2);
    x1 = x2;
    x2 = x3;
    y1 = cos(x1)-x1;
    y2 = cos(x2)-x2;
    det(i) = abs((0.739085-x3)/0.739085);
end

subplot(2,2,3);
title('弦截法-cosx-x=0');
plot(it,det);
xlabel('迭代次数/i');
ylabel('相对误差/det');
hold on;


%x^12-1=0
% x1 = 2;
% x2 = 1.99;
% y1 = x1^12-1;
% y2 = x2^12-1;
% i = 0;
% while i < 20,
%     i = i + 1;
%     x3 = x2 - (y2*(x1-x2))/(y1-y2);
%     x1 = x2;
%     x2 = x3;
%     y1 = x1^12-1;
%     y2 = x2^12-1;
%     det(i) = abs((1-x3)/1);
% end

subplot(2,2,4);
title('弦截法-x^{12}-1=0');
plot(it,det);
xlabel('迭代次数/i');
ylabel('相对误差/det');
hold on;

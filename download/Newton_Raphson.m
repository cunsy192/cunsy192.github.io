it = 1:20;

%cosx-x=0
x = 1;
y = cos(x)-x;
y1 = -sin(x)-1;
i = 0;
while i < 20,
    i = i + 1;
    x = x - y/y1;
    y = cos(x)-x;
    y1 = -sin(x)-1;
    det(i) = abs((0.739085-x)/0.739085);
end

subplot(2,2,1);
title('ţ�ٷ�-cosx-x=0');
plot(it,det);
xlabel('��������/i');
ylabel('������/det');
hold on;

% x^12-1=0
x = 2;
y = x^12-1;
y1 = 12*x^11;
i = 0;
while i < 20,
    i = i + 1;
    x = x - y/y1;
    y = x^12-1;
    y1 = 12*x^11;
    det(i) = abs((1-x)/1);
end

subplot(2,2,2);
title('ţ�ٷ�-x^{12}-1=0');
plot(it,det);
xlabel('��������/i');
ylabel('������/det');
hold on;

% plot(it,det);
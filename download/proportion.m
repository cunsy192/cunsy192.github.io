%设定端点值 a,b
%设定迭代次数 i
%设定步长（间隔距离）h
%设定函数值 fc
%设定空数组 k ,用于储存搜索区间内各值（迭代后清空）
a = 0;
b = 1;

i = 0; 


fa = cos(a)-a;
fb = cos(b)-b;
c = a-(fa/(fa-fb))*(a-b); 
fc = cos(c)-c;

while i < 20, %设定迭代20次，也可用det误差设定条件
    i = i + 1; %迭代次数+1
    if fa*fc < 0,
        b = c;
    end
    if fb*fc < 0,
        a = c;
    end
    fa = cos(a)-a;
    fb = cos(b)-b;
    c = a-(fa/(fa-fb))*(a-b); 
    fc = cos(c)-c;
    det(i) = abs(0.739085 - c)/0.739085; %相对误差
end

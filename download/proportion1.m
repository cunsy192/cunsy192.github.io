%设定端点值 a,b
%设定迭代次数 i
%设定步长（间隔距离）h
%设定函数值 fc
%设定空数组 k ,用于储存搜索区间内各值（迭代后清空）
a = 0;
b = 2;

i = 0; 


fa = a^12-1;
fb = b^12-1;
c = a-(fa/(fa-fb))*(a-b); 
fc = c^12-1;

while i < 10000, %设定迭代20次，也可用det误差设定条件
    i = i + 1; %迭代次数+1
    if fa*fc < 0,
        b = c;
    end
    if fb*fc < 0,
        a = c;
    end
    fa = a^12-1;
    fb = b^12-1;
    c = a-(fa/(fa-fb))*(a-b); 
    fc = c^12-1;
    det(i) = abs(1 - c)/1; %相对误差
end

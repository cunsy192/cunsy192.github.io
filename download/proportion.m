%�趨�˵�ֵ a,b
%�趨�������� i
%�趨������������룩h
%�趨����ֵ fc
%�趨������ k ,���ڴ������������ڸ�ֵ����������գ�
a = 0;
b = 1;

i = 0; 


fa = cos(a)-a;
fb = cos(b)-b;
c = a-(fa/(fa-fb))*(a-b); 
fc = cos(c)-c;

while i < 20, %�趨����20�Σ�Ҳ����det����趨����
    i = i + 1; %��������+1
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
    det(i) = abs(0.739085 - c)/0.739085; %������
end

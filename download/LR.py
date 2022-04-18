#肝了一晚上，和矩阵星乘斗智斗勇
#的确学习了很多numpy库和plt库的知识，顺便还搞了一波如何读入数据
#值得注意的是，该迁移的代码运行速度比matlab快了不少，目前只适合二元线性回归模型
#同时需要明白，在该程序不给力的情况下，需要调整步频a的大小，同时注意该程序未进行标准化
#——村山羊于2020.9.27

import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
import xlrd

#导入数据库
data = xlrd.open_workbook('D:/test.xlsx')
sheet=data.sheets()[0]
rows=sheet.row_values(0)
clou0 = sheet.col_values(0)
clou1 = sheet.col_values(1)
x = clou0[1:]
y = clou1[1:]

#数据散点图（数据源:kaggle）
plt.scatter(x,y)

#矩阵化初始数据
x = np.matrix(x)
x = np.transpose(x)
y = np.matrix(y)

#增扩自变量，转置因变量
one = np.transpose(np.matrix(np.ones(y.shape[1])))
x1 = np.c_[one,x]
y = np.transpose(y)

#配置权重，默认为0
theta = np.zeros((x1.shape[1],1));
theta = np.array(theta)
#print(theta)

#计数器与迭代次数设置（可改变迭代次数）
count = 0;
iterations = 100;

#小作业：实现一个自动收敛的无迭代次数的线性回归程序。
#“我确信已经有了好的方法，可惜这里的空太小，我写不下。”

#权重行数、数据行数设置
m = x1.shape[0]
k = theta.shape[0]

#步长
a = 0.00001;

#循环迭代（指炼丹）
while count < iterations:
    A = [[]]
    for i in range(k):
        a1 = x1 * theta - y
        a1 = np.multiply(a1, x1[:,i])
        a1 = a1.sum() * (1/m)
        A = np.c_[A,a1]

    #如果开启该项，则在图像中将显示出每一次迭代产生的图像
    #plt.plot(x, x * theta[1, :] + theta[0, :])

    theta = theta - a*np.transpose(A)

    count = count + 1;
#循环由此结束

#做回归图，show()函数相当于matlab中的hold on后display，一步到位
plt.plot(x,x*theta[1,:]+theta[0,:])
plt.show()

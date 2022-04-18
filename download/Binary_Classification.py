#该程序只是初步进行分类，可以使用其他方式降低时间复杂度及实现参数智能化
#该程序未进行读写文件操作，之后将进行多次优化改进
#该程序只能进行固定数据集的二分类，本意并不在打造具有鲁棒性的多功能框架，只是模型演示
#——村山羊 2020.9.29
import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
import math
import xlrd

#二元理论数据集（列表形式给出）
x0 = [1,2,3,4,10,5,12,11,14,15]
x1 = [2,1,4,5,13,6,16,13,11,14]
y = [0,0,0,0,1,0,1,1,1,1]

#散点图输出
for i in range(10):
    if y[i] == 0:
        plt.scatter(x0[i],x1[i],marker='o')
    if y[i] == 1:
        plt.scatter(x0[i],x1[i],marker='^')

#矩阵化并创建权重向量
x0 = np.mat(x0)
x1 = np.mat(x1)
y = np.mat(y)
x = np.transpose(np.r_[np.mat(np.ones(x0.shape[1])),x0,x1])
theta = np.transpose(np.zeros((1,x.shape[1])))

#设置迭代参数
cnt = 0
iterations = 1000
m = x.shape[0]
alpha = 0.1

#迭代优化模型
while cnt < iterations:
    i = 0
    A =[[]]

    #此步对应于损失函数导数，用梯度下降法求解（小作业：使用拟牛顿法代替该方法）
    while i < theta.shape[0]:
        a = sum(np.multiply((1.0/(1+np.exp(-x*theta)) - np.transpose(y)),x[:,i]))
        i = i + 1
        A = np.c_[A,a]
    theta = theta - (1/m) * alpha * A.transpose()

    #开启此项，则绘制轨迹图
    '''
    plt1 = np.arange(1, 15, 0.1)
    plt2 = -float(theta[0]) / float(theta[2]) - (float(theta[1]) / float(theta[2])) * plt1
    plt.plot(plt1, plt2)
    '''

    cnt = cnt + 1
#迭代结束

#泛化线性分类边际（感谢舍友相助）
plt1 = np.arange(1,15,0.1)
plt2 = -float(theta[0])/float(theta[2]) - (float(theta[1])/float(theta[2]))*plt1

#输出泛化线性分类边际，具体推导见博客
plt.plot(plt1,plt2)

#输出图像（对应博客最终图）
plt.show()
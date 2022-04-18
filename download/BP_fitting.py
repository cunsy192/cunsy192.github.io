#该程序在博客的基础上做了一点调整，主要是做了个动画展现过程
#同时，设置损失项绘图
#缺点很明显，不能任意修改节点数，而且对高级曲线拟合速度较慢，容易出现[梯度爆炸]
#所以，在运行时如果出现无穷大的数字时，记得改小梯度约1-2个数量级，并修改迭代次数
#——村山羊 2020.10.10
import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
import math
import xlrd
import random

#参数设置与本地数据集矩阵化
x = []
y = []
R = 10
i = -10 #可改点下限
j = 0

#输出初始散点图
while j < 21:
    x.append(i)
    y.append(x[j]*x[j]+random.randint(-50,50)/30) #可改生成散点图函数
    j = j + 1
    i = i + 1
plt.scatter(x,y)

#矩阵化数据集
x1 = x
y1 = y
x = np.mat(x)
y = np.mat(y)
x = x.transpose()
y = y.transpose()
#print(x)
#print(y)

#生成隐藏层（生成隐藏层layer1，以便循环时输出output）
B1 = 1 #偏置项常数B1，用于星乘偏置项，默认为1
B2 = 1 #偏置项常数B1，用于星乘偏置项，默认为1
rd1 = np.random.uniform(-1,1,(x.shape[1],3)) #添加随机扰动，此项目的为避免生成奇异阵
theta1 = np.zeros((x.shape[1],3)) + rd1 #生成随机扰动初始化权重矩阵1
b1 = np.ones((x.shape[1],1))*B1 #偏置项列向量，默认为1，星乘B1得到偏置项
layer1 = x*theta1+b1 #隐藏层Layer1的向量表示
rd2 = np.random.uniform(-1,1,(layer1.shape[1],1)) #添加随机扰动，此项目的为避免生成奇异阵
theta2 = np.zeros((layer1.shape[1],1)) + rd2 #生成随机扰动初始化权重矩阵2
b2 = np.ones((x.shape[0],1))*B2 #偏置项列向量，默认为1，星乘B2得到偏置项


#迭代参数

#梯度项，不可更改
Detla1 = 0
Detla2 = 0

#迭代次数，可调整（建议50次以上）
iterations = 100

#学习率/步长，可调整，为小于1的数，建议梯度消失时取较大值，梯度爆炸时取较小值
a = 0.001

#误差项，不可调整
loss = []
k = []

#迭代
while i < iterations:
    #正向传播
    layer1 = x*theta1+b1
    output = layer1*theta2+b2

    #反向传播，过程比较冗长，可改进

    #误差计算
    delta2 = output - y
    delta1 = delta2*theta2.transpose()

    #梯度计算
    Detla2 = (Detla2+layer1.transpose()*delta2)*1/21
    Detla1 = (Detla1+x.transpose()*delta1)*1/21

    #梯度下降
    theta1 = theta1 - a*Detla1
    theta2 = theta2 - a*Detla2
    b1 = b1 - a * delta1
    b2 = b2 - a * delta2

    #开启此项，显示迭代动画
    plt.scatter(x1, y1)
    plt.plot(x, output)
    plt.pause(0.01)
    plt.cla()

    #迭代误差计算
    loss.append(abs(delta2.sum()))
    k.append(i)

    i = i + 1

plt.close('all')

plt.subplot(1,2,1) #如果不计算误差，请关闭此项

plt.scatter(x1, y1)
plt.plot(x,output)
plt.xlabel('x')
plt.ylabel('y')

#如果不输出误差，请关闭以下5项,并关闭上述plt.subplot(1,2,1)项
plt.subplot(1,2,2)
plt.plot(k,loss)
plt.title('Loss')
plt.xlabel('iterations')
plt.ylabel('loss')

plt.show()
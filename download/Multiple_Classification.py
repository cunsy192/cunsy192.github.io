import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
import math
import xlrd
import random

#建立随机数列表（以3个为例）
x0 = []
y0 = []
y1 = []
for i in range(10):
    x0.append(random.randint(0,9))
    y0.append(random.randint(0,15))
    y1.append(0)
for i in range(10):
    x0.append(random.randint(0,9))
    y0.append(random.randint(30,60))
    y1.append(1)
for i in range(10):
    x0.append(random.randint(15,25))
    y0.append(random.randint(10,30))
    y1.append(2)

#绘图
for i in range(30):
    if y1[i] == 0:
        plt.scatter(x0[i],y0[i],marker='o')
    if y1[i] == 1:
        plt.scatter(x0[i],y0[i],marker='^')
    if y1[i] == 2:
        plt.scatter(x0[i],y0[i],marker='s')

#矩阵化
x0 = np.mat(x0)
y0 = np.mat(y0)
x = np.transpose(np.r_[np.mat(np.ones(x0.shape[1])),x0,y0])
theta = np.zeros((3,3)) #升维权重矩阵
a = []
y = np.empty(shape=[0,len(y1)])

#构造并行增扩阵
for i in range(3):
    for j in range(len(y1)):
        if y1[j] != i:
            a.append(1)
        else:
            a.append(0)
    a = np.mat(a)
    y = np.append(y,a,axis=0)
    a = []
y = y.transpose()

#逻辑回归
cnt = 0
iterations = 1001
m = x.shape[0]
alpha = 0.1
while cnt < iterations:
    A = np.empty(shape=[0,theta.shape[0]])
    for i in range(theta.shape[0]):
        b = sum(np.multiply(1.0/(1+np.exp(-x*theta)) - y,x[:,i]))
        A = np.append(A,b,axis=0)
    theta = theta - (1/m) * alpha * A
    cnt = cnt + 1

#绘制决策边际
x3 = np.arange(-10,30,0.1)
for i in range(theta.shape[1]):
    y3 = (-float(theta[0,i])-float(theta[1,i])*x3)/float(theta[2,i])
    plt.plot(x3,y3)

#绘图
plt.show()

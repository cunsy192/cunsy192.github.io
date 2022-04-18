# 本程序仍然为一层三神经元训练图像，打开即可运行（前提是要装以下这些库）
# 在调整图像设置前，请仔细阅读以下文字，以防止不必要的情况发生：
# 1、除设置可更改外，其他项[尽量]不要更改，以免引起程序及计算机崩溃
# 2、本程序激活函数默认为[sigmoid函数]，您可以更改成其他函数
# 3、不要作死调很大的学习率及迭代次数！！！
# 4、在设置界面，[打开]设置为1，[关闭]建议设置为0，以免引起误会
# 5、如有发现程序异常，请联系本人，同时马上关闭程序
# 6、由于采用随机扰动初始矩阵，导致每次的结果不尽相同，但大同小异，偶尔会出现过拟合或者欠拟合现象，多试几次就行了
# 7、当然，你实在嫌麻烦可以直接打开偏置项（过拟合警告！）
# ——村山羊 2020.10.12
import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
import math
import xlrd
import random

# 此项为设置界面（含[open]的为开关，开启请将参数设置为1，[#####]包围的为封装的设置，请一起变更），
# 请在横行包围区域改变参数
# ————————————————————————————————————————#

# ————图像设置————#
R = 10  # 设置标准圆半径作为分界线
kd = 1 / 4  # 选择1/kd圆（以x轴正半轴逆时针旋转，kd<=1）
# 两类数据集间隔请前往68行和79行设置

Raw_Image_open = 0  # 显示初始图像，散点为灰色（图像须手动关闭才能继续程序）
loss_image_open = 1  # 显示误差-迭代次数图

##### 迭代训练图像设置
iterations_image_open = 1  # 迭代训练图像开关，每n次迭代时显示一次训练图像
n = 100  # 每过n次显示一次训练图像
#####

##### 测试点设置
Test_Point_open = 1  # 测试点开关，显示测试点归属范围（红点或蓝点）
test = [1, 1]  # 测试点集，输出为灰色点
#####
# ——————————————#

# ————图像噪点设置————#
Hot_Pixel_open = 1  # 噪点开关
Hot_Pixel_number = 30  # 生成n个噪点（0<=number<=200）
# ——————————————#

# ——BP神经网络训练设置——#
Bias_Terms_open = 0  # 偏置项梯度下降开关（不建议打开，防止过拟合）
iterations = 1000  # 迭代次数
a = 0.1  # 学习率，为小于1的常数
threshold = 0.5  # 阈值，建议为0.5


# —————————————#

# 设置激活函数，输入量为向量
def sigmoid(t):
    x = 1.0 / (1 + np.exp(-t))
    return x


# ————————————————————————————————————————#


# 生成两组数据集，
x0 = []
x1 = []
y = []

# 该组为以原点为圆心，半径为10之内的1/4随机散点实心圆图
i = 0
while i < 100:
    rk1 = R * random.randint(1, 30) / 100
    rk1 = math.sqrt(rk1)
    thetak = kd * 2 * math.pi * random.randint(1, 100) / 100
    x0.append(rk1 * math.cos(thetak))
    x1.append(rk1 * math.sin(thetak))
    y.append(1)
    i = i + 1

# 该组为以原点为圆心，半径为R之外的1/kd随机散点空心心圆图
i = 0
while i < 100:
    rk2 = R * random.randint(150, 500) / 300
    rk2 = math.sqrt(rk2)
    thetak = kd * 2 * math.pi * random.randint(1, 100) / 100
    x0.append(rk2 * math.cos(thetak))
    x1.append(rk2 * math.sin(thetak))
    y.append(0)
    i = i + 1

# 设置噪点，用于“欺骗”神经网络
if Hot_Pixel_open == 1:
    kl0 = 0
    while kl0 < Hot_Pixel_number / 2:
        rd0 = random.randint(0, 100)
        y[rd0] = 0
        kl0 = kl0 + 1
    kl1 = 0
    while kl1 < Hot_Pixel_number / 2:
        rd0 = random.randint(100, 199)
        y[rd0] = 1
        kl1 = kl1 + 1

# 输出原始散点图，未染色
if Raw_Image_open == 1:
    plt.scatter(x0, x1, c='c')
    plt.show()

# 矩阵化
x01 = np.mat(x0)
x11 = np.mat(x1)
x = np.r_[x01, x11]
x = x.transpose()
y1 = y
y = np.mat(y)
y = y.transpose()

# 设置随机初始权重，并生成隐藏层
rd1 = np.random.uniform(-1, 1, (x.shape[1], 3))
theta1 = np.zeros((x.shape[1], 3)) + rd1
b1 = np.ones((x.shape[0], 3))
layer1 = sigmoid(x * theta1 + b1)

# 设置随机初始权重，并生成输出层
rd2 = np.random.uniform(-1, 1, (layer1.shape[1], 1))
theta2 = np.zeros((layer1.shape[1], 1)) + rd2
b2 = np.ones((layer1.shape[0], 1))
output = sigmoid(layer1 * theta2 + b2)

# 迭代固定参数
i = 0  # 当前迭代次数
Detla1 = 0  # 初始梯度
Detla2 = 0  # 初始梯度
loss = []  # 计算损失列表纵坐标
it = []  # 计算损失列表横坐标

# 迭代
while i < iterations:
    # 正向传播
    layer1 = sigmoid(x * theta1 + b1)  # 隐藏层计算
    output = sigmoid(layer1 * theta2 + b2)  # 输出层计算
    delta2 = output - y  # 误差2（总误差）计算

    # 误差2（总误差）计算
    loss.append(abs(delta2.sum()))
    it.append(i)

    # 误差1（隐藏层）误差计算
    k = np.multiply(layer1, 1 - layer1)
    delta1 = np.multiply(delta2 * theta2.transpose(), k)

    # 梯度计算
    Detla2 = (Detla2 + layer1.transpose() * delta2) * 1 / 200
    Detla1 = (Detla1 + x.transpose() * delta1) * 1 / 200

    # 梯度下降
    theta1 = theta1 - a * Detla1
    theta2 = theta2 - a * Detla2

    # 偏置项梯度下降
    if Bias_Terms_open == 1:
        b1 = b1 - a * delta1
        b2 = b2 - a * delta2
    i = i + 1

    # 显示每n次迭代的训练图像
    if i % n == 0 and iterations_image_open == 1:
        output1 = np.array(output)
        j = 0
        while j < x.shape[0]:
            if output1[j] > threshold:
                output1[j] = 1
            else:
                output1[j] = 0
            j = j + 1
        for k in range(200):
            if output1[k] == 1:
                plt.scatter(x0[k], x1[k], c='b')
            if output1[k] == 0:
                plt.scatter(x0[k], x1[k], c='r')
        plt.xlabel('x0')
        plt.ylabel('x1')
        plt.title('iterations=' + str(i))
        plt.pause(0.01)
        plt.clf()

        # 到此一次迭代结束

# 关闭所有图像，这项防止图片超限，可不使用（不保证电脑安全）
plt.close('all')

# 设置阈值，化概率为确定输出值
output1 = np.array(output)
j = 0
while j < x.shape[0]:
    if output1[j] > threshold:
        output1[j] = 1
    else:
        output1[j] = 0
    j = j + 1

# 显示最后训练图像
b = 0
for k in range(200):
    b = b + 1
    if output1[k] == 1:
        plt.scatter(x0[k], x1[k], c='b')
    if output1[k] == 0:
        plt.scatter(x0[k], x1[k], c='r')
plt.xlabel('x0')
plt.ylabel('x1')

if Test_Point_open == 1:
    plt.scatter(test[0], test[1])
    plt.scatter(test[0] + 1, test[1] + 1, c='w')
    plt.annotate('Test Point', xy=(test[0], test[1]), xytext=(test[0] + 1, test[1] + 1),
                 arrowprops=dict(arrowstyle='->'))
    test = np.mat(test)
    b11 = np.ones((test.shape[0], 1))
    layerk1 = sigmoid(test * theta1 + b11)
    b22 = np.ones((layerk1.shape[0], 1))
    layerk2 = sigmoid(layerk1 * theta2 + b22)
    # plt.annotate('Test Point', xy=(test[0], test[1]), xytext=(test[0] + 1, test[1] + 1),arrowprops=dict(arrowstyle='->'))
    if layerk2 < threshold:
        # plt.annotate('Test Point', xy=(test[0], test[1]), xytext=(test[0] + 1, test[1] + 1),arrowprops=dict(arrowstyle='->'))
        plt.title('test:' + ' ' + str(test) + ' is red point')
    else:
        # plt.annotate('Test Point', xy=(test[0], test[1]), xytext=(test[0] + 1, test[1] + 1),arrowprops=dict(arrowstyle='->'))
        plt.title('test:' + ' ' + str(test) + ' is blue point')
    plt.show()

# 不添加这项，则loss图中可能会出现点
plt.close('all')

if loss_image_open == 1:
    plt.plot(it, loss)
    plt.xlabel('iterations')
    plt.ylabel('loss')
    plt.title('loss-iterations image')
    plt.show()

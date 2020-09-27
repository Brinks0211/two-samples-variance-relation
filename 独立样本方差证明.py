import numpy as np
import random
import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
from scipy.stats import *

n=500
mean=50
sd=4
num=range(0,3)
E=[]
X=[]
switch=0

T=np.random.normal(mean,sd,n)  #按正态分布生成随机数列表
T=np.trunc(T).astype(int).tolist()  #列表内数据取整

#for  i in range(0,500):         #重复随机取值500次作为误差
   # i=random.randint(-3,3)
   # E.append(i)

for i in range(0,500):
    i = np.random.normal(0,5)
    E.append(i)    
    E=np.trunc(E).astype(int).tolist() 

for i in range(0,500):
    a=T[i]+E[i]
    X.append(a)

Ex=np.var(X)
Et=np.var(T)
Ee=np.var(E)
switch=Ex-Et-Ee

def plot(nums):
    #nums_new=pd.Series(nums)#将列表转为Series序列便于统计
    #unique_nums=list(nums_new.value_counts().index)#统计值
    #num=list(nums_new.value_counts())#统计值出现的次数
    #plt.bar(unique_nums,num,width=0.5)
    sns.set()#切换到sns默认运行配置
    sns.distplot(nums,bins=20)
    sns.distplot(nums,hist=False,fit=norm)
    plt.show()

print('按平均数为50，标准差为4的正态分布随机生成500个真分数T(便于计算均取整)如下：\n')
print('______________________________________________________________________\n')
print(T)
print('______________________________________________________________________\n')
print('在以0为平均数，标准差为5的正态分布随机取值500次次作为误差E：')
print('______________________________________________________________________\n')
print(E)
print('______________________________________________________________________\n')
print('真分数与误差值对影响相加得观测分数X：\n')
print('______________________________________________________________________\n')
print(X)
print('______________________________________________________________________\n')
print('实测分数X         真分数T          误差E\n')
print('________________________________________________________\n')
for i in range(0,500):
    print("   ",X[i],"          ",T[i],"              ",E[i])
print('________________________________________________________\n')

print("求得观测分数X方差值：",Ex)
print('求得真分数T方差值：',Et)
print('求得误差E方差值：',Ee,'\n')

if switch<=0.05*Ex:
    print("在小于等于总方差5%的误差内，公式成立。\n")
else:
    print('在小于等于总方差5%的误差内，公式不成立。\n')
print('________________________________________________________\n')

plot(X)
plot(T)
plot(E)

input()

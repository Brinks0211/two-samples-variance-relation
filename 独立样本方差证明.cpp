#include<stdlib.h>
#include<stdio.h>
#include<cmath>
#define M 500
#define PI 3.141592654 

double gaussrand( )       //Box-Muller算法取正态分布值 
{
    static double U, V;
    static int phase = 0;
    double Z,mean=50;

    if(phase == 0)
    {
         U = rand() / (RAND_MAX + 1.0);
         V = rand() / (RAND_MAX + 1.0);
         Z = sqrt(-2.0 * log(U))* sin(2.0 * PI * V);
    }
    else
    {
         Z = sqrt(-2.0 * log(U)) * cos(2.0 * PI * V);
    }

    phase = 1 - phase;
    mean=mean+5*Z;
    return mean;
}

double gaussrand1()
{
    static double U, V;
    static int phase = 0;
    double Z;

    if(phase == 0)
    {
         U = rand() / (RAND_MAX + 1.0);
         V = rand() / (RAND_MAX + 1.0);
         Z = sqrt(-2.0 * log(U))* sin(2.0 * PI * V);
    }
    else
    {
         Z = sqrt(-2.0 * log(U)) * cos(2.0 * PI * V);
    }

    phase = 1 - phase;
    Z=5*Z;
    return Z;
}

double variance(int *a)
{
	int j ;
	double aver,sum1=0,var,sum2=0;
	for (j=1;j<=M;j++)
	{sum1=sum1+a[j];}
	aver=sum1/M;
	for (j=1;j<=M;j++)
	{sum2=sum2+(a[j]-aver)*(a[j]-aver);}
	var=sum2/M;
	return var;
}

main()
{
	int X[M],T[M],E[M],i;
	double Ex,Et,Ee;
	for (i=1;i<=500;i++) 
	{
	 T[i]=gaussrand1();
	}
//	printf("%d",T[0]); 
	printf("用Box-Muller算法按正态分布取平均数为50，标准差为5的随机数500个作为真分数T：\n"); 
	printf("______________________________________________________________________________\n");
	for (i=1;i<=M;i++)
	{T[i]=gaussrand();printf("%d   ",T[i]);}
	printf("\n______________________________________________________________________________\n");
	printf("用Box-Muller算法按正态分布取平均数为0，标准差为5的随机数500个作为误差E:\n");
	printf("______________________________________________________________________________\n");
	for (i=1;i<=M;i++)
	{E[i]=gaussrand1();printf("%d   ",E[i]);}
	printf("\n______________________________________________________________________________\n");
	for (i=1;i<=500;i++)
	{X[i]=E[i]+T[i];}
	printf("真分数与误差对应项相加可得观测分数X：\n");
	printf("______________________________________________________________________________\n");
	for (i=1;i<=M;i++)
	{printf("%d   ",X[i]);}
	printf("\n______________________________________________________________________________\n");
	printf("观测分数X		真分数T			误差E\n");
	printf("______________________________________________________________________________\n");
	for (i=1;i<=M;i++)
	{printf("   %d		      	%d	 		 %d\n",X[i],T[i],E[i]);}
	printf("______________________________________________________________________________\n");
	
	Et=variance(T);
	Ee=variance(E);
	Ex=variance(X);
	
	printf("______________________________________________________________________________\n");
	printf("样本实测分数X方差：%f \n",Ex);
	printf("样本真分数T方差：%f \n",Et);
	printf("样本误差E方差：%f \n",Ee);
	printf("\n______________________________________________________________________________\n");
	system("pause");
}

//Box-Muller算法： 
//如果在 （0,1] 值域内有两个独立的均匀分布的随机数字 U1 和 U2，
//可以使用以下两个等式中的任一个算出一个正态分布的随机数字 Z：
//Z0 = R * cos( θ )
//或
//Z1= R * sin( θ )
//其中，
//R = sqrt(-2 * ln(U1))
//θ = 2 * π * U2
//那么Z0和Z1是满足标准正态分布的独立随机数字。 


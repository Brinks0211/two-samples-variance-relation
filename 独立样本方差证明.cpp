#include<stdlib.h>
#include<stdio.h>
#include<cmath>
#define M 500
#define PI 3.141592654 

double gaussrand( )       //Box-Muller�㷨ȡ��̬�ֲ�ֵ 
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
	printf("��Box-Muller�㷨����̬�ֲ�ȡƽ����Ϊ50����׼��Ϊ5�������500����Ϊ�����T��\n"); 
	printf("______________________________________________________________________________\n");
	for (i=1;i<=M;i++)
	{T[i]=gaussrand();printf("%d   ",T[i]);}
	printf("\n______________________________________________________________________________\n");
	printf("��Box-Muller�㷨����̬�ֲ�ȡƽ����Ϊ0����׼��Ϊ5�������500����Ϊ���E:\n");
	printf("______________________________________________________________________________\n");
	for (i=1;i<=M;i++)
	{E[i]=gaussrand1();printf("%d   ",E[i]);}
	printf("\n______________________________________________________________________________\n");
	for (i=1;i<=500;i++)
	{X[i]=E[i]+T[i];}
	printf("�����������Ӧ����ӿɵù۲����X��\n");
	printf("______________________________________________________________________________\n");
	for (i=1;i<=M;i++)
	{printf("%d   ",X[i]);}
	printf("\n______________________________________________________________________________\n");
	printf("�۲����X		�����T			���E\n");
	printf("______________________________________________________________________________\n");
	for (i=1;i<=M;i++)
	{printf("   %d		      	%d	 		 %d\n",X[i],T[i],E[i]);}
	printf("______________________________________________________________________________\n");
	
	Et=variance(T);
	Ee=variance(E);
	Ex=variance(X);
	
	printf("______________________________________________________________________________\n");
	printf("����ʵ�����X���%f \n",Ex);
	printf("���������T���%f \n",Et);
	printf("�������E���%f \n",Ee);
	printf("\n______________________________________________________________________________\n");
	system("pause");
}

//Box-Muller�㷨�� 
//����� ��0,1] ֵ���������������ľ��ȷֲ���������� U1 �� U2��
//����ʹ������������ʽ�е���һ�����һ����̬�ֲ���������� Z��
//Z0 = R * cos( �� )
//��
//Z1= R * sin( �� )
//���У�
//R = sqrt(-2 * ln(U1))
//�� = 2 * �� * U2
//��ôZ0��Z1�������׼��̬�ֲ��Ķ���������֡� 


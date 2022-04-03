/*
题目描述
一个数如果恰好等于不包含它本身所有因子之和，这个数就称为"完数"。 例如，6的因子为1、2、3，而6=1+2+3，因此6是"完数"。 编程序找出N之内的所有完数，并按下面格式输出其因子

输入
N

输出
? its factors are ? ? ?

样例输入
1000
样例输出
6 its factors are 1 2 3 
28 its factors are 1 2 4 7 14 
496 its factors are 1 2 4 8 16 31 62 124 248 
*/

#include <stdio.h>
int main()
{
	int a,b=0;
	scanf("%d",&a);
	for(int i=1;i<a;i++)
	{
		b=0;
		for(int j=1;j<i;j++)
		{
			if(i%j==0)
			{
				b+=j;
			}
		}
		if(i==b)
		{
			printf("%d its factors are",b);
			for(int k=1;k<i;k++)
			{
				if(i%k==0)
				{
					printf(" %d",k);
				}
			}	
			printf("\n");		
		}	
	}			
	return 0;
} 

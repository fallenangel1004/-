#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) 
{
	int i,j,m=0,flag;
	int a[]={0,1,2,3,5,6};//定义两个数组
	int b[]={3,4,5,6,7};
	int c[11];
	
	for(i=0;i<6;i++)//交集 
	{
		for(j=0;j<5;j++)
		{
			if(a[i]==b[j])
			{
				c[m++]=a[i];
				break;
			}
		}
	}
	printf("交集:\n"); 
	for(i=0;i<3;i++)
		printf("%-4d",c[i]); //输出交集
	
	m=0;
	for(i=0;i<6;i++)
	{
		c[i]=a[i];//复制
	} 
	for(i=0;i<5;i++)//并集
	{
		flag=0;
		for(j=0;j<6;j++)//循环
		{
			if(b[i]!=c[j])
			{
				flag++;
			}
			if(flag==6)
			{
				c[6+(m++)]=b[i];
			}
		} 
	} 
	printf("\n并集：\n");//输出并集
	for(i=0;i<8;i++)
		printf("%-4d",c[i]); 
	 
	return 0;
}



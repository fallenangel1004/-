#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) 
{
	int i,j,m=0,flag;
	int a[]={0,1,2,3,5,6};//������������
	int b[]={3,4,5,6,7};
	int c[11];
	
	for(i=0;i<6;i++)//���� 
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
	printf("����:\n"); 
	for(i=0;i<3;i++)
		printf("%-4d",c[i]); //�������
	
	m=0;
	for(i=0;i<6;i++)
	{
		c[i]=a[i];//����
	} 
	for(i=0;i<5;i++)//����
	{
		flag=0;
		for(j=0;j<6;j++)//ѭ��
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
	printf("\n������\n");//�������
	for(i=0;i<8;i++)
		printf("%-4d",c[i]); 
	 
	return 0;
}



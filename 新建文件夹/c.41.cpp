#include <stdio.h>
#include <stdlib.h>

int i;

void reverse(int num[],int n,int a,int b)
{
	int index=-1,index1=-1;
	for(i=0;i<n;i++)
	{
		if(num[i]==a)
		index=i;
		if(num[i]==b)
		index1=i; 
	}
	if(index==-1||index1==-1)
	{
		printf("error\n");
		return ;
	}
	 while(num[index]!=num[index1]){
        index/=2;
        index1/=2;
    }
    if(num[index] == num[index1])
        printf("它们的公共节点是 %d\n",num[index1]);

}

int main()
{
	int n;
	scanf("%d",&n);
	int num[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&num[i]);
	}
	int a,b;
	scanf("%d %d",&a,&b);
	reverse(num,n,a,b);
	return 0;
	
}

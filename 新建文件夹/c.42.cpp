#include <stdio.h>
#include <stdlib.h> 

int i;

void reverse(int num[],int n,int a,int b)
{
	int c=0;
	for(i=0;i<n;i++)
	{
		if(num[i]>a&&num[i]<b)
		c=c+num[i];
	 } 
	 printf("%d\n",c);
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

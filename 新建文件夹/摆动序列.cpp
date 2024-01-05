#include <stdio.h>

int main()
{
	int s[100]={0};
	
	int i=0;
	
	char ch;

	
	while((ch=getchar())!='\n')
	{
		s[i]=ch;
		i++;
	}

	
    int t=i;
    int x=0;

	for(i=0;i<t-1;i++)
	{
		if(s[i]>s[i+1])
		x++;
		else
		x--;
	}
	if(x==t-1||x+t==1)
	printf("不是摆动序列，需要删除 %d 个元素",t-2);
	else
	printf("是摆动序列");
	return 0;
}









#include <stdio.h>
#include <string.h>
int main()
{
	char s[200]={0};
	char ss[100]={0};
	char ch;
	int i=0;
	
	while((ch=getchar())!='\n')
	{
	   	s[i]=ch;
	   	i++;
	}
	printf("%d\n",i);
	i=0;
	int len1=strlen(s);
	
	while((ch=getchar())!='\n')
	{
	   	ss[i]=ch;
	   	i++;
	}
	
	
	int len2=strlen(ss);
	int j;
	int t,x;
	int flag;
	
	for(i=0;i<len1;i++)
	{
		flag=0;
		j=0;
		if(s[i]==ss[0])
		{
			t=i;
			x=t;
			flag=1;
			for(j=0;j<len2;j++)
			{
				if(flag==len2)
					printf("%d",t+1);
				if(s[x+1]==ss[j+1])
				{
					x++;
					flag++;
				}
				else
				break;
			}
		}
	}

	
	return 0;
	
}














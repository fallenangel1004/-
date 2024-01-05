#include <stdio.h>
#include <string.h>
int main()
{
	char s[2],ss[2];
	char ch;
	int i=0;
	
	while((ch=getchar())!='\n')
	{
	   	s[i]=ch;
	   	i++;
	}

    i=0;
    
    
	while((ch=getchar())!='\n')
	{
	   	ss[i]=ch;
	   	i++;
	}
	if(s[0]==ss[0]||ss[0]=='.')
	{
		if(s[1]==ss[1]||ss[1]=='*')
		printf("true\n");
		else
		printf("false");
	}
	
	return 0;
}






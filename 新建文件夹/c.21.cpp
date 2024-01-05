#include <stdio.h>
#include <string.h>
int main()
{
	int s[100]={0};
	int ss[100]={0};
	
	int i=0;
	
	while(1){
		scanf("%d",&s[i]);
	   	i++;
	   	if(getchar()=='\n')
	   	break;
	}
	
	i=0;
	
	while(1){
		scanf("%d",&ss[i]);
	   	i++;
	   	if(getchar()=='\n')
	   	break;
	}
	
int t=i/2;
printf("%d\n",t);
	
	float x=(s[t]+ss[t])/2.0;
	
	printf("%.1f",x);
	return 0;
}















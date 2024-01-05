#include <stdio.h>
#include <string.h>
int main()
{
	float x;
	
	int ch;
	
	do
	{
		scanf("%f",&x);
		x=x*100;
		if(x==3.00)
		printf("A ");
		if(x==6.00)
		printf("B ");
		if(x==9.00)
		printf("C ");
		if(x==15.00)
		printf("D ");
		if(x==17.00)
		printf("E ");
		
	}while((ch=getchar())!='\n');
	
	
	return 0;
	
	
}




#include <stdio.h>

void shell(int s[],int n)
{
	int i,j,gap,tmp;
	for(gap=n/2;gap>0;gap/=2)
{
	for(i=gap;i<n;i++)
	{
		tmp=s[i];
		for(j=i;j>=gap&&s[j-gap]>tmp;j-=gap)
		{
			s[j]=s[j-gap];
		
		}
		s[j]=tmp;
	}
}

}

int main()
{
	int n,i;
	int s[]={6, 12, 458, 5, 4, 28, 19, 1230, 9, 47};

	n=sizeof(s)/sizeof(s[0]);
    shell(s,n);
	
	for(i=0;i<n;i++)
	printf(" %d",s[i]);
	
	return 0;
}





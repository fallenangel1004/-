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
	printf("���ǰڶ����У���Ҫɾ�� %d ��Ԫ��",t-2);
	else
	printf("�ǰڶ�����");
	return 0;
}









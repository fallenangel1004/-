#include <stdio.h>
#include <string.h>
int isprime(char s[],int i,int j){//�ж��Ƿ�Ϊ�����ַ��� 
	
	while(i<j)
	{
		if(s[i]!=s[j]){
			return 0;
		}
		i++;
		j--;
	}
	if(i>=j){
		return 1;
	}
}
 
int main()
{
	char s[1000];//������ַ��� 
	char max[1000];//��������ַ����������� 
	char t[1000];//�������ַ��������� 
	gets(s);
	int l=strlen(s),maxl=1,m;
	
	
	int i,j,k;
	if(l<2){//�������Ϊ1��ֱ����� 
		printf("%s",s);
	}
	for(i=0;i<=l;i++){
		for(j=i+1;j<l;j++){//�����ж�ÿ�����ַ��� 
			int num=0;
			for(k=i;k<=j;k++){
				t[num++]=s[k];	
			}
			t[num]='\0';//��ÿ�����ַ���������t�� 
			int lt=strlen(t);
			if(isprime(s,i,j)==1&&lt>maxl){//����ж������ַ����ǻ����ַ������ҳ��ȴ�����һ��max 
				strcpy(max,t);//��������ַ������Ƶ�����max 
				maxl=lt;
			}
			strcpy(t,"");//����ַ��� 
		}
	}
	 
	
	printf("%s",max);
	return 0;
}

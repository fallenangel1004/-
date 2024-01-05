#include <stdio.h>
#include <string.h>
int isprime(char s[],int i,int j){//判断是否为回文字符串 
	
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
	char s[1000];//输入的字符串 
	char max[1000];//储存最大字符串长度数组 
	char t[1000];//储存子字符串的数组 
	gets(s);
	int l=strlen(s),maxl=1,m;
	
	
	int i,j,k;
	if(l<2){//如果长度为1；直接输出 
		printf("%s",s);
	}
	for(i=0;i<=l;i++){
		for(j=i+1;j<l;j++){//遍历判断每个子字符串 
			int num=0;
			for(k=i;k<=j;k++){
				t[num++]=s[k];	
			}
			t[num]='\0';//将每个子字符串储存在t中 
			int lt=strlen(t);
			if(isprime(s,i,j)==1&&lt>maxl){//如果判断了子字符串是回文字符串并且长度大于上一个max 
				strcpy(max,t);//将这个子字符串复制到数组max 
				maxl=lt;
			}
			strcpy(t,"");//清空字符串 
		}
	}
	 
	
	printf("%s",max);
	return 0;
}

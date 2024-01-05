#include <stdio.h>  
int stack[100],top;  
int out[100];  
int check(int n)  
{  
    int po=0;  
    for(int i=1;i<=n;i++)  
    {  
        for(int j=po+1;j<=out[i];j++)  
        {  
            po=j;  
            stack[top++]=j;  
        }  
        if(stack[--top]!=out[i])  
        return 0;  
    }  
    return 1;  
}  
int main()  
{  
    int n;  
    scanf("%d",&n);
    for(int i=1;i<=n;i++)  
    {  
        scanf("%d",&out[i]);  
    }  
    if(check(n))  
    printf("是合法的出栈序列\n");  
    else  
    printf("不是合法的出栈序列\n");  
    return 0;  
}  

#include<stdio.h>
#include<stdlib.h>
#define max 100
#define ele int
#define ver int
void find(int num[],int n,int a,int b){
    int index1=-1,index2=-1;
    for(int i=1;i<=n;i++){
        if(num[i]==a)
            index1=i;
        if(num[i]==b)
            index2=i;
    }
    if(index1==-1 || index2==-1){
        printf("They don`t have a same gradeparents.\n");
        return ;
    }
    while(num[index1]!=num[index2]){
        index1/=2;
        index2/=2;
    }
    if(num[index1] == num[index2])
        printf("这两个节点的最近公共祖先的编号是 %d\n",num[index1]);
}
int main(){
    int n;
    scanf("%d",&n);
    int num[n+1];
    for(int i=1;i<=n;i++){
        scanf("%d",&num[i]);
    }
    printf("Find the Same gradeparents.\n");
    int a,b;
    scanf("%d %d",&a,&b);
    find(num,n,a,b);
    return 0;
}














#include<stdio.h>
#include<string.h>
void sentence(char*p1)
{
 char*p2;
 if(p1[0]>='a'&&p1[0]<='z')
  p1[0]-=32;
 while(*p1)
{
   p2=p1+1;
   if(*p1==' ')
   {
     while(*p2==' ')
       {p2++;}
    strcpy(p1,p2-1);
    }
    p1++;
}
  *p1='.';
  *(p1+1)='\0';
}
int main()
{
  char str[100]={0},ch;
  gets(str);
  sentence(str);
  puts(str);
}


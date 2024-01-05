#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct s
{
	int num;
	struct s *next;
}ss;

 ss*creat ()
{
	ss *head;
	ss *p,*q;
	p=q=(ss*)malloc(sizeof(ss));
	head=(ss*)malloc(sizeof(ss));
	scanf("%d",&p->num);
    int i=0;
	while(p->num!=0)	
	{
		i++;
		if(i==1)
		{
			head->next=p;
		}
		else
		q->next=p;
		
   	
   	q=p;
   	p=(ss*)malloc(sizeof(ss));
   	scanf("%d",&p->num);
   	if(i==10)
   	break;
   }
   q->next=NULL;
   return head;
	
}


void print(ss *head)
{
	ss *tt=head->next;
	printf("\n");
	while(tt!=NULL)
	{
		printf("%ld\t",tt->num);
		tt=tt->next;
	}
	printf("\n");
}


void sep(ss *a,ss *&b)
{
	ss *heada=a->next;
	ss *pre=a;
	b=(ss*)malloc(sizeof(ss));
	b->next=NULL;
	ss *headb=b;
	ss *dele;
	while(heada!=NULL)
	{
		if(heada->num%2!=0)
		{
			pre=heada;
			heada=heada->next;
		}
		else
		{
			dele=heada;
			pre->next=dele->next;
			heada=heada->next;
			headb->next=dele;
			headb=dele;
		}
	}
	headb->next=NULL;
}


int main()
{
	ss *list,*list2;
	list=creat();
	list2=list;
	print(list);
	
	sep(list,list2);
	print(list);
	print(list2);
	
	return 0;
}































#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 struct node
{
struct node *next;
int data;
};
void makeset();
void display();
int find(int);
void unions();
struct node *first[30];
int n;
void main()
{
	int i,ch,x,y;
	struct node *ne;
	printf("Enter number :");
	scanf("%d",&n);
for(i=0;i<n;i++)
	{
	ne=(struct node *)malloc(sizeof(struct node));
	ne->next=NULL;
    	ne->data=i+1;
	first[i]=ne;
	}
display();

	do
	{
	printf("\n--MENU--\n1.Display\n2.Union\n3.Find\n4.Makeset\n5.Exit \nChoose operation :");
	scanf("%d",&ch);
		switch(ch)
			{
	  	        case 1:display();
		                break;
		        case 2:unions();
		                break;
		        case 3:printf("Enter the element to Find\n");
                        scanf("%d",&x);
                        i=find(x);\
                        if(i==-1)
                        printf("No such element\n");
                        else
                        printf("Element PRESENT in set-> %d\n",first[i]->data);
                        break;
		         case 4:makeset();
		                break;
			}
	}
	while(ch!=5);
}
void makeset()
	{
	int pos,x;
	pos=find(x);
	printf("Enter the number :");
	scanf("%d",&x);
	pos=find(x);
	 if (pos==-1)
		{
   		 first[n]=(struct node *)malloc(sizeof(struct node));
    		 first[n]->data=x;
    		 first[n]->next=NULL;
   		 n++;
		}
   	else
      		printf("\n The no: exits in another set");
	}
void display()
	{
	struct node *p;
	int i;
	printf("The Sets are :");
	for(i=0;i<n;i++)
	{
		p=first[i];
		if (p==NULL)
		 continue;
	   	printf("{");	
		while(p!=NULL)
		{
	      	printf("%d ",p->data);
	       	p=p->next;
	     	}
	     printf("}\n");
	  }
	}
void unions()
{
int a,b,i,j;
struct node *p;
printf("\nEnter the first element:");
scanf("%d",&a);
printf("\nEnter the second element:");
scanf("%d",&b);
i=find(a);
j=find(b);
if (i==-1 || j ==-1)
{
printf("element not found");
return;
}
if (i==j)
printf("Both are in the same set");
else
{
p=first[i];
while(p->next!=NULL)
p=p->next;
p->next=first[j];
first[j]=NULL;
}
}
int find(int x)
{
struct node *p;
int i,j,flag;
flag=0;
  for(i=0;i<n;i++)
	{
	p=first[i];
	     while(p!=NULL)
		{
	       if (p->data==x)
		{
			flag=1;   break;
		 }
		p=p->next;
		}
	     if (flag==1)
		break;
	}
if (flag==1)
      return i;
   else
       return -1;
}

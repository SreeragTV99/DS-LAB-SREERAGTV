#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define inf 999
void addtoadjlist(int s,int en,int w);
int emptyQ();
int extractminQ();
struct node
{  
	int vertex;
    int weight;
    struct node *next;
}*adj[20];
int v;
int p[20],key[20],q[20];

int main()
{
	int i,s,en,we,e,u,w,sum=0;
    struct node *ptr;
    printf("Enter No. of vertices: ");
    scanf("%d",&v);
    for(i=1;i<=v;i++)
    { 
		p[i]=0;
    	key[i]=inf;
    	q[i]=1;
    	adj[i]=NULL;
    }
    printf("No: of edges: ");
    scanf("%d",&e);
    printf("Enter the Edges\n");
    printf("start end weight\n");
    for(i=1;i<=e;i++)
    {
		scanf("%d%d%d",&s,&en,&we);
    	addtoadjlist(s,en,we);
    	addtoadjlist(en,s,we);
   	}
   	key[1]=0;
   	while(!emptyQ())
   	{
   		u=extractminQ();
      	ptr=adj[u];
      	while(ptr!=NULL)
      	{ 
			w=ptr->vertex;
	 		if (q[w]==1 && ptr->weight < key[w])
	  		{
				key[w]=ptr->weight;
	    		p[w]=u;
	  		}
	  	ptr=ptr->next;
      	}
  	}
  	sum=0;
  	printf("Spanning tree edges\n");
  	for(i=2;i<=v;i++)
  	{  
		printf("(%d-%d) w:%d \n",i,p[i],key[i]);
      	sum=sum+key[i];
   	}
   	printf("The total cost is %d",sum);
  	getch();
}
int emptyQ()
{  
	int i,flag=1;
	for(i=1;i<=v;i++)
 	{
		if (q[i]==1)
       	{
		    flag=0;
			break;
       	}
  	}
  	return flag;
}
int extractminQ()
{ 
	int i,min=inf,ver;
   	for(i=1;i<=v;i++)
   	{
		if (key[i]<min && q[i]==1)
      	{	
			ver=i;
			min=key[i];
       	}
    }
	q[ver]=0;
    return ver;
}
void addtoadjlist(int s,int en,int w)
{
    struct node *ne=(struct node *)malloc(sizeof(struct node));
    ne->vertex=en;
    ne->weight=w;
    ne->next=adj[s];
    adj[s]=ne;
}

#include<stdlib.h>
#include<stdio.h>

struct node {
int data;
struct node *next;
};

struct edge {
int start;
int weight;
int end;
};

void makeset(int x);
void unionset(int a,int b);
int find(int);
int n=0;
struct node *first[20];
struct edge adj[20],a[20];


void main()
{
int v,e,c=-1,s,count=0,i,start,end,weight,k,v1,u,w;
printf("\nENTER THE NUMBER OF VERTICES:");
scanf("%d",&v);
for(i=1;i<=v;i++)
{
    makeset(i);
}
printf("\nENTER THE NUMBER OF EDGES:");
scanf("%d",&e);
printf("\nENTER THE EDGES:\n");
printf("\nSTART\tEND\tWEIGHT\n");

for(i=0;i<e;i++)
{
scanf("%d%d%d",&start,&end,&weight);
for(k=c;k>=0;k--)
if(adj[k].weight>weight)
adj[k+1]=adj[k];
else
break;

adj[k+1].start=start;
adj[k+1].end=end;
adj[k+1].weight=weight;
c++;
}
count=0;
for(i=0;i<c;i++)
{
u=adj[i].start;
v1=adj[i].end;
w=adj[i].weight;
if(find(u)!=find(v1))
{
    a[count].start=u;
    a[count].end=v1;
    a[count].weight=w;
    count++;
    unionset(u,v1);
}
}
printf("SPANNING TREE EDGES:\n");
s=0;
for(i=0;i<count;i++)
{
    printf("%d->%d\tw-%d\n",a[i].start,a[i].end,a[i].weight);
    s=s+a[i].weight;
}
printf("\nTotal cost=%d",s);
}

void makeset(int x)
{
int pos;
pos=find(x);

if (pos==-1)
{
    first[n]=(struct node *)malloc(sizeof(struct node *));
    first[n]->data=x;
    first[n]->next=NULL;
    n++;
}
else
    printf("ELEMENT ALREADY EXIST.\n");
}

int find(int x)
{
int i,flag=0;
struct node *p;
for(i=0;i<n;i++)
{
p=first[i];
while(p!=NULL)
{
if(p->data==x)
{
    flag=1;
    break;
}
p=p->next;
}
if (flag==1)
    break;
}
if(flag==1)
    return i;
else
    return -1;
}

void unionset(int a,int b)
{
int i,j;
struct node *p;

i=find(a);
j=find(b);
if (i==-1 || j ==-1)
{
    printf("ELEMENT NOT FOUND.\n");
    return;
}
if (i==j)
    printf("BOTH ARE IN SAME SET.\n");
else
{
    p=first[i];
    while(p->next!=NULL)
    p=p->next;
    p->next=first[j];
    first[j]=NULL;
}
}

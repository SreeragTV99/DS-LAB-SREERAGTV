#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node
{
	int vertex;
	struct node *next;
};
int v,e;
struct node *adj[20], *adj1[20];
int t=0,visited[20],ft[20];
void dfs();
void dfsvisit(int);
void dfs1();
void dfsvisit1(int);
void adjlistrep(struct node **adj,int s,int en)
{
	struct node *ne=(struct node*)malloc(sizeof(struct node));
	ne->vertex=en;
	ne->next=adj[s];
	adj[s]=ne;
}

void main()
{
	int s,i,en;
	struct node *ptr;
	printf("Enter no. of vertices : ");
	scanf("%d",&v);
	for(i=0;i<=v;i++)
		adj[i]=adj1[i]=NULL;
	printf("Enter no. of edges : ");
	scanf("%d",&e);
	printf("Enter the edges\n");
	printf("Start End\n");
	for(i=0;i<e;i++)
	{
		scanf("%d%d",&s,&en);
		adjlistrep(adj,s,en);
		adjlistrep(adj1,en,s);
	}
	dfs();
	dfs1();
	getch();
}

void dfs()
{
	int i;
	for(i=0;i<=v;i++)
		visited[i]=0;
	printf("\nDFS\n");
	for(i=1;i<=v;i++)
	{
		if(visited[i]==0)
		{
			dfsvisit(i);
		}
	}
}

void dfsvisit(int u)
{
	int w;
	struct node *ptr;
	visited[u]=1;
	printf("%d ",u);
	ptr=adj[u];
	while(ptr!=NULL)
	{
		w=ptr->vertex;
		if(visited[w]==0)
			dfsvisit(w);
		ptr=ptr->next;
	}
	t++;
	ft[u]=t;
}

void dfs1()
{
	int i,max=0,ver;
	printf("\n--Components--\n");
	for(i=0;i<=v;i++)
		visited[i]=0;
	while(1)
	{
		max=0;
		for(i=1;i<=v;i++)
		{
			if(visited[i]==0 && ft[i]>max)
			{
				ver=i;
				max=ft[i];
			}
		}
		if(max==0)
			break;
		printf("{");
		dfsvisit1(ver);
		printf("}\n");
	}
}
void dfsvisit1(int u)
{
	int w;
	struct node *ptr;
	visited[u]=1;
	printf("%d ",u);
	ptr=adj1[u];
	while(ptr!=NULL)
	{
		w=ptr->vertex;
		if(visited[w]==0)
			dfsvisit1(w);
		ptr=ptr->next;
	}
}

#include<stdio.h>
#include<conio.h>
#define inf 999
void printpath(int,int);
int extractmin();
int v,adj[20][20],dist[20],visit[20],pred[20];
void main()
{
int e,st,en,w,i,j,src,ver,k;
//clrscr();
printf("Enter the no. of vertices : ");
scanf("%d",&v);
printf("Enter the no. of edges : ");
scanf("%d",&e);
	for(i=0;i<=v;i++)
	{
		for(j=0;j<=v;j++)
adj[i][j]=inf;
dist[i]=inf;
visit[i]=0;
	}
	printf("Enter the edges\n");
	printf("start end weight\n");
	for(i=1;i<=e;i++)
	{
	 	scanf("%d%d%d",&st,&en,&w);
	 	adj[st][en]=w;
	}
	printf("Enter the starting vertex : ");
	scanf("%d",&src);
	dist[src]=0;
	pred[src]=src;
	for(k=1;k<=v;k++)
	{
	 	ver=extractmin();
		visit[ver]=1;
	    if (dist[ver]==inf) continue;
	    for(i=1;i<=v;i++)
	    {
	    	if (adj[ver][i]!=inf&& visit[i]==0 )
		  		if (dist[i]>dist[ver]+adj[ver][i])
			   	{
				   dist[i]=dist[ver]+adj[ver][i] ;
			       pred[i]=ver;
			   	}
		}
	}
	for(i=1;i<=v;i++)
	{
		if (dist[i]==inf)
			continue;
	    printf("path cost to %d= %d   ",i,dist[i]);
	    if( dist[i]!=inf)
	    {
		    printpath(i,src);
		    printf("->%d",i);
		    printf("\n");
	    }
	}
   getch();
}
void printpath(int i,int src)
{
	if (pred[i]==src)
    {  
		printf("%d ",src);return;
    }
    printpath(pred[i],src);
    printf("->%d  ",pred[i]);
}
int extractmin()
{
	int min=inf,i,ver;
    for(i=1;i<=v;i++)
    {
		if (visit[i]==0 && dist[i]<min)
		{
			min=dist[i];
	   		ver=i;
		}
    }
    return ver;
}

#include<stdlib.h>
#include<stdio.h>
struct node
{ 
int vertex;
struct node *next;
};
int v,e;
struct node **adj;
int que[30],visited[30];
int f=-1,r=-1;
void enq(int x)
{ if (f==-1 && r==-1)
f=0;
r=(r+1)%v;
que[r]=x;
}
int dequ()
{
 int data;
data=que[f];
if (f==r)
f=r=-1;
else
f=(f+1)%v;
return data;
}
void bfs(){
 struct node *ptr;
int ver,i,w;
for(i=0;i<=v;i++)
visited[i]=0;
enq(1);
visited[1]=1;
printf("%d ",1);
while(!(f==-1)){
 ver=dequ();
ptr=adj[ver];
while(ptr!=NULL){ 
w=ptr->vertex;
if (visited[w]==0){
 enq(w);
printf("%d ",w);
visited[w]=1;
}
ptr=ptr->next;
}
}
}
void main()
{ 
int s,i,en;
struct node *ne;
printf("Enter No of vertices : ");
scanf("%d",&v);
adj= (struct node **)malloc((v+1)*sizeof(struct node *));
for(i=0;i<=v;i++)
adj[i]=NULL;
printf("enter No of Edges : ");
scanf("%d",&e);
printf("Enter the edges :\n");
printf("Start End\n");
for(i=0;i<e;i++){ 
scanf("%d%d",&s,&en);
ne=(struct node*)malloc(sizeof(struct node));
ne->vertex=en;
ne->next=adj[s];
adj[s]= ne;
}
printf("\n-BFS-\n");
bfs();
}

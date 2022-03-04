#include<stdio.h>
int front=-1,rear=-1,SIZE=4;
void insert(int *);
void delete(int *);
void search(int *);
void display(int *q);
void main()
{
        int q[4],opt;
        do
        {
                printf("\n---MENU---\n");
                printf("\n1.INSERT\n2.DELETE\n3.SEARCH\n4.DISPLAY\n5.EXIT\n\nEnter Your Choice :");
                scanf("%d",&opt);
                switch(opt)
                {
                        case 1:insert(q);
                                break;
                        case 2:delete(q);
                                break;
                        case 3:search(q);
                                break;
                        case 4:display(q);
                                break;
                }
        }
        while(opt!=5);
}
void insert(int *q)
{
        if(front==(rear+1)%SIZE)
        {
                printf("Queue is Full !!!\n");
                return;
        }
        if(front==-1)
                front=0;
        rear=(rear+1)%SIZE;
        printf("Enter The Element to Insert : ");
        scanf("%d", &q[rear]);           
}
void delete(int *q)
{
        if(front==-1)
        {
                printf("Queue is empty !!!.\n");
                return;
        }
        printf("Deleted Element is %d", q[front]);
        if(front==rear)
                front=rear=-1;
        else
                front=(front+1)%SIZE;
                return;
}
void search(int *q)
{
        int se,f;
        printf("Enter the element to search : ");
	scanf("%d",&se);
        if(front==-1)
        {
                printf("Queue is empty !!!");
                return;
        }
        f=front;
        while(1)
        {
                if(se==q[f])
                {
                        printf("Element Found.");
                        break;
                }
                if(f=rear)
                {
                        printf("Element not found !!!");
                        break;
                }
                f=(f+1)%SIZE;
        }    
}
void display(int *q)
{
        int f;
        if(front==-1)
        {
                printf("Queue is empty !!!");
                return;
        }
        f=front;
        while(1)
        {
                printf("%d ", q[f]);
                if(f==rear)
                        break;
                f=(f+1)%SIZE;                     
        }
}

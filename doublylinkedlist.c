#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *left;
	struct node *right;
};
struct node*head=NULL;

void finsert(int);
void linsert(int);
void fdelete();
void ldelete();
void display();
void insertpos();
void deletepos();
void search();

void main()
{
int opt,q;
do
{
	printf("\n---MENU---\n");
	printf("\n1.INSERT AT FIRST \n2.INSERT AT LAST \n3.DISPLAY \n4.DELETE FIRST \n5.DELETE LAST \n6.INSERT POSITION\n7.DELETE POSITION\n8.SEARCH\n9.EXIT\nChoose operation :");
	scanf("%d",&opt);
	switch(opt)
	{
			
		case 1:
				finsert(q);
				break;
		case 2:
				linsert(q);
				break;
		case 3:
				display();
				break;
		case 4:
				fdelete(q);
				break;
		case 5:
				ldelete(q);
				break;
		case 6:
				insertpos();
				break;
		case 7:
				deletepos();
				break;
		case 8:
				search();
				break;	
	}
}
while(opt!=9);
}
void finsert(int q)
{
	struct node *ne;
	ne=(struct node *)malloc(sizeof(struct node));
	if(ne == NULL)
	{
	        printf("Insufficient memory!!!");
	}
	printf("Enter the element to insert at first:\n");
	scanf("%d",&q);
	
	ne->data = q;
	        ne->left = NULL;
	        ne->right = NULL;
	if(head == NULL)
	{
               head=ne; 
	}
	else
        {
                ne->right=head;
                head->left=ne;
                head=ne;
}
}
void linsert(int q)
{
        struct node *ne,*ptr;
	ne=(struct node *)malloc(sizeof(struct node));
	if(ne == NULL)
		{
		printf("Insufficient memory!!!");
		}
	printf("Enter the element to insert at last:\n");
	scanf("%d",&q);
	
	ne->data = q;
	        ne->right=NULL;
	        ne->left=NULL;
	
	if(head == NULL)
	{
	        head=ne;
	}
	else
	{
	        ptr=head;
	        while(ptr->right!=NULL)
	        {
	                ptr=ptr->right;
	        }
	        ptr->right=ne;
	        ne->left=ptr;
	}
}
void display()
{
        struct node *ptr;    
        if(head==NULL)
        {
                printf("List Empty!!!");
        }
        else
                ptr=head;
                while(ptr!=NULL)
                {
                        printf("%d\n",ptr->data);
                        ptr=ptr->right;
                }    
}

void fdelete(int q)
{
	struct node *ptr;
	if(head==NULL)
	{
		printf("List is Empty!!!");
	}
	else
	{
		ptr=head;
		head=head->right;
	}
	if(head==NULL)
	{
		head->left=NULL;
	}
	free(ptr);
}

void ldelete(int q)
{
	struct node *ptr;
	struct node *prev;
	if(head==NULL)
	{
		printf("List is Empty!!!");
	}
	if(head->right==NULL)
	{
		free(head);
		head=NULL;
	}
	else
	{
		ptr=head;
	}
	while(ptr->right!=NULL)
	{
		ptr=ptr->right;
	}
	prev=ptr->left;
	prev->right=NULL;
	free(ptr);  
}

void insertpos()
{
	struct node *ne;
	struct node *ptr,*ptr1;
	int x,key;
	printf("Enter the element to INSERT :\n");
	scanf("%d",&x);
	printf("Enter the position where you want to insert item: ");
    scanf("%d", &key);
	ne=(struct node *)malloc(sizeof(struct node));
	if (ne == NULL)
	{
		printf("Insufficient Memory!!!") ;
		return;
	}
	ne->data=x;
	ne->left=NULL;
	ne->right=NULL;
	if(head == NULL)
	{
		head=ne;
		return;
	}
	ptr = head;
	while(ptr->data!=key&&ptr->right!=NULL)
	{
		ptr=ptr->right;
	}
	if(ptr->right==NULL)
	{
		ptr->right=ne;
		ne->left=ptr;
	}
	else
	{
		ne->left=ptr;
		ne->right=ptr->right;
		ptr1=ptr->right;
		ptr->right=ne;
		ne->left=ne;
	}
}

void deletepos()
{
  	struct node *ptr;
	struct node *prev;
	struct node *next;
	int x;
	if (head == NULL)
	{
		printf("Linked List is Empty!!!") ;
		
	}
	printf("Enter the position where you want to DELETE item: ");
	scanf("%d", &x);
	if(head->data==x)
	{
		ptr = head;
		head = head->right;
		if (head != NULL)
		{
			head->left=NULL;
		}
		free(ptr);	
	}
	else
	{
		ptr = head;
		while(ptr->data != x && ptr->right!=NULL)
		{
			ptr=ptr->right;
		}
		if(ptr!=NULL)
		{
			prev=ptr->left;
			next=ptr->right;
			prev->right=ptr->right;
		}

		if(prev->right!=NULL)
		{
			next->left=ptr->left;
			free(ptr);
		}
	}        
}

void search()
{
	struct node *ptr;
	int x;
	printf("Enter the element to search :\n");
	scanf("%d",&x);
	if (head == NULL)
	{
		printf("Linked List is Empty!!!") ;
		return;
	}
	else
	{
		ptr=head;
		while(ptr!=NULL)
		{
		if(ptr->data==x)
		{
			printf("Element Found.");
			printf("\n");
			break;
		}
		ptr=ptr->right;
		}
		if(ptr==NULL)
		{
			printf("Element Not Found!!!");
			printf("\n");
		}	
	}
}






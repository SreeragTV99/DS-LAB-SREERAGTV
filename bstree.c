#include<stdio.h>
#include<stdlib.h>

struct node
{
int data;
struct node *next;
struct node *right;
struct node *left;
};
struct node *ROOT=NULL;
int preorder(struct node *);
int postorder(struct node *);
int inorder(struct node *);
int insert(int);
void delet(int);
int search();
int main()
{
int opt,x;
do
{
printf("\n---MENU---\n");
printf("\n1.PREORDER \n2.POSTORDER \n3.INORDER\n4.INSERT\n5.DELETE\n6.SEARCH\n6.EXIT\nENTER THE OPTION :");
scanf("%d",&opt);
	switch(opt)
		{
  		case 1:
                        preorder(ROOT);
                        break;
                case 2:
                        postorder(ROOT);
                        break;
	  	case 3:
                        inorder(ROOT);
                        break;
		case 4:
                        insert(x);
                        break;
                case 5:
                	printf("Enter data to delete :");
                	scanf("%d",&x);
                	delet(x);
                	break;
                case 6: 
                        search();
                        break;
		}
}
while(opt!=7);
}
int inorder(struct node *ptr)
{

	if(ptr!=NULL)
	{
                inorder(ptr->left);
                printf("%d\t",ptr->data);
                inorder(ptr->right);
        }
}

int preorder(struct node *ptr)
{

	if (ptr!=NULL)
        {
        printf("%d\t",ptr->data);
        preorder(ptr->left);
        preorder(ptr->right);
        }
}

int postorder(struct node *ptr)
{
	if (ptr!=NULL)
{

postorder(ptr->left);
postorder(ptr->right);
printf("%d\t",ptr->data);

}
}
int search()
{
	int x;
	struct node *ptr=ROOT;
	printf("Enter data to search :");
        	scanf("%d",&x);
while(ptr!=NULL)
{

if(ptr->data==x)
{
        printf("Data Present.");
        break;
}
if(x>ptr->data)
        ptr=ptr->right;
else
        ptr=ptr->left;
}

if(ptr==NULL)
        printf("Data not present!!!");
}


int insert(int x)
{
	struct node *ne,*ptr,*ptr1;
	ne=(struct node*)malloc(sizeof(struct node));

	if (ne==NULL)
	{

	printf("\nInsufficient Memory!!!");

	}
	printf("Enter data to INSERT :");
        	scanf("%d",&x);
 	ne->right=ne->left=NULL;
	ne->data=x;
if(ROOT==NULL)
	{

	ROOT=ne;
	}
	ptr=ROOT;
 while(ptr!=NULL)
 {
 
	if (x==ptr->data)
	{

	printf("Item present in the tree.");
	break;
	}

if(x>ptr->data)
        {
        ptr1=ptr;
        ptr=ptr->right;
        }
else
{
        ptr1=ptr;
        ptr=ptr->left;
}
}
if(ptr==NULL)
{

   if(x>ptr1->data)
   {
        ptr1->right=ne;
   }
else
        ptr1->left=ne;
}
}

void delet(int x)
{
        struct node*parent,*p,*ptr;
        int dat;
if(ROOT==NULL)
{
        printf("\nTree is empty!!!");
        return;
}
parent=NULL;
ptr=ROOT;
while(ptr!=NULL)
{
        if(ptr->data==x)
                break;
        parent=ptr;
        if(x>ptr->data)
                ptr=ptr->right;
        else
                ptr=ptr->left;
}
if(ptr==NULL)
{
         printf("Item not found!!!");
         return;
}
if(ptr->right==NULL&&ptr->left==NULL)
{
        if(parent==NULL)
                ROOT=NULL;
        else if(parent->right==ptr)
                parent->right=NULL;
else
        parent->left=NULL;
        printf("Element to delete :");
        free(ptr);
        return;
}
if(ptr->right!=NULL&&ptr->left!=NULL)
{
         p=ptr->right;
         while(p->left!=NULL)
{
 p=p->left;
}
 dat=p->data;
 delet(p->data);
 ptr->data=dat;
 return;
}
if(parent==NULL)
{
         if(ptr->right==NULL)
                ROOT=ptr->left;
         else
                ROOT=ptr->right;
}
else
{
        if(parent->right==ptr)
        {
                 if(ptr->right==NULL)
                        parent->right=ptr->left;
                 else
                        parent->right=ptr->right;
        }
        else
        {
         if(ptr->left==NULL)
         parent->left=ptr->right;
         else
         parent->left=ptr->left;
        }
}
printf("\nElement deleted Successfully.");
free(ptr);
return;
}

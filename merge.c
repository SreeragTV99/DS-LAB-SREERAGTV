#include<stdio.h>
void read(int *,int);
void main()
{
	int a[20],b[20],c[20],i=0,j=0,k=0,n1,n2;
	printf("Enter the no of elements in a :");
	scanf("%d",&n1);
	printf("Enter the elements in a (in sorted order):\n");
	read(a,n1);
	printf("Enter the no of elements in b :");
	scanf("%d",&n2);
	printf("Enter the elements in b (in sorted order):\n");
	read(b,n2);
	i=0;
	while(i<n1 && j<n2)
	{
		if(a[i]<b[j])
			{
			c[k]=a[i];
			k++;
			i++;
			}
		else if(a[i]>b[j])
			{
			c[k]=b[j];
			k++;
			j++;
			}
		else
			{
			c[k]=a[i];
			}

	}
	while(i<n1)
		{
		c[k]=a[i];
		i++;
		k++;
		}
	while(j<n2)
		{
		c[k]=b[j];
		j++;
		k++;
		}
	for(i=0;i<k;i++)
		{
		printf("%d\t",c[i]);
		}
	printf("\n");
}
void read(int *p,int y)
{
int j;
	for(j=0;j<y;j++)
	{
	scanf("%d",&p[j]);
	}
}


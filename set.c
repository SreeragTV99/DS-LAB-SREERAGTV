#include<stdlib.h>
#include<stdio.h>
#include<string.h>
void setunion(char *,char *,char *);
void setintersection(char *,char *,char *);
void setdifference(char *,char *,char *);

void main()
{
char s1[20],s2[20],s3[20];
printf("Enter Set-1 :\n");
scanf("%s",s1);
printf("Enter Set-2 :\n");
scanf("%s",s2);
//check whether the two strings are equal or not
setunion(s1,s2,s3);
printf("\nUNION\n%s",s3);
setintersection(s1,s2,s3);
printf("\nINTERSECTION\n%s",s3);
setdifference(s1,s2,s3);
printf("\nSETDIFFERENCE\n%s",s3);
}

void setunion(char *s1,char *s2,char *s3)
{
 int i,l=strlen(s1);
for(i=0;i<l;i++)
{
 if(s1[i]=='0'&& s2[i]=='0')
s3[i]='0';
else
s3[i]='1';
}
s3[i]='\0';
}

void setintersection(char *s1,char *s2,char *s3)
{ 
int i,l=strlen(s1);
for(i=0;i<l;i++)
{ 
if(s1[i]=='1'&& s2[i]=='1')
s3[i]='1';
else
s3[i]='0';
}
s3[i]='\0';
}

void setdifference(char *s1,char *s2,char *s3)
{ int i,l=strlen(s1);
for(i=0;i<l;i++)
{ if(s1[i]=='1'&&  s2[i]=='0')
s3[i]='1';
else
s3[i]='0';
}
s3[i]='\0';
}

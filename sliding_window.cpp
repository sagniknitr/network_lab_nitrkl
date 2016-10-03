#include<stdio.h>
#include<stdlib.h>
int main()
{
int i,m,n,j,w;
char c;
FILE*f;
f=fopen("text.txt","r");
printf("window size");
scanf("%d",&n);
m=n;
while(!feof(f))
{
i=rand()%n+1;
j=i;
1=i;
if(m>i)
{
m=m-i;
if(m>0)
{
printf("\n");
while(i>0 & !feof(f))
{
c=getc(f);
printf("%c",c);
i--;
}
printf("\n%d transferred",&j);
if(j>3)
printf("\n 1 acknowledgement received");
else
printf("\n acknowledgement received",&(j+1));
}
}
m=m+j-1;
return 0;
}

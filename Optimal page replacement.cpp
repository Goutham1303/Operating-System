#include <stdio.h>
#include<stdbool.h>
int rs[100],count =0,f[10];
bool dataavi(int n)
{
int i;
for(i=0;i<n;i++)
{
if(rs[count]==f[i])
return 1;
}
return 0;
}
int check(int n,int m)
{
int buf[10],i,j=0;
for(j=0;j<n;j++)
{
int x=0;
for(i=count+1;i<m;i++)
{

if(f[j]==rs[i])
{
buf[j]=i;
i=m+1;
x=1;
}

}
if(x==0)
return j;
}
int max =buf[0],maxi=0;
for(i=0;i<n-1;i++)
{
if(max<=buf[i+1])
{
max=buf[i+1];
maxi=i+1;
}
}
return maxi;
}
void optimal(int n,int m)
{
int fs=0,i=0,in=0,kom=0;
while(count<m)
{
if(in<n)
{
if(dataavi(n)&&in>0)
{
count++;
kom=0;
}
else
{
f[in++]=rs[count];
fs++;
count++;
kom=1;
}
}
else
{
if(dataavi(n))
{
count++;
kom=0;
}
else
{
int j=check(n,m);
f[j]=rs[count++];
fs++;
kom=1;
}
}
if(kom==1)
printf(" Page Fault :");
else
printf("            :");
for(i=0;i<n;i++)
printf(" %d",f[i]);
printf("\n");
}
printf("\n\npage fault =%d",fs);
}
int main()
{
int n ,m,i;
printf("ENTER THE NO OF FRAME AND REFERENCE STREAM\n");
scanf ("%d%d",&n,&m);
printf ("ENTER THE REFERENCE STREAM\n");
for(i=0;i<m;i++)
scanf("%d",&rs[i]);
optimal(n,m);
}


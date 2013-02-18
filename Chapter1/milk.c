/*
ID: a.sanya1
LANG: C
TASK: milk
*/
#include<stdio.h>

int part(int a[],int p[],int m)
{
int temp=0;
temp = a[m-1];
a[m-1] = a[m/2];
a[m/2] = temp;
temp = p[m-1];
p[m-1] = p[m/2];
p[m/2] = temp;
int i=0,j=0;
for(i=0;i<(m-1);i++)
if(a[i] < a[m-1])
	{
		temp = a[i];
		a[i] = a[j];
		a[j] = temp;
		temp = p[i];
		p[i] = p[j];
		p[j++] = temp;
	}
temp = a[j];
a[j] = a[m-1];
a[m-1] = temp;
temp = p[j];
p[j] = p[m-1];
p[m-1] = temp;
return j;
} 

void qsort(int a[],int p[],int m)
{
if (m<=1)
	return;
int pivot = part(a,p,m);
qsort(a,p,pivot);
qsort(a+pivot+1,p+pivot+1,m-pivot-1);
}

int main()
{
FILE *fin = fopen("milk.in","r");
FILE *fout = fopen("milk.out","w");
if(fin==NULL||fout==NULL)
{
fprintf(stderr,"File fuck up!");
return -1;
}
int n,m,i;
fscanf(fin,"%d",&n);
fscanf(fin,"%d",&m);
int a[m];
int p[m];
for(i=0;i<m;i++)
	{
		fscanf(fin,"%d",p+i);
		fscanf(fin,"%d",a+i);
	}
fclose(fin);
qsort(p,a,m);
int sum=0;
for(i=0;i<m;i++)
{
printf("%d %d\n",a[i],p[i]);
}
i=0;
printf("%d",n);
while(n)
{
if(n<a[i]){
	sum = sum + n*p[i];break;}
n = n-a[i];
sum = sum + a[i]*p[i];
i++;
}
fprintf(fout,"%d\n",sum);
fclose(fout);
}

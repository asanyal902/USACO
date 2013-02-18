/*
ID: a.sanya1
LANG: C
TASK: palsquare
*/
#include<stdio.h>
#include<string.h>
#define N 300
char *convert(int n,int base,char *temp){
int j=0;
int k=n;
while(k)
{k/=base;
j++;}
j--;
temp[j+1] = '\0';
while(n)
{
switch(n%base){
case 10:
temp[j--] = 'A';
break;
case 11:
temp[j--] = 'B';
break;
case 12:
temp[j--] = 'C';
break;
case 13:
temp[j--] = 'D';
break;
case 14:
temp[j--] = 'E';
break;
case 15:
temp[j--] = 'F';
break;
case 16:
temp[j--] = 'G';
break;
case 17:
temp[j--] = 'H';
break;
case 18:
temp[j--] = 'I';
break;
case 19:
temp[j--] = 'J';
break;
default:
temp[j--] = n%base + '0';
break;
}
n /= base;
}
return temp;
}

int palin(char *temp)
{
int n = strlen(temp);
int i,j;
i=0;j=n-1;
while(i<j)
if(temp[i++]!=temp[j--])
	return 0;
return 1;
}

int main()
{
FILE *fin = fopen("palsquare.in","r");
FILE *fout = fopen("palsquare.out","w");
if(fin==NULL||fout==NULL)
{
fprintf(stderr,"File fuck up!");
return -1;
}
int base,n,i,j=0;
fscanf(fin,"%d",&base);
fclose(fin);
char temp[30];
char temp2[10];
for(i=1;i<=N;i++)
{
n = i;
convert(i*i,base,temp);
if(palin(temp))
{
convert(i,base,temp2);
fprintf(fout,"%s %s\n",temp2,temp);
}
}
fclose(fout);
}

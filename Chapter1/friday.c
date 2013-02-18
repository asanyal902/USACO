/*
ID: a.sanya1
LANG: C
TASK: friday
*/
#include <stdio.h>
int leap(int year)
{
if(year%100&&!(year%4)||!(year%400))
	return 1;
return 0;
}
int main () 
{
int i;
int day[7];
for(i=0;i<7;i++)
	day[i]=0;
FILE *fin  = fopen ("friday.in", "r");
FILE *fout = fopen ("friday.out", "w");
int n;
fscanf(fin,"%d",&n);
int count=1,j,temp;
for(j=0;j<n;j++)
for(i=0;i<12;i++)
{

	day[(count+5)%7]++;
	if(i==1)
		if(leap(j+1900))
			count = (count+1)%7;
		else;
	else if(i==3||i==5||i==8||i==10)
		count = (count+2)%7;	
	else 
		count = (count+3)%7;
	
}	
for(i=6;i<13;i++)
	fprintf(fout,"%d ",day[i%7]);	
fseek(fout,-1,SEEK_CUR);
fprintf(fout,"\n");
fclose(fin);
fclose(fout);
}

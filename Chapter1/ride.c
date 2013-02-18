/*
ID: a.sanya1
LANG: C
TASK: ride
*/
#include <stdio.h>
int char_count(char *a)
{
int sum=1;
int i=0;
while(a[i]!='\0')
	{
	sum*=(a[i]-'A'+1);
	i++;}	
return sum%47;
}

int main () 
{
FILE *fin  = fopen ("ride.in", "r");
FILE *fout = fopen ("ride.out", "w");
char comet[7];
char grp[7];
fscanf(fin,"%s %s",comet,grp);
if(char_count(comet)==char_count(grp))
	fprintf(fout,"GO\n");
else fprintf(fout,"STAY\n");	
fclose(fin);
fclose(fout);
}

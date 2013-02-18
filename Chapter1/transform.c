/*
ID: a.sanya1
LANG: C
TASK: transform
*/

#include<stdio.h>
#include<stdlib.h>
void print(char **in,int n)
{
int i,j;
for(i=0;i<n;i++)
	{for(j=0;j<n;j++)
		printf("%c",in[i][j]);
	printf("\n");}
}
char **rot(char **in,int n)
{
char **temp;
int i,j;
temp = (char **)malloc(n*sizeof(char *));
for(i=0;i<n;i++)
	temp[i] = (char *)malloc(n*sizeof(char));
for(i=0;i<n;i++)
	for(j=0;j<n;j++)
		temp[i][j]=in[n-j-1][i];
return temp;	
}

int rot1(char **in,char **out,int n)
{
int i,j;
char temp[n][n],flag=0;
for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	{
	temp[i][j]=in[n-j-1][i];
	if(temp[i][j]!=out[i][j])
		{
			flag=1;	
			break;
		}	
	}
#ifdef DEBUG
print(in,n);
printf("\n\n");
#endif
if(flag)
	return 0;
return 1;
}

int rot2(char **in,char **out,int n)
{
int i,j,flag=0;
char **temp = rot(rot(in,n),n);
#ifdef DEBUG
print(in,n);
printf("\n\n");
print(temp,n);
#endif
for(i=0;i<n;i++)
	for(j=0;j<n;j++)
		if(temp[i][j]!=out[i][j])
		{
			flag=1;	
			break;
		}	
if(flag)
	return 0;
return 1;
}

int rot3(char **in,char **out,int n)
{
int i,j,flag=0;
char **temp = rot(rot(rot(in,n),n),n);
#ifdef DEBUG
print(in,n);
printf("\n\n");
print(temp,n);
#endif
for(i=0;i<n;i++)
	for(j=0;j<n;j++)
		if(temp[i][j]!=out[i][j])
		{
			flag=1;	
			break;
		}	
if(flag)
	return 0;
return 1;
}


int mirror(char **in,char **out,int n)
{
char temp[n][n],flag=0,i,j;
for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	{
	temp[i][j]=in[i][n-j-1];
	if(temp[i][j]!=out[i][j])
		{
			flag=1;	
			break;
		}	
	}
#ifdef DEBUG
print(in,n);
printf("\n\n");

#endif
if(flag)
	return 0;
return 1;
}


int comb(char **in,char **out,int n)
{
char **temp;
int i,j;
temp = (char **)malloc(n*sizeof(char *));
for(i=0;i<n;i++)
	temp[i] = (char *)malloc(n*sizeof(char));
for(i=0;i<n;i++)
	for(j=0;j<n;j++)
		temp[i][j]=in[i][n-j-1];
if(rot1(temp,out,n))
	return 1;
if(rot2(temp,out,n))
	return 1;
if(rot3(temp,out,n))
	return 1;
return 0;
}

int comp(char **in,char **out,int n)
{
int i,j,flag=0;
for(i=0;i<n;i++)
	for(j=0;j<n;j++)
		if(in[i][j]!=out[i][j])
		{
		flag=1;
		break;
		}
if(flag)
	return 0;
return 1;
}



int main()
{
int n,i,j;
FILE *fin = fopen("transform.in","r");
if(fin==NULL)
	{
		fprintf(stderr,"Fack!");
		return 0;
	}
FILE *fout = fopen("transform.out","w");
if(fout==NULL)
	{
		fprintf(stderr,"Fack!");
		return 0;
	}
fscanf(fin,"%d",&n);
char **in = (char **)malloc(n*sizeof(char *));
for(i=0;i<n;i++)
	in[i] = (char *)malloc(n*sizeof(char));
for(i=0;i<n;i++)
	fscanf(fin,"%s",in[i]);
char **out = (char **)malloc(n*sizeof(char *));
for(i=0;i<n;i++)
	out[i] = (char *)malloc(n*sizeof(char));
for(i=0;i<n;i++)
	fscanf(fin,"%s",out[i]);
#ifdef DEBUG
print(in,n);
printf("\n\n");
print(out,n);
#endif
if(rot1(in,out,n))
	fprintf(fout,"1");
else if(rot2(in,out,n))
	fprintf(fout,"2");
else if(rot3(in,out,n))
	fprintf(fout,"3");
else if(mirror(in,out,n))
	fprintf(fout,"4");
else if(comb(in,out,n))
	fprintf(fout,"5");
else if(comp(in,out,n))
	fprintf(fout,"6");
else
	fprintf(fout,"7");
fprintf(fout,"\n");
fclose(fin);
fclose(fout);
return 0;
}


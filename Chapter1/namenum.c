/*
ID: a.sanya1
LANG: C
TASK: namenum
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char temp[12];
typedef struct  node
{
struct node *last;
struct node *next[26];
}node;
typedef struct tran
{
int n;
char letter[2];
}tran;       
node *final;
tran map[8];
node *create(void)
{
int i;
node *new = (node *)malloc(sizeof(node));
if(new == NULL)
{
fprintf(stderr,"Space fuck up!");
return NULL;
}
for(i=0;i<26;i++)
	new->next[i] = NULL;
new->last = NULL;
return new; 
}
node *init(void)
{
int i;
node *root = (node *)malloc(sizeof(node));
final = (node *)malloc(sizeof(node));
if(root == NULL || final==NULL)
{
fprintf(stderr,"Space fuck up!");
return NULL;
}
for(i=0;i<26;i++)
	root->next[i] = NULL;
root->last = NULL;
return root;
}

int insert(node *root,char *str)
{
int n = strlen(str);
int i;
node *temp = root;
for(i=0;i<n;i++)
{
if(temp->next[str[i]-'A']==NULL)
	temp->next[str[i]-'A'] = create();
temp = temp->next[str[i]-'A'];
}
temp->last = final;
}
FILE *fout;
int check(node *root,char *str)
{
int n= strlen(str);
node *temp = root;
int i;
for(i=0;i<n;i++)
{
if(temp==NULL)
	return 0;
temp = temp->next[str[i]-'A'];
}
if(temp==NULL)
	return 0;
if(temp->last==final)
	return 1;
else 
return 0;
}
int flag = 0;
int perm(char *n,node *root,int count)
{
if(*n=='\0')
{	
if(check(root,temp))
	{
		fprintf(fout,"%s\n",temp);
		flag =1 ;	
	}
return 0;
}
*(temp+count) = map[(*n-'0'-2)].letter[0];
perm(n+1,root,count+1);
*(temp+count) = map[(*n-'0'-2)].letter[1];
perm(n+1,root,count+1);
*(temp+count) = map[(*n-'0'-2)].letter[2];
perm(n+1,root,count+1);
}

int main()
{
int i;
FILE *dict = fopen("dict.txt","r");
if(dict==NULL)
{
fprintf(stderr,"File fuck up!");
return -1;
}
node *root = init();
char n[12];
while (!feof(dict))
{
fscanf(dict,"%s",temp);
insert(root,temp);
}
fclose(dict);
for(i=0;i<12;i++)
temp[i] = '\0';
map[0].letter[0] = 'A';
map[0].letter[1] = 'B';
map[0].letter[2] = 'C';
map[1].letter[0] = 'D';
map[1].letter[1] = 'E';
map[1].letter[2] = 'F';
map[2].letter[0] = 'G';
map[2].letter[1] = 'H';
map[2].letter[2] = 'I';
map[3].letter[0] = 'J';
map[3].letter[1] = 'K';
map[3].letter[2] = 'L';
map[4].letter[0] = 'M';
map[4].letter[1] = 'N';
map[4].letter[2] = 'O';
map[5].letter[0] = 'P';
map[5].letter[1] = 'R';
map[5].letter[2] = 'S';
map[6].letter[0] = 'T';
map[6].letter[1] = 'U';
map[6].letter[2] = 'V';
map[7].letter[0] = 'W';
map[7].letter[1] = 'X';
map[7].letter[2] = 'Y';
FILE *fin = fopen("namenum.in","r");
fout = fopen("namenum.out","w");
if(fin==NULL||fout==NULL)
{
fprintf(stderr,"File fuck up!");
return -1;
}
fscanf(fin,"%s",n);
fclose(fin);
perm(n,root,0);
if(!flag)
fprintf(fout,"NONE\n");
fclose(fout);
}

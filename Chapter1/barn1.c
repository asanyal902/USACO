/*
ID: a.sanya1
LANG: C
TASK: barn1
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_LEN 205
#define Min(a,b) ((a)<(b) ? (a) : (b))
int M, S, C;
int rt, stalls[MAX_LEN], diff[MAX_LEN];

int
asc_cmp(const void *arg1, const void *arg2)
{
        return (*(int *)arg1) - (*(int *)arg2);
}

int
desc_cmp(const void *arg1, const void *arg2)
{
        return (*(int *)arg2) - (*(int *)arg1);
}

void
init()
{
        int i;
        for(i=0; i<C; i++)
                scanf("%d", stalls+i);
        qsort(stalls, C, sizeof(int), asc_cmp);
        rt = stalls[C-1] - stalls[0] + 1;
        for(i=1; i<C; i++)
                diff[i-1] = stalls[i] - stalls[i-1] - 1;
        qsort(diff, C-1, sizeof(int), desc_cmp);
}

void
solve()
{
        int i, up;
        up = Min(C-1, M-1);
        for(i=0; i<up; i++)
                rt -= diff[i];
        printf("%d\n", rt);
}

int
main(int argc, char **argv)
{
        freopen("barn1.in", "r", stdin);
        freopen("barn1.out", "w", stdout);
        while(scanf("%d %d %d", &M, &S, &C) != EOF) {
                init();
                solve();
        }
        return 0;
}

/*#include<stdio.h>
#include<assert.h>
int main()
{
	FILE *fin = fopen("barn1.in","r");
	FILE *fout = fopen("barn1.out","w");
	assert(fin!=NULL && fout!=NULL);
	int m,s,c,temp;
	/*taking input
	fscanf(fin,"%d %d %d",&m,&s,&c);
	int barn[c];
	int i; 
	for (i= 0; i < c; ++i)
		fscanf(fin,"%d",barn+i);
	int len=0;
	for (i = 1; i < c-1,m; ++i)
	{
		if(barn[i]-barn[i-1]>barn[i+1]-barn[i])
			{
				m--;
				len++;
			}
		else
			len+=(barn[i]-barn[i-1]);
	}
	if(!m)
		len+=(barn[c-1]-barn[i]+1);
	fprintf(fout,"%d\n",len);

}*/
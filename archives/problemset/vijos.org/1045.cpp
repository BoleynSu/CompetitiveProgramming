/*
PROGRAM: $PROGRAM
AUTHOR: Su Jiao
DATE: 2010-5-6
DESCRIPTION:
VIJOS1045
APIO要到了，练习一下NOI Linux环境下写程序。
*/
#include <stdio.h>
#include <stdlib.h>
#define MAXEDGE 100000*2
#define MAXNODE 100000

struct Edge{int x,y;double s;};

double s;
int n,m;
Edge edge[MAXEDGE];
int set[MAXNODE+1];

int get_father(int x)
{
	if (set[x]) return set[x]=get_father(set[x]);
	else return x;
}
bool is_friend(int x,int y)
{
	return get_father(x)==get_father(y);
}
void set_friend(int x,int y)
{
	set[get_father(x)]=get_father(y);
}
int edgecmp(const void* a,const void* b)
{
	if (((Edge*)a)->s<((Edge*)b)->s) return -1;
	else return 1;
}

int main()
{
	freopen("town.in","r",stdin);
	freopen("town.out","w",stdout);
	scanf("%lf%d",&s,&n);
	int e;
	while (scanf("%d%d%lf",&(edge[m].x),&(edge[m].y),&(edge[m].s))!=EOF)
		m++;
	qsort(edge,m,sizeof(Edge),edgecmp);
	double need=0;
	int counter=0;
	for (int i=0;i<m;i++)
		if (!is_friend(edge[i].x,edge[i].y))
		{
			counter++;
			set_friend(edge[i].x,edge[i].y);
			need+=edge[i].s;
		}
	if (need<=s&&counter==n-1) printf("Need %.2f miles of cable\n",need);
	else printf("Impossible\n");
	fclose(stdin);
	fclose(stdout);
	return 0;
}

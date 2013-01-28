/*
AUTHOR: Su Jiao
DATE: 2010-7-23
DESCRIPTION:
$DESCRIPTION
*/
#include <stdio.h>
#include <string.h>

#define max(a,b) ((a)>(b)?(a):(b))
const int LOG2_MAXLENGTH=20;
const int MAXLENGTH=1<<LOG2_MAXLENGTH;
const int MAXALPHABET=256;
typedef char string[MAXLENGTH];
int sort[max(MAXLENGTH,MAXALPHABET)];
int SA[MAXLENGTH],rank[MAXLENGTH],TSA[MAXLENGTH],Trank[MAXLENGTH];
void get_SA(string s,int length)
{
	memset(sort,0,sizeof(sort));
	for (int i=1;i<=length;i++) sort[s[i]]++;
	for (int i=1;i<MAXALPHABET;i++) sort[i]+=sort[i-1];
	for (int i=1;i<=length;i++) SA[sort[s[i]]--]=i;
	rank[SA[1]]=1;
	for (int i=2;i<=length;i++)
		if (s[SA[i]]==s[SA[i-1]]) rank[SA[i]]=rank[SA[i-1]];
		else rank[SA[i]]=rank[SA[i-1]]+1;
	for (int block=1;block<length;block<<=1)
	{
		for (int i=1;i<=length;i++) sort[rank[SA[i]]]=i;
		for (int i=length;i>=1;i--)
			if (SA[i]-block>=1)
				TSA[sort[rank[SA[i]-block]]--]=SA[i]-block;
		for (int i=length-block+1;i<=length;i++)
			TSA[sort[rank[i]]--]=i;
		Trank[TSA[1]]=1;
		for (int i=2;i<=length;i++)
			if (rank[TSA[i]]==rank[TSA[i-1]]
				&&rank[TSA[i]+block]==rank[TSA[i-1]+block])
				Trank[TSA[i]]=Trank[TSA[i-1]];
			else Trank[TSA[i]]=Trank[TSA[i-1]]+1;
		memcpy(SA,TSA,sizeof(SA));
		memcpy(rank,Trank,sizeof(rank));
	}
}
int height[MAXLENGTH];
void get_height(string s,int length)
{
	for (int h=0,i=1;i<=length;i++)
	{
		if (h) h--;
		if (rank[i]!=1)
		{
			int j=SA[rank[i]-1];
			while (s[i+h]==s[j+h]) h++;
		}
		height[rank[i]]=h;
	}
}

string s;
int length;

int main()
{
	scanf("%s",s+1);
	int firstLength=strlen(s+1);
	s[++firstLength]='#';
	scanf("%s",s+1+firstLength);
	length=strlen(s+1);
	s[++length]='$';
	get_SA(s,length);
	get_height(s,length);
	int answer=0;
	for (int i=2;i<=length;i++)
	{
		if (((SA[i-1]<=firstLength)^(SA[i]<=firstLength))&&height[i]>answer)
			answer=height[i];
	}
	printf("%d\n",answer);
}
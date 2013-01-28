#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

enum{SIZE=100};
int n,m;
int k[SIZE];
int pi[SIZE];
int ai[SIZE][SIZE];

bool used[SIZE];
int get[SIZE];
int answer_index;
int answer_p;
void dfs(int i=0)
{
	if (i==n)
	{
		int get_p=(n-1)*n/2+1;
		for (int p=0;p<n;p++)
			for (int q=0;q<p;q++)
				if (get[q]>get[p])
					get_p--;
		for (int j=0;j<m;j++)
		{
			bool match=true;
			for (int p=0,q=0;p<n;p++)
			{
				while (get[p]!=ai[j][q]&&q<k[j]) q++;
				if (q>=k[j])
				{
					match=false;
					break;
				}
			}
			if (match)
			{
				if (get_p>answer_p)
				{
					answer_p=get_p;
					answer_index=j+1;
				}
				else if (get_p==answer_p&&answer_index>j)
					answer_index=j+1;
				break;
			}
		}
	}
	else
	{
		for (get[i]=1;get[i]<=n;get[i]++)
			if (!used[get[i]])
			{
				used[get[i]]=true;
				dfs(i+1);
				used[get[i]]=false;
			}
	}
}

int main()
{
	map<string,int> f;
	cin>>n;
	vector<string> p(n);
	for (int i=0;i<n;i++)
	{
		cin>>p[i];
		if (f.find(p[i])==f.end())
			f[p[i]]=f.size();
		pi[i]=f[p[i]];
	}
	cin>>m;
	vector<vector<string> > a(m);
	for (int i=0;i<m;i++)
	{
		cin>>k[i];
		a[i].resize(k[i]);
		for (int j=0;j<k[i];j++)
		{
			cin>>a[i][j];
			if (f.find(a[i][j])==f.end())
				f[a[i][j]]=f.size();
			ai[i][j]=f[a[i][j]];
		}
	}
	dfs();
	if (answer_p==0)
		cout<<"Brand new problem!"<<endl;
	else
	{
		cout<<answer_index<<endl;
		cout<<"[:";
		for (int i=0;i<answer_p;i++) cout<<"|";
		cout<<":]"<<endl;
	}
}


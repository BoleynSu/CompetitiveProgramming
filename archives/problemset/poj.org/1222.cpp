#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int N;
	cin>>N;
	for (int n=1;n<=N;n++)
	{
		int m[30][31];
		memset(m,0,sizeof m);
		for (int i=0;i<5;i++)
			for (int j=0;j<6;j++)
			{
				#define node(x,y) ((x)*6+y)
				#define add(x,y) if (0<=(x)&&(x)<5&&0<=(y)&&(y)<6) m[node((x),(y))][node(i,j)]=1;
				cin>>m[node(i,j)][30];
				add(i,j);
				add(i-1,j);
				add(i+1,j);
				add(i,j-1);
				add(i,j+1);
			}
		for (int i=0;i<30;i++)
		{
			for (int j=i;j<30;j++)
				if (m[j][i])
				{
					for (int k=i;k<=30;k++)
					{
						int swap=m[i][k];
						m[i][k]=m[j][k];
						m[j][k]=swap;
					}
					break;
				}
			for (int j=i+1;j<30;j++)
				if (m[j][i])
				{
					for (int k=i;k<=30;k++)
						m[j][k]=m[j][k]^m[i][k];
				}
		}
		int x[30];
		for (int i=30-1;i>=0;i--)
		{
			x[i]=m[i][30];
			for (int j=30-1;j>i;j--)
				x[i]=x[i]^(m[i][j]&x[j]);
		}
		cout<<"PUZZLE #"<<n<<endl;
		for (int i=0;i<5;i++)
			for (int j=0;j<6;j++)
				cout<<x[node(i,j)]<<char(j+1==6?'\n':' ');
	}
}

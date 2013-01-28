#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int M,N1,N2;
int a1[1993];
int a2[1993];
int f[199][199];
int answer;

int main()
{
	cin>>M;
	while (M--)
	{
		cin>>N1>>N2;
		for (int i=1;i<=N1;i++) cin>>a1[i];
		for (int i=1;i<=N2;i++) cin>>a2[i];
		answer=0;
		memset(f,0,sizeof f);
		for (int i=1;i<=N1;i++)
			for (int j=1;j<=N2;j++)
			{
				f[i][j]=0;
				if (a1[i]!=a2[j])
					for (int i_=1;i_<i;i_++)
						if (a1[i_]==a2[j])
							for (int j_=1;j_<j;j_++)
								if (a1[i]==a2[j_])
									if (f[i][j]<f[i_-1][j_-1]+2)
										f[i][j]=f[i_-1][j_-1]+2;
				if (f[i][j]<f[i][j-1]) f[i][j]=f[i][j-1];
				if (f[i][j]<f[i-1][j]) f[i][j]=f[i-1][j];
			}
		cout<<f[N1][N2]<<endl;
	}
}

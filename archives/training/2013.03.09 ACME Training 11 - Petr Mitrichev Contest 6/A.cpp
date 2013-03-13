#include <iostream>
using namespace std;

double g[53][53][53];
double f[53][53];

double C(int n,int m)
{
	if (m<0||m>n) return 0;
	double ans=1.0;
	for (int i=0;i<m;i++) ans*=double(n-i)/double(i+1);
	//cout<<n<<" "<<m<<" "<<ans<<endl;
	return ans;
}

int main()
{
	int n,l1,l2,p;
	cin>>n>>l1>>l2>>p;
	for (int i=0;i<=n;i++)
	{
		for (int l1=0;l1<=n;l1++)
			for (int l2=0;l2<=n-l1;l2++)
				g[i][l1][l2]+=double(1)/n*C(i,l1)*C(n-i,l2)/C(n,l1+l2);
	}
	for (int i=0;i<=n;i++)
	{
		for (int j=0;j<=n;j++) f[i][i]+=g[j][l1][l2];
		f[i][i]=g[i][l1][l2]/f[i][i];
	}
	for (int i=1;i<=n;i++)
		for (int j=0;j+i<=n;j++)
			f[j][j+i]=f[j+1][j+i]+f[j][j+i-1]-(j+1<=j+i-1?f[j+1][j+i-1]:0);
	int ii,jj;
	for (int i=0;i<=n;i++)
		for (int j=0;j+i<=n;j++)
		{
			if (f[j][j+i]*100>=p-1e-13)
			{
				ii=i,jj=j;
				cout<<jj<<" "<<jj+ii<<endl;
				return 0;
			}
		}
}

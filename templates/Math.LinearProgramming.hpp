/*
 * Package: StandardCodeLibrary.Math.LinearProgramming
 * Description:
 * 线性规划 单纯形法实现
 * Usage:
 * MAXN:最大变量个数
 * MAXM:最大不等式个数
 * n=变量个数,m=不等式个数
 * 目标函数为 sum{x[i]*A[0][i];0<=i<n}+A[0][n]
 * 约束条件为
 *  1) x[i]>=0 for 0<=i<n
 *  2) sum{x[i]*A[j][i];0<=i<n}<=A[j][n] for 1<=j<=m
 * simplex输出目标函数的最大值(-inf表示无解,+inf表示有无穷大解) 并且使X[i]变为该最优解取得时的x[i]的值
 * */
#include <Core>

namespace StandardCodeLibrary
{
namespace Math
{
namespace LinearProgramming
{

const int MAXN=1;
const int MAXM=1;
int n,m;
db A[MAXM+1][MAXN+1],X[MAXN];
int basis[MAXM+1],out[MAXN+1];

void pivot(int a,int b)
{
	ft(i,0,m) if (i!=a&&sgn(A[i][b])) ft(j,0,n) if (j!=b) A[i][j]-=A[a][j]*A[i][b]/A[a][b];
	ft(j,0,n) if (j!=b) A[a][j]/=A[a][b];
	ft(i,0,m) if (i!=a) A[i][b]/=-A[a][b];
	A[a][b]=1/A[a][b];
	swap(basis[a],out[b]);
}
db simplex()
{
	rep(j,n) A[0][j]=-A[0][j];
	ft(i,0,m) basis[i]=-i;
	ft(j,0,n) out[j]=j;
	lp
	{
		int ii=1,jj=0;
		ft(i,1,m) if (mp(A[i][n],basis[i])<mp(A[ii][n],basis[ii])) ii=i;
		if (A[ii][n]>=0) break;
		rep(j,n) if (A[ii][j]<A[ii][jj]) jj=j;
		if (A[ii][jj]>=0) rtn -inf;
		pivot(ii,jj);
	}
	lp
	{
		int ii=1,jj=0;
		rep(j,n) if (mp(A[0][j],out[j])<mp(A[0][jj],out[jj])) jj=j;
		if (A[0][jj]>=0) break;
		ft(i,1,m)
			if (A[i][jj]>0&&(A[ii][jj]<=0||mp(A[i][n]/A[i][jj],basis[i])<mp(A[ii][n]/A[ii][jj],basis[ii])))
				ii=i;
		if (A[ii][jj]<=0) rtn +inf;
		pivot(ii,jj);
	}
	rep(j,n) X[j]=0;
	ft(i,1,m) if (basis[i]>=0) X[basis[i]]=A[i][n];
	rtn A[0][n];
}

}
}
}

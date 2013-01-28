#include <iostream>
#include <cstdio>
using namespace std;

//http://webdocs.cs.ualberta.ca/~contest/code/Old/Arithmetic/simplex.c

//  Simplex Method for Linear Programming
//
//  m - number of (less than) inequalities
//  n - number of variables
//
//  C - (m+1) by (n+1) array of coefficients:
//
//        row 0        - objective function coefficients
//        row 1:m        - less-than inequalities
//
//        column 0:n-1 - inequality coefficients
//        column n    - inequality constants (0 for objective function)
//
//  X[n] - result variables
//
//  return value - maximum value of objective function
//                    (-inf for infeasible, inf for unbounded)
//

#define MAXM 400    // leave one extra
#define MAXN 10002    // leave one extra
#define EPS 1e-8
#define INF 1e+8

double A[MAXM][MAXN];
int basis[MAXM],out[MAXN];

void pivot(int m,int n,int a,int b)
{
    for (int i=0;i<=m;i++)
        if (i!=a)
            for (int j=0;j<=n;j++)
                if (j!=b)
                    A[i][j]-=A[a][j]*A[i][b]/A[a][b];

    for (int j=0;j<=n;j++) if (j!=b) A[a][j]/=A[a][b];
    for (int i=0;i<=m;i++) if (i!=a) A[i][b]=-A[i][b]/A[a][b];
    A[a][b]=1/A[a][b];

    int swap= basis[a];
    basis[a]=out[b];
    out[b]=swap;
}

double simplex(int m,int n,double C[][MAXN],double X[])
{
    // i,ii are row indexes; j,jj are column indexes
    int i,j,ii,jj;
    for (i=1;i<=m;i++)
        for (j=0;j<=n;j++)
            A[i][j]=C[i][j];
    for (j=0;j<=n;j++) A[0][j]=-C[0][j];
    for (i=0;i<=m;i++) basis[i]=-i;
    for (j=0;j<=n;j++) out[j]=j;

    for(;;)
    {
        for (i=ii=1;i<=m;i++)
            if (A[i][n]<A[ii][n]||(A[i][n]==A[ii][n]&&basis[i]<basis[ii]))
                ii=i;
        if (A[ii][n]>=-EPS) break;
        for (j=jj=0;j<n;j++)
            if (A[ii][j]<A[ii][jj]||(A[ii][j]<A[ii][jj]&&out[i]<out[j]))
                jj=j;
        if (A[ii][jj]>=-EPS) return-INF;
        pivot(m,n,ii,jj);
    }

    for(;;)
    {
        for (j=jj=0;j<n;j++)
            if (A[0][j]<A[0][jj]||(A[0][j]==A[0][jj]&&out[j]<out[jj]))
                jj=j;
        if (A[0][jj]>=-EPS) break;
        for (i=1,ii=0;i<=m;i++)
            if (A[i][jj]>=EPS&&(!ii||A[i][n]/A[i][jj]<A[ii][n]/A[ii][jj]||(A[i][n]/A[i][jj]<A[ii][n]/A[ii][jj]+EPS&&basis[i]<basis[ii])))
                ii=i;
        if (A[ii][jj]<=EPS) return INF;
        pivot(m,n,ii,jj);
    }

    for (j=0;j<n;j++) X[j]=0;
    for (i=1;i<=m;i++) if (basis[i]>=0) X[basis[i]]=A[i][n];
    return A[0][n];
}

int main()
{
    cin.sync_with_stdio(false);
    int T;
    cin>>T;
    for (int t=0;t<T;t++)
    {
        long long n,d,L,W;
        cin>>n>>d>>L>>W;
        long long s[n],t[n];
        for (int i=0;i<n;i++)
                cin>>s[i]>>t[i];
        double answer=0;
        for (int i=0;i<n;i++)
        {
                L-=d;
                W-=s[i]*d;
                answer+=t[i]*d;
        }
        double C[4][MAXN],X[MAXN];
        for (int i=0;i<n;i++) C[0][i]=-t[i];
        C[0][n]=0;
        for (int i=0;i<n;i++) C[1][i]=1;
        C[1][n]=L;
        for (int i=0;i<n;i++) C[2][i]=-1;
        C[2][n]=-L;
        for (int i=0;i<n;i++) C[3][i]=s[i];
        C[3][n]=W;
        double get=simplex(3,n,C,X);
        if (get==-INF) printf("No solution\n");
        else printf("%.2f\n",answer-get);
    }
}

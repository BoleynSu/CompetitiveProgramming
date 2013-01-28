import java.math.*;
import java.io.*;
import java.util.*;

class Main
{
    public static void main(String arg[])
    {
        new Main();
    }
    class edge
    {
        int v,n;
    }
    static final double oo=1e10;
    int n,x[],y[],p[];
    double dist[][];
    int top;
    edge edges[];
    int adj[];
    double dp[][];
    void add_edge(int u,int v)
    {
        edges[top]=new edge();
        edges[top].v=v;
        edges[top].n=adj[u];
        adj[u]=top++;
        edges[top]=new edge();
        edges[top].v=u;
        edges[top].n=adj[v];
        adj[v]=top++;
    }
    void dfs(int u,int father,int root)
    {
        if (father!=-1)
        {
            if (dp[root][father]<dist[father][u])
                dp[root][u]=dist[father][u];
            else
                dp[root][u]=dp[root][father];
        }
        else dp[root][u]=0;
        for (int e=adj[u];e!=-1;e=edges[e].n)
            if (edges[e].v!=father)
                dfs(edges[e].v,u,root);
    }
    Main()
    {
        Scanner cin=new Scanner(new BufferedInputStream(System.in));
        for (int t=cin.nextInt();t>0;t--)
        {
            n=cin.nextInt();
            x=new int[n];
            y=new int[n];
            p=new int[n];
            for (int i=0;i<n;i++)
            {
                x[i]=cin.nextInt();
                y[i]=cin.nextInt();
                p[i]=cin.nextInt();
            }
            dist=new double[n][n];
            for (int i=0;i<n;i++)
                for (int j=0;j<n;j++)
                    dist[i][j]=Math.sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
            int qh,qt;
            int q[]=new int[n];
            int pre[]=new int[n];
            double d[]=new double[n];
            double total=0;
            Arrays.fill(d,+oo);
            pre[0]=-1;
            d[q[qh=qt=0]=0]=0;
            top=0;
            edges=new edge[(n-1)*2];
            adj=new int[n];
            Arrays.fill(adj,-1);
            while (qh<=qt)
            {
                int u=q[qh++];
                if (pre[u]!=-1) add_edge(pre[u],u);
                double mind=+oo;
                int minv=-1;
                for (int v=0;v<n;v++)
                    if (d[v]!=0)
                    {
                        if (d[v]>dist[u][v])
                        {
                            pre[v]=u;
                            d[v]=dist[u][v];
                        }
                        if (mind>d[v])
                            mind=d[minv=v];
                    }
                if (minv!=-1)
                {
                    total+=mind;
                    d[q[++qt]=minv]=0;
                }
            }
            dp=new double[n][n];
            for (int u=0;u<n;u++)
                dfs(u,-1,u);
            double answer=0;
            for (int u=0;u<n;u++)
                for (int v=0;v<u;v++)
                {
                    double get=((double)(p[u])+(double)(p[v]))/(total-dp[u][v]);
                    if (get>answer) answer=get;
                }
            System.out.printf("%.2f%n",answer);
        }
    }
}

import java.util.*;
import java.io.*;

public class Main {
    public static void main(String arg[])
    {
        new Main();
    }
    LinkedList<Integer> adj[];
    ArrayList<Integer> natd[];
    int io[],oo[],dp[];
    int t;
    void dfs(int u,int d)
    {
        io[u]=t;
        natd[d].add(t);
        dp[u]=d;
        t++;
        for (Integer v: adj[u])
            dfs(v,d+1);
        oo[u]=t;
    }
    public Main()
    {
        Scanner cin=new Scanner(new BufferedInputStream(System.in));
        int n=cin.nextInt();
        adj=new LinkedList[n+2];
        for (int i=1;i<=n;i++)
            adj[i]=new LinkedList<Integer>();
        natd=new ArrayList[n+2];
        for (int i=0;i<n;i++)
            natd[i]=new ArrayList<Integer>();
        io=new int[n+2];
        oo=new int[n+2];
        dp=new int[n+2];
        int f[][]=new int[20][n+2];
        for (int i=0;i<20;i++)
            Arrays.fill(f[i],0);
        LinkedList<Integer> root=new LinkedList<Integer>();
        for (int i=1;i<=n;i++)
        {
            int r=cin.nextInt();
            if (r!=0)
            {
                adj[r].add(i);
                f[0][i]=r;
            }
            else root.add(i);
        }
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<20;j++)
                f[j][i]=f[j-1][f[j-1][i]];
        }
        t=0;
        for (int r: root) dfs(r,0);
        for (int i=0;i<n;i++)
            Collections.sort(natd[i],new Comparator<Integer>(){public int compare(Integer a,Integer b){if (a==b) return 0;else return a<b?-1:1;}});
        int m=cin.nextInt();
        for (int i=1;i<=m;i++)
        {
            int v=cin.nextInt(),p=cin.nextInt();
            for (int j=0;j<20;j++)
                if ((p&(1<<j))!=0)
                    v=f[j][v];
            int answer=0;
            if (v!=0)
            {
                int L,R,d=dp[v]+p;
                L=-1;
                R=natd[d].size()-1;
                while (L+1!=R)
                {
                    int mid=(L+R)/2;
                    if (natd[d].get(mid)<=io[v]) L=mid;
                    else R=mid;
                }
                int b=R;
                L=0;
                R=natd[d].size();
                while (L+1!=R)
                {
                    int mid=(L+R)/2;
                    if (natd[d].get(mid)>oo[v]) R=mid;
                    else L=mid;
                }
                int e=L;
                answer=e-b;
            }
            if (i==m) System.out.println(answer);
            else System.out.print(answer+" ");
        }
        cin.close();
    }
}

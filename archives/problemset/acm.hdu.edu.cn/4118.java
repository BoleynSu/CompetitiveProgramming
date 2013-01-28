/*
PROGRAM: $PROGRAM
AUTHOR: Su Jiao
DATE: 2011-11-11
DESCRIPTION:
$DESCRIPTION
*/

import java.io.*;
import java.util.*;

public class Main {
    public static void main(String args[])
    {
        new Main();
    }
    public class Graph {
        public class edge {
            public int v,d,n;
        }
        public int top;
        public edge edges[];
        public int adj[];
        public int N;
        public Graph(int N_)
        {
            N=N_;
            edges=new edge[(N-1)*2];
            top=0;
            adj=new int[N];
            Arrays.fill(adj,-1);
        }
        void add_edge(int u,int v,int d)
        {
            u--;v--;
            edges[top]=new edge();edges[top].v=v;edges[top].d=d;edges[top].n=adj[u];adj[u]=top++;
            edges[top]=new edge();edges[top].v=u;edges[top].d=d;edges[top].n=adj[v];adj[v]=top++;
        }
    }
    public Graph graph;
    public long get_answer()
    {
        int qh,qt;
        int q[]=new int[graph.N];
        int f[]=new int[graph.N];
        int d[]=new int[graph.N];
        boolean inq[]=new boolean[graph.N];
        Arrays.fill(inq,false);
        inq[q[qh=qt=0]=0]=true;
        while (qh<=qt)
        {
            int u=q[qh++];
            for (int e=graph.adj[u];e!=-1;e=graph.edges[e].n)
            {
                int v=graph.edges[e].v;
                if (!inq[v])
                {
                    inq[q[++qt]=v]=true;
                    f[v]=u;
                    d[v]=graph.edges[e].d;
                }
            }
        }
        long answer=0;
        int c[]=new int[graph.N];
        Arrays.fill(c,0);
        while (qt>=0)
        {
            int u=q[qt--];
            c[u]++;
            c[f[u]]+=c[u];
            answer+=(long)(Math.min(c[u],graph.N-c[u]))*(long)(d[u])*(long)(2);
        }
        return answer;
    }
    public Main()
    {
        Scanner cin = new Scanner(new BufferedInputStream(System.in));
        int T=cin.nextInt();
        for (int t=1;t<=T;t++)
        {
            int N=cin.nextInt();
            graph=new Graph(N);
            for (int i=1;i<N;i++)
            {
                int X,Y,Z;
                X=cin.nextInt();
                Y=cin.nextInt();
                Z=cin.nextInt();
                graph.add_edge(X,Y,Z);
            }
            System.out.println("Case #"+t+": "+get_answer());
        }
    }
}


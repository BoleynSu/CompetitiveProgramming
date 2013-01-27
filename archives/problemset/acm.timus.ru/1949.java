import java.util.*;
import java.io.*;
import java.math.*;

public class Main {
	public static void main(String arg[])
	{
		new Main();
	}
	final int OO=Integer.MAX_VALUE;
	final BigInteger oo=BigInteger.valueOf(10);
	final int MAXE=1000000;
	final int MAXV=1000000;
	class edge{int v,c;BigInteger d;edge n,b;};
	int S,T;
	edge[] adj=new edge[MAXV];;
	void add_edge(int u,int v,int c,BigInteger d)
	{
		edge top;
		top=new edge();
		top.v=v;
		top.c=c;
		top.d=d;
		top.n=adj[u];
		adj[u]=top;
		top=new edge();
		top.v=u;
		top.c=0;
		top.d=d.negate();
		top.n=adj[v];
		adj[v]=top;
		adj[u].b=adj[v];
		adj[v].b=adj[u];
	}
	void build_graph()
	{
		Arrays.fill(adj,null);
		//S,T;//源,汇
		//add_edge(u,v,c,d);
	}
	BigInteger[] d=new BigInteger[MAXV];
	int[] q=new int[MAXV];
	boolean[] inq=new boolean[MAXV];
	int qh,qt;
	edge[] p=new edge[MAXV];
	BigInteger min_cost_max_flow()
	{
		BigInteger cost=BigInteger.ZERO;
		for (;;)
		{
			Arrays.fill(d,oo);
			inq[q[qh=qt=0]=S]=true;
			d[S]=BigInteger.ZERO;
			p[S]=null;
			while (qh<=qt)
			{
				int u=q[(qh++)%MAXV];
				inq[u]=false;
				for (edge i=adj[u];i!=null;i=i.n)
					if (i.c!=0&&d[i.v].compareTo(d[u].add(i.d))>0)
					{
						d[i.v]=d[u].add(i.d);
						if (!inq[i.v]) inq[q[(++qt)%MAXV]=i.v]=true;
						p[i.v]=i;
					}
			}
			if (d[T].equals(oo)) break;
			else
			{
				int delta=OO;
				for (edge i=p[T];i!=null;i=p[i.b.v]) if (delta>i.c) delta=i.c;
				for (edge i=p[T];i!=null;i=p[i.b.v])
				{
					i.c-=delta;
					i.b.c+=delta;
				}
				cost=cost.add(d[T].multiply(BigInteger.valueOf(delta)));
			}
		}
		return cost;
	}
	public Main()
	{
		Scanner cin=new Scanner(new BufferedInputStream(System.in));
		int n=cin.nextInt(),k=cin.nextInt();
		int[] a=new int[n],b=new int[n],c=new int[n];
		for (int i=0;i<n;i++)
		{
			a[i]=cin.nextInt();
			b[i]=cin.nextInt();
			c[i]=cin.nextInt();
		}
		build_graph();
		S=n*2+1;
		T=n*2+2;
		for (int i=0;i<n;i++)
		{
			add_edge(i,i+n,1,BigInteger.TEN.pow(n-1-i).negate());
			add_edge(S,i,OO,BigInteger.ZERO);
			add_edge(i+n,n*2,OO,BigInteger.ZERO);
		}
		for (int i=0;i<n;i++)
			for (int j=0;j<n;j++)
				if (b[i]<=a[j]&&c[i]<=c[j])
					add_edge(i+n,j,OO,BigInteger.ZERO);
		add_edge(n*2,T,k,BigInteger.ZERO);
		System.out.println(min_cost_max_flow().negate());
		cin.close();
	}
}

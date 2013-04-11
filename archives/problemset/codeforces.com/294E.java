import java.io.BufferedInputStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;


public class Main {
	private int n;
	private ArrayList<Integer>[] adj=new ArrayList[5000],
								len=new ArrayList[5000];
	private int[] size_init=new int[5000],
				size=new int[5000];
	long dfs_init(int u,int p)
	{
		long ans=0;
		size_init[u]=1;
		for (int i=0;i<adj[u].size();i++)
		{
			int v=adj[u].get(i);
			int w=len[u].get(i);
			if (v!=p)
			{
				long get=dfs_init(v,u);
				size_init[u]+=size_init[v];
				ans+=(long)w*size_init[v]*(n-size_init[v])+get;
			}
		}
		return ans;
	}
	long dfs(int u,int p,int OTHER)
	{
		long ans=0;
		size[u]=1;
		for (int i=0;i<adj[u].size();i++)
		{
			int v=adj[u].get(i);
			int w=len[u].get(i);
			if (v!=p)
			{
				long get=Math.min(ans,dfs(v,u,OTHER));
				size[u]+=size[v];
				get+=(long)w*(size[v]+OTHER)*(n-size[v]-OTHER)-(long)w*size[v]*(n-size[v]);
				//System.out.println(get);
				ans=Math.min(ans,get);
			}
		}
		return ans;
	}
	long calc(int L,int R,int w)
	{
		return dfs(L,R,size_init[R])+dfs(R,L,n-size_init[R]);
	}
	public Main()
	{
		Scanner scanner=new Scanner(new BufferedInputStream(System.in));
		n=scanner.nextInt();
		for (int i=0;i<n;i++)
		{
			adj[i]=new ArrayList<Integer>();
			len[i]=new ArrayList<Integer>();
		}
		for (int i=1;i<n;i++)
		{
			int a=scanner.nextInt()-1,b=scanner.nextInt()-1,w=scanner.nextInt();
			//System.out.println(a+","+b);
			adj[a].add(b);
			adj[b].add(a);
			len[a].add(w);
			len[b].add(w);
		}
		long ans_init=dfs_init(0,-1);
		//System.out.println(ans_init);
		long ans=Long.MAX_VALUE;
		for (int L=0;L<n;L++)
		{
			for (int i=0;i<adj[L].size();i++)
			{
				int R=adj[L].get(i);
				if (size_init[L]>size_init[R]) ans=Math.min(ans,ans_init+calc(L,R,len[L].get(i)));
			}
		}
		System.out.println(ans);
		scanner.close();
	}
	public static void main(String[] arg)
	{
		new Main();
	}
}


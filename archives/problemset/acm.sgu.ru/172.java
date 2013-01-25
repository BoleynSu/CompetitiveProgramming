import java.util.*;
import java.io.*;

public class Solution
{
	public static void main(String arg[])
	{
		new Solution();
	}
	public Solution()
	{
		new TaskF();
	}
}

class TaskF
{
	final int red=0,green=1,blue=2;
	int color[];
	LinkedList<Integer> adj[];
	boolean dfs(int u,int c)
	{
		if (color[u]!=red) return color[u]==c;
		else
		{
			color[u]=c;
			c=(c==blue?green:blue);
			for (int v:adj[u])
				if (!dfs(v,c)) return false;
			return true;
		}
	}
	public TaskF()
	{
		Scanner cin=new Scanner(new BufferedInputStream(System.in));
		int N=cin.nextInt(),M=cin.nextInt();
		color=new int[N+2];
		adj=new LinkedList[N+2];
		for (int i=1;i<=N;i++)
		{
			adj[i]=new LinkedList<Integer>();
			color[i]=red;
		}
		for (int i=0;i<M;i++)
		{
			int u=cin.nextInt(),v=cin.nextInt();
			adj[u].add(v);
			adj[v].add(u);
		}
		boolean YES=true;
		for (int i=1;i<=N;i++)
			if (color[i]==red)
				if (!dfs(i,blue)) YES=false;
		if (YES)
		{
			System.out.println("yes");
			ArrayList<Integer> a=new ArrayList<Integer>();
			for (int i=1;i<=N;i++)
				if (color[i]==blue) a.add(i);
			System.out.println(a.size());
			for (int i=0;i<a.size();i++)
				System.out.print(a.get(i)+(i+1==a.size()?"\n":" "));
		}
		else System.out.println("no");
		cin.close();
	}
}
/*
PROGRAM: $PROGRAM
AUTHOR: Su Jiao
DATE: 2011-11-18
DESCRIPTION:
$DESCRIPTION
*/

import java.io.*;
import java.util.*;
import java.math.*;

public class Ural {
	public static void main(String args[])
	{
		new Ural();
	}
	private class Edge {
		public int v,next;
	}
	private int n,m,k,E,adj[],match[];
	private Edge edges[];
	private boolean visited[];
	void find(int u)
	{
		for (int e=adj[u];e!=-1;e=edges[e].next)
			if (!visited[edges[e].v])
			{
				visited[edges[e].v]=true;
				if (match[edges[e].v]==-1)
				{
					match[u]=edges[e].v;
					match[match[u]]=u;
					return;
				}
				else
				{
					find(match[edges[e].v]);
					if (match[match[edges[e].v]]!=edges[e].v)
					{
						match[u]=edges[e].v;
						match[match[u]]=u;
						return;
					}
				}
			}
	}
	public Ural()
	{
		Scanner cin=new Scanner(new BufferedInputStream(System.in));
		n=cin.nextInt();
		m=cin.nextInt();
		k=cin.nextInt();
		E=0;
		adj=new int[n+m];
		match=new int[n+m];
		edges=new Edge[k*2];
		Arrays.fill(adj,-1);
		Arrays.fill(match,-1);
		for (int i=0;i<k;i++)
		{
			int u=cin.nextInt()-1;
			int v=cin.nextInt()+n-1;
			edges[E]=new Edge();
			edges[E].next=adj[u];
			edges[E].v=v;
			adj[u]=E++;
			edges[E]=new Edge();
			edges[E].next=adj[v];
			edges[E].v=u;
			adj[v]=E++;
		}
		int answer=n+m;
		visited=new boolean[n+m];
		for (int i=0;i<n+m;i++)
		{
			if (match[i]==-1)
			{
				Arrays.fill(visited,false);
				find(i);
				if (match[i]!=-1) answer--;
			}
		}
		System.out.println(answer);
	}
}
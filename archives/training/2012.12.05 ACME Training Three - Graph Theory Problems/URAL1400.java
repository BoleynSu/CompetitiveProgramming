import java.util.*;
import java.io.*;

public class Main {
	public static void main(String arg[])
	{
		new Main();
	}
	int[] d;
	int bfs(int s,int n,int m)
	{
		d=new int[n];
		int[] q=new int[n];
		boolean[] inq=new boolean[n];
		Arrays.fill(inq,false);
		int qh,qt;
		inq[q[qh=qt=0]=s]=true;
		d[q[qt]]=0;
		while (qh<=qt)
		{
			int u=q[qh++];
			if (u-m>=0&&!inq[u-m])
			{
				inq[q[++qt]=u-m]=true;
				d[q[qt]]=d[u]+1;
			}
			if (u+m<n&&!inq[u+m])
			{
				inq[q[++qt]=u+m]=true;
				d[q[qt]]=d[u]+1;
			}
			if (!inq[(u+n-1)%n])
			{
				inq[q[++qt]=(u+n-1)%n]=true;
				d[q[qt]]=d[u]+1;
			}
			if (!inq[(u+1)%n])
			{
				inq[q[++qt]=(u+1)%n]=true;
				d[q[qt]]=d[u]+1;
			}
		}
		int get=0;
		for (int i=0;i<n;i++) get+=d[i];
		return get;
	}
	public Main()
	{
		Scanner cin=new Scanner(new BufferedInputStream(System.in));
		int n=cin.nextInt(),m=cin.nextInt();
		int ans=Integer.MAX_VALUE,anss=0;
		for (int s=0;s<n;s++)
		{
			int get=bfs(s,n,m);
			if (get<ans)
			{
				ans=get;
				anss=s;
			}
		}
		System.out.printf("Mean = %.2f%n",(double)(ans)/(double)(n));
		bfs(anss,n,m);
		for (int i=0;i<n;i++) if ((i+1)%m==0||i+1==n) System.out.printf("%d%n",d[i]);
		else System.out.printf("%d ",d[i]);
		cin.close();
	}
}
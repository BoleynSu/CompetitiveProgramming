import java.util.*;
import java.io.*;
import java.math.BigInteger;

public class Main {
	public static void main(String[] arg)
	{
		new Main();
	}
	public Main()
	{
		Scanner cin=new Scanner(new BufferedInputStream(System.in));
		String segma=cin.next();
		int segmas=segma.length();
		int k=cin.nextInt();
		int s=cin.nextInt();
		int l=cin.nextInt();
		int[] t=new int[l];
		for (int i=0;i<l;i++) t[i]=cin.nextInt();
		int[][] phi=new int[k+1][segmas],chi=new int[k+1][segmas];
		for (int i=1;i<=k;i++) for (int j=0;j<segmas;j++) phi[i][j]=cin.nextInt();
		for (int i=1;i<=k;i++) for (int j=0;j<segmas;j++) chi[i][j]=cin.nextInt();
		for (int i=1;i<=k;i++) for (int j=0;j<segmas;j++)
		{
			boolean[] vis=new boolean[k+1];
			int cur=i;
			while (chi[cur][j]==1&&!vis[cur])
			{
				vis[cur]=true;
				cur=phi[cur][j];
			}
			if (vis[cur]) phi[i][j]=0;
			else phi[i][j]=phi[cur][j];
		}
		int n=cin.nextInt();
		BigInteger[][] f=new BigInteger[n+1][k+1];
		Arrays.fill(f,BigInteger.ZERO);
		f[0][s]=BigInteger.ONE;
		for (int i=0;i<n;i++)
			for (int j=1;j<=k;j++)
				for (int m=0;m<segmas;m++) f[i+1][phi[j][m]]=f[i+1][phi[j][m]].add(f[i][j]);
		BigInteger ans=BigInteger.ZERO;
		for (int i=0;i<l;i++) ans=ans.add(f[n][t[i]]);
		System.out.println(ans);
		cin.close();
	}
}

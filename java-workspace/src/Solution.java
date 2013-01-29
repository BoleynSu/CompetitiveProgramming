import java.util.*;
import java.io.*;
import java.math.BigInteger;

public class Solution {
	public static void main(String[] arg)
	{
		new Solution();
	}
	public Solution()
	{
		Scanner cin=new Scanner(new BufferedInputStream(System.in));
		String segma=cin.next();
		int segmas=segma.length();
		int k=cin.nextInt();
		int s=cin.nextInt()-1;
		int l=cin.nextInt();
		int[] t=new int[l];
		for (int i=0;i<l;i++) t[i]=cin.nextInt()-1;
		int[][] phi=new int[k][segmas];
		boolean[][] chi=new boolean[k][segmas];
		for (int i=0;i<k;i++) for (int j=0;j<segmas;j++) phi[i][j]=cin.nextInt()-1;
		for (int i=0;i<k;i++) for (int j=0;j<segmas;j++) chi[i][j]=cin.nextInt()==1;
		for (int i=0;i<k;i++) for (int j=0;j<segmas;j++)
		{
			boolean[] vis=new boolean[k];
			Arrays.fill(vis,false);
			int cur=i;
			while (chi[cur][j]&&!vis[cur])
			{
				vis[cur]=true;
				cur=phi[cur][j];
			}
			if (!vis[cur])
			{
				phi[i][j]=phi[cur][j];
				chi[i][j]=false;
			}
		}
		int n=cin.nextInt();
		BigInteger[][] f=new BigInteger[n+1][k];
		for (int i=0;i<=n;i++) Arrays.fill(f[i],BigInteger.ZERO);
		f[0][s]=BigInteger.ONE;
		for (int i=0;i<n;i++)
			for (int j=0;j<k;j++)
				for (int m=0;m<segmas;m++)
					if (!chi[j][m])
						f[i+1][phi[j][m]]=f[i+1][phi[j][m]].add(f[i][j]);
		BigInteger ans=BigInteger.ZERO;
		for (int i=0;i<l;i++) ans=ans.add(f[n][t[i]]);
		System.out.println(ans);
		cin.close();
	}
}

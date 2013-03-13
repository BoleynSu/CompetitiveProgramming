import java.io.BufferedInputStream;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] arg)
	{
		new Main();
	}
	Main()
	{
		Scanner cin=new Scanner(new BufferedInputStream(System.in));
		int n=cin.nextInt();
		int[] a=new int[n];
		for (int i=0;i<n;i++) a[i]=cin.nextInt();
		int[][] g=new int[n][n];
		for (int i=0;i<n;i++)
		{
			Arrays.fill(g[i],-1);
			for (int k=0;k<i;k++)
				for (int l=0;l<i;l++)
					if (a[k]+a[l]==a[i])
						g[i][k]=l;
		}
		int[] f=new int[1<<n];
		Arrays.fill(f,19930309);
		f[1]=1;
		for (int i=1;i<n;i++)
		{
			for (int jj=1<<(i-1);jj<(1<<i);jj++)
				if (f[jj]!=19930309)
				{
					for (int k=0;k<i;k++)
					{
						int l=g[i][k];
						if (l!=-1&&(jj&(1<<k))!=0&&((jj&(1<<l))!=0))
						{
							{
								int j=jj|(1<<i);
								f[j]=Math.min(f[j],f[jj]+1);
								for (int m=0;m<i;m++)
									if ((j&(1<<m))!=0)
										f[j^(1<<m)]=Math.min(f[j^(1<<m)],f[jj]);
							}
							break;
						}
					}
				}
		}
		int ans=19930309;
		for (int i=1<<(n-1);i<(1<<n);i++) if (f[i]!=19930309)
		{
			ans=Math.min(ans,f[i]);
		}
		if (ans!=19930309) System.out.println(ans);
		else System.out.println(-1);
		cin.close();
	}
}

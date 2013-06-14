import java.io.BufferedInputStream;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner in=new Scanner(new BufferedInputStream(System.in));
		PrintStream out=System.out;
		int n=in.nextInt(),m=in.nextInt(),k=in.nextInt();
		long f[][]=new long[n+1][n+1];
		for (long[] i:f) Arrays.fill(i,Long.MAX_VALUE/2);
		for (int i=0;i<m;i++)
		{
			int l=in.nextInt(),r=in.nextInt(),c=in.nextInt();
			f[l][r]=Math.min(f[l][r],c);
		}
		for (int i=n-1;i>=0;i--)
			for (int j=0;j+i<=n;j++)
			{
				f[j][j+i]=Math.min(f[j][j+i],Math.min(j+i==n?Long.MAX_VALUE:f[j][j+i+1],j==0?Long.MAX_VALUE:f[j-1][j+i]));
			}
		long[][] g=new long[n+1][n+1];
		Arrays.fill(g[0],Long.MAX_VALUE/2);
		g[0][0]=0;
		for (int i=1;i<=n;i++)
			for (int j=0;j<=n;j++)
			{
				g[i][j]=g[i-1][j];
				for (int l=Math.max(i-j,0);l<i;l++)
					g[i][j]=Math.min(g[i][j],g[l][j-(i-l)]+f[l+1][i]);
			}
		long ans=Long.MAX_VALUE/2;
		for (int i=k;i<=n;i++)
			ans=Math.min(ans,g[n][i]);
		out.println(ans==Long.MAX_VALUE/2?-1:ans);
		out.close();
		in.close();
	}
}


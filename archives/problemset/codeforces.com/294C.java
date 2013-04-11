import java.io.BufferedInputStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;


public class Main {
	public static void main(String[] arg)
	{
		Scanner scanner=new Scanner(new BufferedInputStream(System.in));
		int n=scanner.nextInt(),m=scanner.nextInt();
		int[] a=new int[m+2];
		a[m]=0;
		a[m+1]=n+1;
		for (int i=0;i<m;i++) a[i]=scanner.nextInt();
		Arrays.sort(a);
		int two=0;
		if (a[1]!=1) two-=a[1]-a[0]-1-1;
		if (a[m]!=n) two-=a[m+1]-a[m]-1-1;
		ArrayList<Integer> b=new ArrayList<Integer>();
		for (int i=1;i<a.length;i++)
			if (a[i]-a[i-1]-1!=0)
				b.add(a[i]-a[i-1]-1);
		int N=n-m,M=b.size();
		Integer[] A=new Integer[M];
		int SUMA=0;
		int MOD=1000000007;
		long[][] C=new long[1000+1][1000+1];
		for (int i=0;i<=1000;i++) Arrays.fill(C[i],0);
		for (int i=0;i<=1000;i++)
			C[i][0]=1;
		for (int i=1;i<=1000;i++)
			for (int j=1;j<=i;j++)
				C[i][j]=(C[i-1][j]+C[i-1][j-1])%MOD;
		A=b.toArray(A);
		long dp=1;
		for (int i=0;i<M;i++)
		{
			SUMA+=A[i];
			dp*=C[SUMA][A[i]];
			dp%=MOD;
		}
		two+=N-M;
		for (int i=0;i<two;i++)
		{
			dp*=2;
			dp%=MOD;
		}
		System.out.println(dp);
		scanner.close();
	}
}


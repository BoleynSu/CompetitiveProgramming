import java.math.BigInteger;
import java.util.Arrays;
import java.util.Scanner;


public class Main {
	public static void main(String[] args) {
		int n=new Scanner(System.in).nextInt();
		BigInteger[][] s=new BigInteger[100][100];
		BigInteger[] a=new BigInteger[100];
		for (int i=0;i<s.length;i++) Arrays.fill(s[i],BigInteger.ZERO);
		Arrays.fill(a,BigInteger.ZERO);
		a[1]=BigInteger.ONE;
		for(int k=1;k<n;k++)
		{
			for(int j=1;j<=k;j++)
			{
				for(int i=1;i<=k/j;i++)
					s[k][j]=s[k][j].add(a[k+1-i*j]);
			}
			for(int j=1;j<=k;j++)
				a[k+1]=a[k+1].add(BigInteger.valueOf(j).multiply(a[j]).multiply(s[k][j]));
			a[k+1]=a[k+1].divide(BigInteger.valueOf(k));
		}
		System.out.println(a[n]);
	}
}

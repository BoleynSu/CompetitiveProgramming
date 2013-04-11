import java.io.BufferedInputStream;
import java.util.Arrays;
import java.util.Scanner;


public class Main {
	public static void main(String[] arg)
	{
		Scanner scanner=new Scanner(new BufferedInputStream(System.in));
		int n=scanner.nextInt();
		int[] t=new int[n],w=new int[n];
		int sumw=0;
		for (int i=0;i<n;i++)
		{
			t[i]=scanner.nextInt();
			w[i]=scanner.nextInt();
			sumw+=w[i];
			w[i]+=t[i];
		}
		int[] dp=new int[20000+1];
		Arrays.fill(dp,19930309);
		dp[0]=0;
		for (int i=0;i<n;i++)
			for (int j=20000;j>=w[i];j--)
				dp[j]=Math.min(dp[j],dp[j-w[i]]+t[i]);
		int ans=19930309;
		for (int i=20000;i>=sumw;i--) ans=Math.min(ans,dp[i]);
		System.out.println(ans);
		scanner.close();
	}
}


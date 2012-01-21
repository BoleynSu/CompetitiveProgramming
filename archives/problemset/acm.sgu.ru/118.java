import java.util.*;
import java.io.*;
import java.math.*;

public class Solution {
	public static void main(String arg[])
	{
		new Solution();
	}
	Solution()
	{
		Scanner cin=new Scanner(new BufferedInputStream(System.in));
		int k=cin.nextInt();
		while (k-->0)
		{
			int n=cin.nextInt();
			int a[]=new int[n];
			for (int i=0;i<n;i++) a[i]=cin.nextInt();
			BigInteger sum=BigInteger.ZERO;
			for (int i=n-1;i>=0;i--)
				sum=sum.add(BigInteger.ONE).multiply(BigInteger.valueOf(a[i]));
			String s=sum.toString();
			long x=0;
			for (int i=0;i<s.length();i++) x+=s.charAt(i)-'0';
			while (x>=10)
			{
				long y=0;
				while (x>0)
				{
					y+=x%10;
					
					x/=10;
				}
				x=y;
			}
			System.out.println(x);
		}
	}
}

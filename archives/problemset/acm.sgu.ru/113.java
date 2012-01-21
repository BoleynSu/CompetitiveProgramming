import java.math.*;
import java.io.*;
import java.util.*;

public class Solution {
	public static void main(String args[])
	{
		Scanner cin=new Scanner(new BufferedInputStream(System.in));
		int primes;
		int prime[]=new int[100000];
		prime[primes=0]=2;
		for (int i=3;i<=100000;i++)
		{
			boolean isprime=true;
			for (int j=0;j<=primes&&isprime;j++)
				if (i%prime[j]==0) isprime=false;
			if (isprime) prime[++primes]=i;
		}
		int n=cin.nextInt();
		for (int t=0;t<n;t++)
		{
			int x=cin.nextInt();
			boolean isnearlyprime=false;
			for (int i=0;i<=primes;i++)
				if (x%prime[i]==0)
				{
					isnearlyprime=true;
					x=x/prime[i];
					if (x==1) isnearlyprime=false;
					for (int j=i;j<=primes&&isnearlyprime;j++)
						if (x%prime[j]==0&&x!=prime[j]) isnearlyprime=false;
					break;
				}
			if (isnearlyprime) System.out.println("Yes");
			else System.out.println("No");
		}
	}
}

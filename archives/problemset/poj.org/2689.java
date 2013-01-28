import java.io.*;
import java.util.*;
import java.math.BigInteger;

class Main
{
	//http://en.wikipedia.org/wiki/Miller%E2%80%93Rabin_primality_test
	static class Prime
	{
		static int powWithMod(int x,int y,int z)
		{
			int result=1;
			while (y!=0)
			{
				if (y%2!=0) result=result*x%z;
				y/=2;
				x*=x;
				x%=z;
			}
			return result;
		}
		/*
		 * Input: n > 3, an odd integer to be tested for primality;
		 * Input: k, a parameter that determines the accuracy of the test
		 * Output: composite if n is composite, otherwise probably prime
		 * write n − 1 as 2^s·d with d odd by factoring powers of 2 from n − 1
		 * LOOP: repeat k times:
		 *    pick a random integer a in the range [2, n − 2]
		 *    x ← a^d mod n
		 *    if x = 1 or x = n − 1 then do next LOOP
		 *    for r = 1 .. s − 1
		 *       x ← x^2 mod n
 		 *      if x = 1 then return composite
		 *       if x = n − 1 then do next LOOP
		 *    return composite
		 * return probably prime
		 * */
		static boolean isProbablePrime(int n,int k)
		{
			if (n<=1) return false;
			if (n==2) return true;
			int s=0,d=n-1;
			while (d%2==0)
			{
				s++;
				d/=2;
			}
			for (int i=0;i<k;i++)
			{
				int a=(int)(Math.random()*(n-3))+2;
				int x=powWithMod(a,d,n);
				if (x==1||x==n-1) continue;
				boolean nextLoop=false;
				for (int r=1;r<s;r++)
				{
					x=powWithMod(x,2,n);
					if (x==1) return false;
					if (x==n-1)
					{
						nextLoop=true;
						break;
					}
				}
				if (!nextLoop) return false;
			}
			return true;
		}
	}
	public static void main(String arg[])
	{
		new Main();
	}
	Main()
	{
		Scanner cin=new Scanner(new BufferedInputStream(System.in));
		while (cin.hasNextInt())
		{
			int L=cin.nextInt(),U=cin.nextInt();
			int min=U-L+1,max=0,a=0,b=0,c=0,d=0;
			for (int i=L,j=0;i<=U;i++)
			{
				if (Prime.isProbablePrime(i,10))
				{
					if (j!=0)
					{
						int get=i-j;
						if (min>get)
						{
							min=get;
							a=j;
							b=i;
						}
						if (max<get)
						{
							max=get;
							c=j;
							d=i;
						}
					}
					j=i;
				}
			}
			if (min!=U-L+1&&max!=0) System.out.printf("%d,%d are closest, %d,%d are most distant.\n",a,b,c,d);
			else System.out.printf("There are no adjacent primes.\n");
		}
	}
}
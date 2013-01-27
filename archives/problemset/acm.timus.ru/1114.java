/*
PROGRAM: $PROGRAM
AUTHOR: Su Jiao
DATE: 2011-11-18
DESCRIPTION:
$DESCRIPTION
*/

import java.io.*;
import java.util.*;
import java.util.Comparator;
import java.math.*;

public class Ural {
	public static void main(String args[])
	{
		new Ural();
	}
	private BigInteger C(long n,long m)
	{
		BigInteger c=BigInteger.valueOf(1);
		for (int i=1;i<=n;i++)
			c=c.multiply(BigInteger.valueOf(m-i+1)).divide(BigInteger.valueOf(i));
		return c;
	}
	public Ural()
	{
		Scanner cin=new Scanner(new BufferedInputStream(System.in));
		long n=cin.nextInt(),a=cin.nextInt(),b=cin.nextInt();
		BigInteger answer=BigInteger.valueOf(0);
		for (int i=0;i<=a;i++)
			for (int j=0;j<=b;j++)
				answer=answer.add(C(n-1,i+n-1).multiply(C(n-1,j+n-1)));
		System.out.println(answer);
	}
}
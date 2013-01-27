/*
PROGRAM: $PROGRAM
AUTHOR: Su Jiao
DATE: 2011-11-18
DESCRIPTION:
$DESCRIPTION
*/

import java.io.*;
import java.util.*;
import java.math.*;

public class Ural {
	public static void main(String args[])
	{
		new Ural();
	}
	public Ural()
	{
		Scanner cin=new Scanner(new BufferedInputStream(System.in));
		int n=cin.nextInt();
		BigInteger x=BigInteger.valueOf(1);
		BigInteger y=BigInteger.valueOf(1);
		BigInteger last=BigInteger.valueOf(0);
		for (int i=1;i<=n;i++)
		{
			BigInteger a=y.divide(x);
			if (y.mod(x).compareTo(BigInteger.valueOf(0))==0)
				a=a.add(BigInteger.valueOf(1));
			if (a.compareTo(last)<=0) a=last.add(BigInteger.valueOf(1));
			BigInteger tx=x,ty=y;
			x=a.multiply(tx).subtract(ty);
			y=ty.multiply(a);
			last=a;
			System.out.println(a);
		}
	}
}
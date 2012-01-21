import java.math.*;
import java.io.*;
import java.util.*;

public class Solution {
	public static void main(String args[])
	{
		Scanner cin=new Scanner(new BufferedInputStream(System.in));
		BigInteger n=cin.nextBigInteger();
		BigInteger x=BigInteger.valueOf(1);
		for (;;)
		{
			BigInteger x_=x.add(n.divide(x)).divide(BigInteger.valueOf(2));
			if (x_.subtract(x).abs().compareTo(BigInteger.valueOf(1))<=0) break;
			x=x_;
		}
		if (x.multiply(x).compareTo(n)>0) x=x.subtract(BigInteger.valueOf(1));
		System.out.println(x);
	}
}

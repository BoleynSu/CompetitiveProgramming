import java.math.*;
import java.io.*;
import java.util.*;

public class Solution {
	public static void main(String args[])
	{
		Scanner cin=new Scanner(new BufferedInputStream(System.in));
		BigInteger a=cin.nextBigInteger();
		BigInteger b=cin.nextBigInteger();
		System.out.println(a.pow(b.intValue()).subtract(b.pow(a.intValue())));
	}
}

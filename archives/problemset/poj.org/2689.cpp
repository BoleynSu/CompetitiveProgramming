import java.io.*;
import java.util.*;
import java.math.BigInteger;

class Main
{
	public static void main(String arg[])
	{
		new Main();
	}
	Main()
	{
		Scanner cin=new Scanner(new BufferedInputStream(System.in));
		while (cin.hasNextBigInteger())
		{
			BigInteger L=cin.nextBigInteger(),U=cin.nextBigInteger();
			BigInteger min=null,max=null,a=null,b=null,c=null,d=null;
			for (BigInteger i=L,j=null;i.compareTo(U)<=0;i=i.add(BigInteger.ONE))
			{
				if (i.isProbablePrime(200))
				{
					if (j!=null)
					{
						BigInteger get=i.subtract(j);
						if (min==null||min.compareTo(get)>0)
						{
							min=get;
							a=j;
							b=i;
						}
						if (max==null||max.compareTo(get)<0)
						{
							max=get;
							c=j;
							d=i;
						}
					}
					j=i;
				}
			}
			if (min!=null&&max!=null)
				System.out.println(a.toString()+","+b.toString()+" are closest, "+c.toString()+","+d.toString()+" are most distant.");
			else System.out.println("There are no adjacent primes.");
		}
	}
}

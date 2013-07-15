import java.math.BigInteger;
import java.util.Arrays;
import java.util.Scanner;


public class Main {
	static final BigInteger TWO = BigInteger.valueOf(2);
	public static void main(String[] args) {
		BigInteger n=new Scanner(System.in).nextBigInteger();
		BigInteger[] ans=new BigInteger[64];
		int anss=0;
		for (int x=0;x<64;x++)
		{
			BigInteger t=TWO.pow(x);
			BigInteger tmo=t.subtract(BigInteger.ONE);
			BigInteger l=BigInteger.ONE.negate(),r=TWO.pow(64);
			while (!r.subtract(l).equals(BigInteger.ONE))
			{
				BigInteger mid=l.add(r).divide(TWO);
				BigInteger k=mid.multiply(TWO).add(BigInteger.ONE);
				if (k.multiply(mid.add(tmo)).compareTo(n)>=0) r=mid;
				else l=mid;
			}
			BigInteger k=r.multiply(TWO).add(BigInteger.ONE);
			if (k.multiply(r.add(tmo)).equals(n)) ans[anss++]=k.multiply(t);
		}
		Arrays.sort(ans,0,anss);
		for (int i=0;i<anss;i++) System.out.println(ans[i]);
		if (anss==0) System.out.println(-1);
	}

}

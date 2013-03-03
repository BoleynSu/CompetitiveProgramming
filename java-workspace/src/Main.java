import java.io.BufferedInputStream;
import java.math.BigInteger;
import java.util.Scanner;
import java.security.SecureRandom;

class PollardRho {
    private final static BigInteger ZERO = new BigInteger("0");
    private final static BigInteger ONE  = new BigInteger("1");
    private final static BigInteger TWO  = new BigInteger("2");
    private final static SecureRandom random = new SecureRandom();

    public static BigInteger rho(BigInteger N) {
        BigInteger divisor;
        BigInteger c  = new BigInteger(N.bitLength(), random);
        BigInteger x  = new BigInteger(N.bitLength(), random);
        BigInteger xx = x;

        // check divisibility by 2
        if (N.mod(TWO).compareTo(ZERO) == 0) return TWO;

        do {
            x  =  x.multiply(x).mod(N).add(c).mod(N);
            xx = xx.multiply(xx).mod(N).add(c).mod(N);
            xx = xx.multiply(xx).mod(N).add(c).mod(N);
            divisor = x.subtract(xx).gcd(N);
        } while((divisor.compareTo(ONE)) == 0);

        return divisor;
    }

    public static BigInteger factor(BigInteger N){
        for (BigInteger i=TWO;i.compareTo(N)<0;i=i.add(ONE)) if (N.mod(i).equals(ZERO)) return i;
        return N;
    	/*if (N.isProbablePrime(50)) return N;
        BigInteger divisor = rho(N);
        return factor(divisor);*/
    }

}

public class Main
{
	public static void main(String[] arg)
	{
		try
		{
			new Main();
		}
		catch(Exception e)
		{
		}
	}
	public Main()
	{
		//2854240469829088704
		Scanner cin=new Scanner(new BufferedInputStream(System.in));
		while (cin.hasNextBigInteger())
		{
			BigInteger x=cin.nextBigInteger();
			int cnt=0;
			BigInteger[] fac=new BigInteger[1000];
			int[] num=new int[1000];
			BigInteger t=x;
			while (!t.equals(BigInteger.ONE))
			{
//				while (t.compareTo(new BigInteger("2854240469829088704"))==0)
//				{
//					System.out.println("ASSART");
//				}
				fac[cnt]=PollardRho.factor(t);
				num[cnt]=0;
				do
				{
					t=t.divide(fac[cnt]);
					num[cnt]++;
				}
				while (t.mod(fac[cnt]).equals(BigInteger.ZERO));
				cnt++;
			}
			BigInteger[] stack=new BigInteger[1000];
			int[] step=new int[1000];
			int top=0;
			stack[top]=BigInteger.ONE;
			step[top]=0;
			int anss=0;
			long[] alst=new long[1000],blst=new long[1000];
			for (;;)
			{
				if (top==cnt)
				{
					BigInteger y=stack[top];
					BigInteger delta=x.divide(y).multiply(BigInteger.valueOf(4)).subtract(y.multiply(y)).multiply(BigInteger.valueOf(3));
					if (delta.signum()>=0)
					{
						BigInteger sqrt_delta=delta.shiftRight(delta.bitLength()/2);
						for (;;)
						{
							if (sqrt_delta.equals(BigInteger.ZERO)) break;
							BigInteger sqrt_delta_=sqrt_delta.add(delta.divide(sqrt_delta)).divide(BigInteger.valueOf(2));
							if (sqrt_delta_.subtract(sqrt_delta).abs().compareTo(BigInteger.valueOf(1))<=0) break;
							sqrt_delta=sqrt_delta_;
						}
						if (sqrt_delta.multiply(sqrt_delta).compareTo(delta)>0) sqrt_delta=sqrt_delta.subtract(BigInteger.ONE);
						if (sqrt_delta.multiply(sqrt_delta).compareTo(delta)<0) sqrt_delta=sqrt_delta.add(BigInteger.ONE);
						if (sqrt_delta.multiply(sqrt_delta).compareTo(delta)==0)
						{
							BigInteger a=y.multiply(BigInteger.valueOf(3)).subtract(sqrt_delta);
							if (a.mod(BigInteger.valueOf(6)).equals(BigInteger.ZERO)&&a.signum()>0)
							{
								a=a.divide(BigInteger.valueOf(6));
								alst[anss]=a.longValue();
								blst[anss]=y.subtract(a).longValue();
								anss++;
							}
						}						
					}
					top--;
					if (top>=0)
					{
						step[top]++;
						stack[top]=stack[top].multiply(fac[top]);
					}
					else break;
				}
				else
				{
					if (step[top]>num[top])
					{
						top--;
						if (top>=0)
						{
							step[top]++;
							stack[top]=stack[top].multiply(fac[top]);
						}
						else break;
					}
					else
					{
						top++;
						stack[top]=stack[top-1];
						step[top]=0;
					}
				}
			}
			
			System.out.print(anss);
			for (int i=0;i<anss;i++)
			{
				for (int j=i+1;j<anss;j++)
					if (alst[i]>alst[j])
					{
						long swap;
						swap=alst[i];
						alst[i]=alst[j];
						alst[j]=swap;
						swap=blst[i];
						blst[i]=blst[j];
						blst[j]=swap;
					}
				System.out.print(" ("+alst[i]+","+blst[i]+")");
			}
			System.out.println();
		}
		cin.close();
	}
}

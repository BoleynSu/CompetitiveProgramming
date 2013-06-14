import java.io.BufferedInputStream;
import java.math.BigInteger;
import java.util.Scanner;


public class Main {

    public Main()
    {
        BigInteger fx[][]=new BigInteger[400+2][400+2];
        BigInteger fy[][]=new BigInteger[400+2][400+2];
        int MAX=400;
        fx[0][1]=BigInteger.ONE;
        fy[0][1]=BigInteger.ONE;
        for (int i=1;i<=MAX;i++)
        {
            for (int j=i+1;j>=2;j--)
            {
                fx[i][j]=fx[i-1][j-1].multiply(BigInteger.valueOf(i));
                fy[i][j]=fy[i-1][j-1].multiply(BigInteger.valueOf(j));
                BigInteger gcd=fx[i][j].gcd(fy[i][j]);
                fx[i][j]=fx[i][j].divide(gcd);
                fy[i][j]=fy[i][j].divide(gcd);
                if (fy[i][j].signum()<0)
                {
                    fx[i][j]=fx[i][j].negate();
                    fy[i][j]=fy[i][j].negate();
                }
                //System.out.println(fx[i][j]+"/"+fy[i][j]+" ");
            }
            BigInteger x=BigInteger.ONE,y=BigInteger.ONE;
            for (int j=i+1;j>=2;j--)
            {
                BigInteger ny=y.multiply(fy[i][j]),nx=x.multiply(fy[i][j]).subtract(y.multiply(fx[i][j]));
                x=nx;
                y=ny;
                BigInteger gcd=x.gcd(y);
                x=x.divide(gcd);
                y=y.divide(gcd);
            }
            if (y.signum()<0)
            {
                x=x.negate();
                y=y.negate();
            }
            fx[i][1]=x;
            fy[i][1]=y;
            //System.out.println();
        }
        Scanner cin=new Scanner(new BufferedInputStream(System.in));
        int p=cin.nextInt();
        for (int i=1;i<=p;i++)
        {
            cin.nextInt();
            int n=cin.nextInt(),m=cin.nextInt();
            System.out.print(i+" ");
            if (fy[n][m].equals(BigInteger.ONE)) System.out.println(fx[n][m]);
            else System.out.println(fx[n][m]+"/"+fy[n][m]); 
        }
    }
    /**
     * @param args
     */
    public static void main(String[] args) {
        new Main();

    }

}


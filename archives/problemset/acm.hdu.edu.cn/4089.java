import java.math.*;
import java.io.*;
import java.util.*;

class Main
{
    public static void main(String arg[])
    {
        new Main();
    }
    Main()
    {
        Scanner cin=new Scanner(new BufferedInputStream(System.in));
        while (cin.hasNext())
        {
            int N=cin.nextInt(),M=cin.nextInt(),K=cin.nextInt();
            double p1=cin.nextDouble(),p2=cin.nextDouble(),p3=cin.nextDouble(),p4=cin.nextDouble();
            final double eps=1e-8;
            if (Math.abs(1.0-p1)<1e-8)
            {
                System.out.printf("%.5f%n",0.0);
            }
            else
            {
                double fx[][]=new double[2][N];
                double fc[][]=new double[2][N];
                double f[][]=new double[2][N];
                N--;
                M--;
                K--;
                /*
                (m=1)
                f[n][1]=+p1*f[n][1]
                    +p2*f[n][n]
                    +p3*0
                    +p4*1
                (1<m<=k)
                f[n][m]=+p1*f[n][m]
                    +p2*f[n][m-1]
                    +p3*f[n-1][m-1]
                    +p4*1
                (k<m<=n)
                f[n][m]=+p1*f[n][m]
                    +p2*f[n][m-1]
                    +p3*f[n-1][m-1]
                    +p4*0
                */
                for (int _n_=0;_n_<=N;_n_++)
                {
                    int n=_n_%2;
                    int n_1=(_n_-1)%2;
                    fx[n][0]=p2/(1.0-p1);
                    fc[n][0]=p4/(1.0-p1);
                    for (int m=1;(m<=K)&&(m<=_n_);m++)
                    {
                        fx[n][m]=p2*fx[n][m-1]/(1.0-p1);
                        fc[n][m]=(p2*fc[n][m-1]+p3*f[n_1][m-1]+p4)/(1.0-p1);
                    }
                    for (int m=K+1;m<=_n_;m++)
                    {
                        fx[n][m]=p2*fx[n][m-1]/(1.0-p1);
                        fc[n][m]=(p2*fc[n][m-1]+p3*f[n_1][m-1])/(1.0-p1);
                    }
                    double fnn=fc[n][_n_]/(1.0-fx[n][_n_]);
                    if (Math.abs(1.0-fx[n][_n_])<1e-8)
                    {
                        System.out.printf("%.5f%n",0.0);
                        break;
                    }
                    for (int m=0;m<=_n_;m++)
                        f[n][m]=fnn*fx[n][m]+fc[n][m];
                    if (_n_==N) System.out.printf("%.5f%n",f[n][M]);
                }
            }
        }
    }
}

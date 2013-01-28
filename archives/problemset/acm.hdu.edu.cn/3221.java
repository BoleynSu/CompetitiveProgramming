import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
    public static void main(String[] arg)
    {
        new Main();
    }
    long c(long p)
    {
        long phi=p;
        for (int i=2;i<=p;i++)
            if (p%i==0)
            {
                phi/=i;
                phi*=i-1;
                while (p%i==0) p/=i;
            }
        return phi;
    }
    long[][] mul(long a[][],long b[][],long p)
    {
        long c[][]=new long[2][2];
        for (int i=0;i<2;i++)
            for (int j=0;j<2;j++)
            {
                c[i][j]=0;
                for (int k=0;k<2;k++)
                    c[i][j]=(c[i][j]+a[i][k]*b[k][j])%p;
            }
        return c;
    }
    long fib(long n,long p)
    {
        if (n==-1) return 1;
        long A[][]=new long[2][2];
        long M[][]=new long[2][2];
        A[0][0]=A[1][1]=1;
        A[0][1]=A[1][0]=0;
        M[0][0]=M[0][1]=M[1][0]=1;
        M[1][1]=0;
        while (n!=0)
        {
            if (n%2==1)
            {
                A=mul(A,M,p);
            }
            M=mul(M,M,p);
            n/=2;
        }
        return A[1][0];
    }
    long pow(long x,long y,long p)
    {
        long a=1;
        while (y!=0)
        {
            if (y%2==1) a=(a*x)%p;
            x=(x*x)%p;
            y/=2;
        }
        return a;
    }
    Main()
    {
        Scanner cin=new Scanner(new BufferedInputStream(System.in));
        int T=cin.nextInt();
        for (int t=1;t<=T;t++)
        {
            long answer=0;
            int a=cin.nextInt(),b=cin.nextInt(),p=cin.nextInt(),n=cin.nextInt();
            if (n>30&&p>1) answer=pow(a,fib(n-2,c(p))+c(p),p)*pow(b,fib(n-1,c(p))+c(p),p)%p;
            if (n<=30&&p>1) answer=pow(a,fib(n-2,1000000000),p)*pow(b,fib(n-1,1000000000),p)%p;
            System.out.println("Case #"+t+": "+answer);
        }
        cin.close();
    }
}


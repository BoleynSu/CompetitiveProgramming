import java.io.*;
import java.util.*;
import java.math.*;

public class Ural {
	public static void main(String args[]) throws IOException
	{
		new Ural();
	}
	public int N;
	public BigInteger x[],y[],ax,ay,bx,by,cx,cy;
	public BigInteger cross(BigInteger ax,BigInteger ay,BigInteger bx,BigInteger by,BigInteger cx,BigInteger cy)
	{
		return bx.subtract(ax).multiply(cy.subtract(ay)).subtract(by.subtract(ay).multiply(cx.subtract(ax)));
	}
	public BigInteger dot(BigInteger ax,BigInteger ay,BigInteger bx,BigInteger by,BigInteger cx,BigInteger cy)
	{
		return bx.subtract(ax).multiply(cx.subtract(ax)).add(by.subtract(ay).multiply(cy.subtract(ay)));
	}
	public boolean less(BigInteger xa,BigInteger ya,BigInteger xb,BigInteger yb)
	{
		BigInteger A=BigInteger.valueOf(dot(xa,ya,ax,ay,bx,by).signum()).multiply(dot(xa,ya,ax,ay,bx,by).pow(2).multiply(dot(xb,yb,ax,ay,ax,ay).multiply(dot(xb,yb,bx,by,bx,by))));
		BigInteger B=BigInteger.valueOf(dot(xb,yb,ax,ay,bx,by).signum()).multiply(dot(xb,yb,ax,ay,bx,by).pow(2).multiply(dot(xa,ya,ax,ay,ax,ay).multiply(dot(xa,ya,bx,by,bx,by))));
		return A.compareTo(B)<0;
	}
	public void nth_element(int l,int r,int n)
	{
		int i=l,j=r;
		BigInteger midx=x[(l+r)/2];
		BigInteger midy=y[(l+r)/2];
		while (i<=j)
		{
			while (less(x[i],y[i],midx,midy)) i++;
			while (less(midx,midy,x[j],y[j])) j--;
			if (i<=j)
			{
				BigInteger swap;
				swap=x[i];
				x[i]=x[j];
				x[j]=swap;
				swap=y[i];
				y[i]=y[j];
				y[j]=swap;
				i++;
				j--;
			}
		}
		if (l<j)
		{
			if (n<=j) nth_element(l,j,n);
		}
		if (i<r)
		{
			nth_element(i,r,n-i);
		}
	}
	public Ural()
	{
		Scanner cin=new Scanner(new BufferedInputStream(System.in));
		N=cin.nextInt();
		if (N%2!=1)
		{
			System.out.println("No solution");
			return ;
		}
		x=new BigInteger[N];
		y=new BigInteger[N];
		for (int i=0;i<N;i++)
		{
			x[i]=cin.nextBigInteger();
			y[i]=cin.nextBigInteger();
		}
		int ai,bi,ci;
		ax=x[0];
		ay=y[0];
		ai=0;
		for (int i=1;i<N;i++)
			if (x[i].compareTo(ax)>0)
			{
				ax=x[i];
				ay=y[i];
				ai=i;
			}
		N--;
		x[ai]=x[N];
		y[ai]=y[N];
		System.out.println(ax+" "+ay);
		bx=x[0];
		by=y[0];
		bi=0;
		for (int i=1;i<N;i++)
			if (cross(ax,ay,bx,by,x[i],y[i]).compareTo(BigInteger.valueOf(0))>0)
			{
				bx=x[i];
				by=y[i];
				bi=i;
			}
		N--;
		x[bi]=x[N];
		y[bi]=y[N];
		System.out.println(bx+" "+by);
		nth_element(0,N-1,N/2);
		cx=x[N/2];
		cy=y[N/2];
		System.out.println(cx+" "+cy);
	}
}

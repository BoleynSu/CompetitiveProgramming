/*
PROGRAM: $PROGRAM
AUTHOR: Su Jiao
DATE: 2011-11-18
DESCRIPTION:
$DESCRIPTION
*/

import java.io.*;
import java.util.*;
import java.util.Comparator;
import java.math.*;

public class Ural {
	public static void main(String args[])
	{
		new Ural();
	}
	private static class Point {
		public double x,y;
	}
	private static class Square {
		public int id;
		public Point a,b,c,d;
		public Square()
		{
			a=new Point();
			b=new Point();
			c=new Point();
			d=new Point();
		}
	}
	private static class MyComparator implements Comparator<Square> {
		public static Point p;
		private static final double eps=1e-14;
		private double sqr(double x)
		{
			return x*x;
		}
		private double dot(Point a,Point b,Point c)
		{
			return (a.x-b.x)*(a.x-c.x)+(a.y-b.y)*(a.y-c.y);
		}
		private double cross(Point a,Point b,Point c)
		{
			return (a.x-b.x)*(a.y-c.y)-(a.y-b.y)*(a.x-c.x);
		}
		private double distance(Point a,Point b)
		{
			return Math.sqrt(dot(a,b,b));
		}
		private double distance(Point a,Point b,Point p)
		{
			return Math.abs(cross(a,b,p)/distance(a,b));
		}
		public double distance(Square s,Point p)
		{
			double distance;
			if (distance(s.a,s.c)<eps) distance=distance(s.a,p);
			else
			{
				if (dot(s.a,s.b,p)>0&&dot(s.b,s.a,p)>0&&dot(s.a,s.d,p)>0&&dot(s.d,s.a,p)>0) distance=0;
				else if (dot(s.a,s.b,p)>0&&dot(s.b,s.a,p)>0)
				{
					double a=distance(s.a,s.b,p),b=distance(s.c,s.d,p);
					distance=a<b?a:b;
				}
				else if (dot(s.a,s.d,p)>0&&dot(s.d,s.a,p)>0)
				{
					double a=distance(s.a,s.d,p),b=distance(s.c,s.b,p);
					distance=a<b?a:b;
				}
				else
				{

					double distances[]=new double[]{distance(s.a,p),distance(s.b,p),distance(s.c,p),distance(s.d,p)};
					distance=distances[0];
					for (int i=1;i<distances.length;i++)
						if (distance>distances[i])
							distance=distances[i];
				}
			}
			return distance;
		}
		private int sign(double x)
		{
			if (x<-eps) return -1;
			else if (x>+eps) return 1;
			else return 0;
		}
		private int toInteger(Square a,Square b,double x)
		{
			if (sign(x)!=0) return sign(x);
			else if (a.id<b.id) return -1;
			else return 1;
 		}
		public int compare(Square a,Square b)
		{
			return toInteger(a,b,distance(a,p)-distance(b,p));
		}
	}
	public Ural()
	{
		Scanner cin=new Scanner(new BufferedInputStream(System.in));
		int n=cin.nextInt();
		Square squares[]=new Square[n];
		for (int i=0;i<n;i++)
		{
			squares[i]=new Square();
			squares[i].id=i+1;
			squares[i].a.x=cin.nextDouble();
			squares[i].a.y=cin.nextDouble();
			squares[i].c.x=cin.nextDouble();
			squares[i].c.y=cin.nextDouble();
			Point mid=new Point();
			mid.x=(squares[i].a.x+squares[i].c.x)/2;
			mid.y=(squares[i].a.y+squares[i].c.y)/2;
			squares[i].b.x=mid.x-(squares[i].a.y-mid.y);
			squares[i].b.y=mid.y+(squares[i].a.x-mid.x);
			squares[i].d.x=mid.x-(squares[i].c.y-mid.y);
			squares[i].d.y=mid.y+(squares[i].c.x-mid.x);
		}
		MyComparator.p=new Point();
		MyComparator.p.x=cin.nextDouble();
		MyComparator.p.y=cin.nextDouble();
		Arrays.sort(squares,new MyComparator());
		for (int i=0;i<n;i++) System.out.printf("%d%c",squares[i].id,i+1==n?'\n':' ');
	}
}

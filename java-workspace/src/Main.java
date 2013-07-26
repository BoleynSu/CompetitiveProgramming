import java.io.BufferedInputStream;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;


class Constants
{
	public static final double eps=1e-8;
}
class Point
{
	public double x,y;
	public Point(double x,double y)
	{
		this.x=x;
		this.y=y;
	}
	public Point add(Point other)
	{
		return new Point(x+other.x,y+other.y);
	}
	public Point subtract(Point other)
	{
		return new Point(x-other.x,y-other.y);
	}
	public Point multiply(double other)
	{
		return new Point(x*other,y*other);
	}
	public Point divide(double other)
	{
		return new Point(x/other,y/other);
	}
	public double cross(Point other)
	{
		return x*other.y-y*other.x;
	}
	public double dot(Point other)
	{
		return x*other.x+y*other.y;
	}
	public double length()
	{
		return Math.sqrt(x*x+y*y);
	}
	public boolean in(Point[] other)
	{
//		double s=0;
//		for (int i=0,j=other.length-1;i<other.length;j=i++) s+=subtract(other[j]).cross(subtract(other[i]));
//		return s>Constants.eps;
		boolean in=false;
		for (int i=0,j=other.length-1;i<other.length;j=i++)
			if ((other[j].y>y)!=(other[i].y>y)
				&&x<(other[i].x-other[j].x)/(other[i].y-other[j].y)*(y-other[j].y)+other[j].x)
				in=!in;
		return in;
	}
}
class Segment
{
	public Point x,y;
	public Segment(Point x,Point y)
	{
		this.x=x;
		this.y=y;
	}
	public Point intersection(Segment other)
	{
		Point va=y.subtract(x),vb=other.y.subtract(other.x);
		if (Math.abs(va.cross(vb))<Constants.eps) return null;
		else return x.add(va.multiply(other.x.subtract(x).cross(vb)/va.cross(vb)));
	}
}
class MyComparator implements Comparator<Point>
{
	private Point o;
	public MyComparator(Point o)
	{
		this.o=o;
	}
	@Override
	public int compare(Point a,Point b)
	{
		double alpha=Math.atan2(a.y-o.y,a.x-o.x);
		double beta=Math.atan2(b.y-o.y,b.x-o.x);
		return
			alpha>beta?-1:
			alpha<beta?1:
			0;
	}
}
public class Main
{
	public static void main(String[] arg)
	{
		new Main();
	}
	public Main()
	{
		Scanner cin=new Scanner(new BufferedInputStream(System.in));
		{
			Point o=new Point(cin.nextDouble(),cin.nextDouble());
			int n=cin.nextInt();
			Point[] p=new Point[n];
			for (int i=0;i<p.length;i++) p[i]=new Point(cin.nextDouble(),cin.nextDouble());
			{
				int pIndex=-1;
				for (int i=0;i<p.length;i++) if (Math.abs(p[i].subtract(o).length())<Constants.eps) pIndex=i;
				Point[] q=new Point[pIndex==-1?p.length:p.length-1];
				int qIndex=0;
				for (int i=0;i<p.length;i++) if (i!=pIndex) q[qIndex++]=p[i];
				Arrays.sort(q,new MyComparator(o));
				//for (int i=0;i<q.length;i++) System.out.println(q[i].x+","+q[i].y);
				double answer=0;
				for (int i=0,j=q.length-1;i<q.length;j=i++)
				{
					double get=Double.MAX_VALUE;
					boolean found=false,in=false;
					for (int ii=0,jj=p.length-1;ii<p.length;jj=ii++)
					{
						Point a=new Segment(p[jj],p[ii]).intersection(new Segment(o,q[j]));
						Point b=new Segment(p[jj],p[ii]).intersection(new Segment(o,q[i]));
						if (a!=null
							&&b!=null
							&&a.subtract(o).dot(q[j].subtract(o))>-Constants.eps
							&&b.subtract(o).dot(q[i].subtract(o))>-Constants.eps
							&&p[jj].subtract(a).dot(p[ii].subtract(a))<Constants.eps
							&&p[jj].subtract(b).dot(p[ii].subtract(b))<Constants.eps
							&&Math.abs(a.subtract(o).cross(b.subtract(o)))/2>Constants.eps)
						{
							if (get>Math.abs(a.subtract(o).cross(b.subtract(o)))/2)
							{
								get=Math.abs(a.subtract(o).cross(b.subtract(o)))/2;
								in=o.add(a).add(b).divide(3).in(p);
								found=true;
							}
						}
					}
					if (!found||!in) get=0;
					//System.out.println(get);
					//System.out.println(q[j].x+" "+q[j].y+" "+q[i].x+" "+q[i].y);
					answer+=get;
				}
				System.out.printf("%.2f\n",answer);
			}
		}
		cin.close();
	}
}
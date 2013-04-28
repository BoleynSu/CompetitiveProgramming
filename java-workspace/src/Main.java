import java.util.Arrays;
import java.util.Scanner;


public class Main {

	static Scanner sc=new Scanner(System.in);
	static void doit()
	{
		int n;
		double[] x,y,lst;
		n=sc.nextInt();
		x=new double[n];
		y=new double[n];
		lst=new double[n];
		for (int i=0;i<n;i++)
		{
			double xi,yi;
			xi=Math.random();yi=Math.random();
			xi=sc.nextDouble();
			yi=sc.nextDouble();
			y[i]=yi/xi;
			x[i]=xi;
		}
		double pi=Math.acos(-1);
		double dd=pi/180/40;
		double eps=1e-2;
		int ans=0;
		for (double d=pi/2+dd;d<pi;d+=dd)
		{
			double k=Math.tan(d);
			for (int i=0;i<n;i++)
				lst[i]=y[i]-k*x[i];
			Arrays.sort(lst);
			for (int i=0;i<n;i++)
			{
				int j=i;
				while (j+1<n&&lst[j+1]-lst[i]<eps) j++;
				if (j-i+1>ans) ans=j-i+1;
			}
		}
		System.out.printf("%d\n",ans);
	}
	public static void main(String[] args) {
		int t=sc.nextInt();
		while ((t--)!=0) doit();
	}

}

import java.io.IOException;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Comparator;


public class Main {
	public static void main(String[] args) throws IOException {
		//Scanner in=new Scanner(new BufferedInputStream(System.in));
		PrintStream out=System.out;
		int x=nextInt();
		int n=0;
		for (int i=1;i!=x;i*=4) n++;
		Integer[] a=new Integer[x];
		for (int i=0;i<x;i++) a[i]=nextInt();
		Arrays.sort(a,new Comparator<Integer>(){
			@Override
			public int compare(Integer o1, Integer o2) {
				// TODO Auto-generated method stub
				return o2-o1;
			}
		});
		long[] sum=new long[x];
		sum[0]=a[0];
		for (int i=1;i<x;i++) sum[i]=sum[i-1]+a[i];
		long ans=0;
		for (int i=0,j=1;i<=n;i++,j*=4)
			ans+=sum[j-1];
		out.println(ans);
		out.close();
		//in.close();
	}
	static int nextInt() throws IOException
	{
		int c;
		do c=System.in.read();
		while (!('0'<=c&&c<='9'));
		int x=c-'0';
		for (;;)
		{
			c=System.in.read();
			if ('0'<=c&&c<='9') x=x*10+c-'0';
			else break;
		}
		return x;
	}
}

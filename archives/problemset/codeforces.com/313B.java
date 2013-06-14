import java.io.BufferedInputStream;
import java.io.PrintStream;
import java.util.Scanner;


public class Main {
	public static void main(String[] args) {
		Scanner in=new Scanner(new BufferedInputStream(System.in));
		PrintStream out=System.out;
		String s=in.next();
		int[] sum=new int[s.length()];
		sum[0]=0;
		for (int i=1;i<s.length();i++)
			sum[i]=sum[i-1]+(s.charAt(i)==s.charAt(i-1)?1:0);
		int m=in.nextInt();
		for (int i=0;i<m;i++)
		{
			int l=in.nextInt()-1,r=in.nextInt()-1;
			out.println(sum[r]-sum[l]);	
		}
		out.close();
		in.close();
	}
}


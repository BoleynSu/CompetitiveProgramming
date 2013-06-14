import java.io.BufferedInputStream;
import java.io.PrintStream;
import java.util.Scanner;



public class CF185A {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in=new Scanner(new BufferedInputStream(System.in));
		PrintStream out=System.out;
		long n=in.nextLong(),k=in.nextLong();
		if (n*(n-1)/2>k)
		{
			for (int i=0;i<n;i++)
				out.println(0+" "+i);
		}
		else out.println("no solution");
		out.close();
		in.close();
	}

}


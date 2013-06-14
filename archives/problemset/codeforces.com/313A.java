import java.io.BufferedInputStream;
import java.io.PrintStream;
import java.util.Scanner;


public class Main {
	public static void main(String[] args) {
		Scanner in=new Scanner(new BufferedInputStream(System.in));
		PrintStream out=System.out;
		int n=in.nextInt();
		if (n>=0) out.println(n);
		else out.println(Math.max(-((-n)/10), -((-n)/100*10+(-n)%10)));
		out.close();
		in.close();
	}
}


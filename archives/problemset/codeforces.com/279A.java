import java.io.BufferedInputStream;
import java.util.Scanner;

public class Main {
	public static void main(String[] arg)
	{
		new Main();
	}
	Main()
	{
		Scanner cin=new Scanner(new BufferedInputStream(System.in));
		int x=cin.nextInt(),y=cin.nextInt();
		if (x==0&&y==0) System.out.println(0);
		else if (y>x&&y>=-x) System.out.println(y*4-2);
		else if (y<-x&&y>=x) System.out.println(-x*4-1);
		else if (y<x&&y<=1-x) System.out.println(-y*4);
		else if (y>1-x&&y<=x) System.out.println(x*4-3);
		cin.close();
	}
}

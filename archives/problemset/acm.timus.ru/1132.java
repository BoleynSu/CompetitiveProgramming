import java.io.BufferedInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Scanner;


public class Main
{
	public static void main(String[] arg)
	{
		new Main();
	}
	Main()
	{
		//Scanner cin=new Scanner(new BufferedInputStream(System.in));
		InputReader cin=new InputReader(System.in);
		PrintWriter cout=new PrintWriter(System.out);
		int k=cin.readInt();//int k=cin.nextInt();
		int[] a=new int[k],n=new int[k];
		ArrayList<ArrayList<Integer> > map=new ArrayList<ArrayList<Integer> >(32768);
		for (int i=0;i<32768;i++) map.add(null);
		for (int i=0;i<k;i++)
		{
			a[i]=cin.readInt();//a[i]=cin.nextInt();
			n[i]=cin.readInt();//n[i]=cin.nextInt();
			a[i]%=n[i];
			if (map.get(n[i])==null) map.set(n[i],new ArrayList<Integer>());
			map.get(n[i]).add(i);
		}
		int[] ans=new int[k];
		for (int prime=0;prime<map.size();prime++) if (map.get(prime)!=null)
		{
			ArrayList<Integer> indexs=map.get(prime);
			int[] get=new int[prime];
			Arrays.fill(get,-1);
			for (int i=0;i<=prime/2;i++)
				get[(i*i)%prime]=i;
			for (int index:indexs) ans[index]=get[a[index]];
		}
		for (int i=0;i<k;i++)
		{
			if (ans[i]==-1) cout.println("No root");
			else
			{
				if (ans[i]==0||ans[i]+ans[i]==n[i]) cout.println(ans[i]);
				else cout.println(ans[i]+" "+(n[i]-ans[i]));
			}
		}
		cout.close();
		//cin.close();
	}
}

class InputReader {

	private InputStream stream;
	private byte[] buf = new byte[1024];
	private int curChar;
	private int numChars;
	private SpaceCharFilter filter;

	public InputReader(InputStream stream) {
		this.stream = stream;
	}

	public int read() {
		if (numChars == -1)
			throw new InputMismatchException();
		if (curChar >= numChars) {
			curChar = 0;
			try {
				numChars = stream.read(buf);
			} catch (IOException e) {
				throw new InputMismatchException();
			}
			if (numChars <= 0)
				return -1;
		}
		return buf[curChar++];
	}

	public int readInt() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		int sgn = 1;
		if (c == '-') {
			sgn = -1;
			c = read();
		}
		int res = 0;
		do {
			if (c < '0' || c > '9')
				throw new InputMismatchException();
			res *= 10;
			res += c - '0';
			c = read();
		} while (!isSpaceChar(c));
		return res * sgn;
	}

	public boolean isSpaceChar(int c) {
		if (filter != null)
			return filter.isSpaceChar(c);
		return isWhitespace(c);
	}

	public static boolean isWhitespace(int c) {
		return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
	}

	public interface SpaceCharFilter {
		public boolean isSpaceChar(int ch);
	}
}

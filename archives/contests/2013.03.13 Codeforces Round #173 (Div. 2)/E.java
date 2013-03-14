import java.io.IOException;
import java.io.InputStream;
import java.util.InputMismatchException;

public class Main {
	public static void main(String[] arg)
	{
		new Main();
	}
	class node
	{
		node[] n=new node[2];
	}
	Main()
	{
		InputReader cin=new InputReader(System.in);
		int n=cin.readInt();
		long[] a=new long[n];
		for (int i=0;i<n;i++) a[i]=cin.readLong();
		long[] s=new long[n+1];
		s[0]=0;
		for (int i=0;i<n;i++) s[i+1]=s[i]^a[i];
		node root=new node();
		for (int i=0;i<=n;i++)
		{
			node u=root;
			for (int j=39;j>=0;j--)
			{
				int c=(int)((s[i]>>j)&(long)(1));
				if (u.n[c]==null) u.n[c]=new node();
				u=u.n[c];
			}
		}
		long ans=Long.MIN_VALUE;
		for (int i=1;i<=n;i++)
		{
			long get=0;
			node u=root;
			for (int j=39;j>=0;j--)
			{
				get^=((long)(1))<<j;
				int c=(int)(((get^s[n]^s[i])>>j)&(long)(1));
				if (u.n[c]==null)
				{
					c^=1;
					get^=((long)(1))<<j;
				}
				u=u.n[c];
			}
			ans=Math.max(get,ans);
		}
		System.out.println(ans);
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

	public long readLong() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		int sgn = 1;
		if (c == '-') {
			sgn = -1;
			c = read();
		}
		long res = 0;
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

import java.awt.Point;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;

public class Main {

	public static class Scanner {

		private InputStream in;

		public Scanner(InputStream in) {
			this.in = in;
		}

		public int nextInt() {
			try {
				int c = in.read(), flag, x;
				while (!Character.isDigit(c) && c != '-')
					c = in.read();
				if (c == '-') {
					flag = -1;
					x = 0;
				} else {
					flag = 1;
					x = c - '0';
				}
				c = in.read();
				while (Character.isDigit(c)) {
					x = x * 10 + c - '0';
					c = in.read();
				}
				return flag * x;
			} catch (IOException e) {
				return 0;
			}
		}
	}

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		int n = in.nextInt(), m = in.nextInt(), k = in.nextInt();
		int[] a = new int[k];
		for (int i = 0; i < k; i++)
			a[i] = in.nextInt();
		if (k == n || m > (n - 3) * (n - 2) / 2 + (n - 1))
			out.println(-1);
		else {
			int core = 0;
			for (int i = 1; i <= n; i++) {
				boolean found = false;
				for (int j = 0; j < k; j++)
					if (a[j] == i)
						found = true;
				if (!found)
					core = i;
			}
			int left = 0, right = 0;
			for (int i = n; i >= 1; i--)
				if (i != core)
					left = i;
			for (int i = 1; i <= n; i++)
				if (i != core)
					right = i;
			int cnt = 0;
			for (int i = 1; i <= n && cnt < m - 1; i++)
				for (int j = i + 1; j <= n && cnt < m - 1; j++)
					if (i != left && j != left) {
						out.println(i + " " + j);
						cnt++;
					}
			out.println(left + " " + core);
		}
		out.close();
	}
}
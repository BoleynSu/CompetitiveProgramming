import java.io.BufferedInputStream;
import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(new BufferedInputStream(System.in));
		long[] f = new long[256];
		for (int i = '0'; i <= '9'; i++)
			f[i] = i - '0';
		for (int i = 'A'; i <= 'Z'; i++)
			f[i] = i - 'A' + 10;
		for (int i = 'a'; i <= 'z'; i++)
			f[i] = i - 'a' + 36;
		String s;
		long y;
		while (in.hasNext()) {
			s = in.next();
			y = in.nextLong();
			long x = 0;
			for (int i = 0; i < s.length(); i++)
				x = x * y + f[s.charAt(i)];
			long t = y;
			BigInteger ans = null;
			for (long i = 2; i <= t; i++)
				if (t % i == 0) {
					while (t % i == 0)
						t /= i;
					long p = 0;
					long b = i;
					while (y % b == 0) {
						p++;
						b *= i;
					}
					BigInteger get = BigInteger.ZERO;
					long a = x;
					while (a != 0) {
						get = get.add(BigInteger.valueOf(a / i));
						a /= i;
					}
					get = get.divide(BigInteger.valueOf(p));
					if (ans == null || ans.compareTo(get) > 0)
						ans = get;
				}
			System.out.println(ans);
		}
	}
}
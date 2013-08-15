import java.io.BufferedInputStream;
import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(new BufferedInputStream(System.in));
		int T = in.nextInt();
		for (int t = 0; t < T; t++) {
			BigInteger n = in.nextBigInteger();
			int k = in.nextInt();
			BigInteger ans = BigInteger.ZERO;
			// n/2^x<i<=n/2^(x-1)
			BigInteger beg = n.shiftRight(k - 1), end = n;
			int x = 0;
			while (beg.compareTo(end) != 0) {
				int delta = (end.testBit(0) ? 1 : 0) - (beg.testBit(0) ? 1 : 0);
				ans = ans.add(BigInteger.valueOf(x).multiply(
						end.shiftRight(1).subtract(beg.shiftRight(1))
								.add(BigInteger.valueOf(delta))));
				end = beg;
				beg = beg.shiftRight(k);
				x++;
			}
			System.out.println(ans);
		}
	}
}
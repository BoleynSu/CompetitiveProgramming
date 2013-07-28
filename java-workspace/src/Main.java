import java.io.BufferedInputStream;
import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner cin = new Scanner(new BufferedInputStream(System.in));
		while (cin.hasNextLong()) {
			long n = cin.nextLong();
			long ansr = n, ansk = 1;
			for (long k = 1, cur = 3; cur <= n; k++, cur = cur * 2 + 1) {
				long l = 1, r = n;
				while (l + 1 != r) {
					long mid = (l + r) / 2;
					long x = 1, y = 0;
					for (int i = 0; i <= k; i++) {
						y += x;
						if (i != k
								&& BigInteger
										.valueOf(y)
										.add(BigInteger.valueOf(x).multiply(
												BigInteger.valueOf(mid)))
										.compareTo(BigInteger.valueOf(n)) > 0) {
							y = n + 1;
							break;
						}
						x *= mid;
					}
					if (y < n)
						l = mid;
					else
						r = mid;
				}
				long x = 1, y = 0;
				for (int i = 0; i <= k; i++) {
					y += x;
					x *= r;
				}
				if (y == n) {
					if (ansr * ansk > r * k) {
						ansr = r;
						ansk = k;
					}
					if (ansr * ansk == r * k && ansr > r) {
						ansr = r;
						ansk = k;
					}
				}
			}
			n++;
			for (long k = 1, cur = 3; cur <= n; k++, cur = cur * 2 + 1) {
				long l = 1, r = n;
				while (l + 1 != r) {
					long mid = (l + r) / 2;
					long x = 1, y = 0;
					for (int i = 0; i <= k; i++) {
						y += x;
						if (i != k
								&& BigInteger
										.valueOf(y)
										.add(BigInteger.valueOf(x).multiply(
												BigInteger.valueOf(mid)))
										.compareTo(BigInteger.valueOf(n)) > 0) {
							y = n + 1;
							break;
						}
						x *= mid;
					}
					if (y < n)
						l = mid;
					else
						r = mid;
				}
				long x = 1, y = 0;
				for (int i = 0; i <= k; i++) {
					y += x;
					x *= r;
				}
				if (y == n) {
					if (ansr * ansk > r * k) {
						ansr = r;
						ansk = k;
					}
					if (ansr * ansk == r * k && ansr > r) {
						ansr = r;
						ansk = k;
					}
				}
			}
			System.out.println(ansr + " " + ansk);
		}
	}
}
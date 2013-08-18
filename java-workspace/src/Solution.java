import java.math.BigInteger;
import java.util.Scanner;

public class Solution {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		BigInteger[] fac = new BigInteger[n + 1], pow = new BigInteger[n + 1];
		fac[0] = pow[0] = BigInteger.ONE;
		for (int i = 1; i <= n; i++) {
			fac[i] = fac[i - 1].multiply(BigInteger.valueOf(i));
			pow[i] = pow[i - 1].multiply(BigInteger.valueOf(n));
		}
		BigInteger ans = BigInteger.ZERO;
		BigInteger t = fac[n - 1];
		for (int k = n; k >= 3; k--) {
			ans = ans.add(t);
			t = t.divide(BigInteger.valueOf(n - (k - 1))).multiply(
					BigInteger.valueOf(n));
		}
		ans = ans.divide(BigInteger.valueOf(2));
		System.out.println(ans);
	}
}
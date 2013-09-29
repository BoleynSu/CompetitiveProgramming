import java.io.BufferedInputStream;
import java.math.BigInteger;
import java.util.Formatter.BigDecimalLayoutForm;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(new BufferedInputStream(System.in));
		int TC = in.nextInt();
		for (int tc = 1; tc <= TC; tc++) {
			System.out.print("Case " + tc + ": ");
			int n = in.nextInt();
			BigInteger a = in.nextBigInteger().subtract(BigInteger.ONE);
			BigInteger x = in.nextBigInteger().subtract(BigInteger.ONE);
			BigInteger b = in.nextBigInteger().subtract(BigInteger.ONE);
			BigInteger y = in.nextBigInteger().subtract(BigInteger.ONE);
			BigInteger s = a.xor(b), t = x.xor(y);
			char[] S = new char[n * 2], T = new char[n];
			for (int i = 0; i < n; i++) {
				S[i] = S[i + n] = s.testBit(i) ? '1' : '0';
				T[i] = t.testBit(i) ? '1' : '0';
			}
			boolean ans = false;
			int[] pi = new int[n];
			pi[0] = -1;
			for (int i = 1, j = -1; i < n; i++) {
				while (j != -1 && T[j + 1] != T[i])
					j = pi[j];
				if (T[j + 1] == T[i])
					j++;
				pi[i] = (j != -1 && i + 1 < n && T[j + 1] == T[i + 1]) ? pi[j]
						: j;
			}
			for (int i = 0, j = -1; i < n * 2; i++) {
				while (j != -1 && T[j + 1] != S[i])
					j = pi[j];
				if (T[j + 1] == S[i])
					j++;
				if (j == n - 1) {
					ans = true;
					j = pi[j];
				}
			}
			System.out.println(ans ? "Yes" : "No");
		}
	}
}
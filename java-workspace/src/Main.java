import java.math.BigInteger;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for (int i = 0; i < T; i++) {
			BigInteger sum = BigInteger.ZERO;
			for (int j = 0; j < 12; j++) {
				String[] s = in.next().split("\\.");
				sum = sum.add(BigInteger.valueOf(Integer.parseInt(s[0]) * 100
						+ Integer.parseInt(s[1])));
			}
			sum = sum.add(BigInteger.valueOf(6));
			sum = sum.divide(BigInteger.valueOf(12));
			BigInteger h = sum.divide(BigInteger.valueOf(100));
			BigInteger l = sum.mod(BigInteger.valueOf(100));
			if (l.signum() != 0)
				while (l.mod(BigInteger.valueOf(10)).signum() == 0)
					l = l.divide(BigInteger.valueOf(10));
			System.out.println("$" + h + (l.signum() == 0 ? "" : "." + l));
		}
	}
}
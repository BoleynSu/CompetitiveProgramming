import java.io.BufferedInputStream;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(new BufferedInputStream(System.in));
		for (int i = 1;; i++) {
			int L = in.nextInt(), P = in.nextInt(), V = in.nextInt();
			if (L == 0 && P == 0 && V == 0)
				break;
			int ans = V / P * L + Math.min(V % P, L);
			System.out.println("Case " + i + ": " + ans);
		}
	}
}
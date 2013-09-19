import java.util.Arrays;

public class TheTree {
	public int maximumDiameter(int[] cnt) {
		int ans = 0;
		for (int root = 0; root < cnt.length; root++) {
			int[] cpy = Arrays.copyOf(cnt, cnt.length);
			int get = 0;
			for (int dep = 0; root + dep < cpy.length; dep++) {
				if (cpy[root + dep] == 0)
					break;
				cpy[root + dep]--;
				get++;
			}
			for (int dep = 0; root + dep < cpy.length; dep++) {
				if (cpy[root + dep] == 0)
					break;
				cpy[root + dep]--;
				get++;
			}
			ans = Math.max(ans, get);
		}
		return ans;
	}

	public static void main(String[] args) {
		System.out.print(new TheTree().maximumDiameter(new int[] { 1, 1, 1, 1,
				1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
				1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
				1, 1, 1 }));
	}
}

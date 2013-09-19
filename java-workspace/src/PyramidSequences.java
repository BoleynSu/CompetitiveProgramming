public class PyramidSequences {
	private long gcd(long a, long b) {
		return a == 0 ? b : gcd(b % a, a);
	}

	public long distinctPairs(int N, int M) {
		long ans = 0;
		// i -> k(2n-2)+i
		// i -> k(2n-2)+2-i
		// j -> l(2m-2)+j
		// j -> l(2m-2)+2-j
		long G = gcd(2 * N - 2, 2 * M - 2);
		//G | i*2-2 ans+=(2*M-2)/G
		//otherwise ans+=2*(2*M-2)/G
		ans=(long)N*2*(2*M-2)/G;
		ans-=(long)(2*N-2)/G*(2*M-2)/G;
		return ans;
	}
}

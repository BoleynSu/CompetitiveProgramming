import java.util.*;
import java.io.*;

public class Solution
{
	public static void main(String arg[])
	{
		new Solution();
	}
	public Solution()
	{
		new TaskI();
	}
}

class TaskI
{
	int get(int N,int q)
	{
		if (N==1) return q;
		int K=N/2;
		if (q<=K) return N-K+get(K,K-q+1);
		else return get(N-K,N-q+1);
	}
	public TaskI()
	{
		Scanner cin=new Scanner(new BufferedInputStream(System.in));
		int N=cin.nextInt(),q=cin.nextInt();
		System.out.println(get(N,q));
		cin.close();
	}
}

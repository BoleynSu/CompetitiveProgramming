import java.util.*;
import java.io.*;

public class Main {
	public static void main(String arg[])
	{
		new Main();
	}
	LinkedList<Integer> adj[];
	ArrayList<Integer> natd[];
	int io[],oo[],dp[];
	int t;
	void dfs(int u,int d)
	{
		io[u]=t;
		natd[d].add(t);
		dp[u]=d;
		t++;
		for (Integer v: adj[u])
			dfs(v,d+1);
		oo[u]=t;
	}
	public Main()
	{
		Scanner cin=new Scanner(new BufferedInputStream(System.in));
		String s=cin.nextLine();
		ArrayList<String> a=new ArrayList<String>();
		while (cin.hasNextLine())
			a.add(cin.nextLine());
		for (int i=0;i<s.length();i++)
		{
			if (s.charAt(i)=='{')
			{
				int j=i+1;
				while (j<s.length()&&s.charAt(j)!='}') j++;
				boolean is=true;
				if (j>=s.length()) is=false;
				for (int k=i+1;k<j;k++)
					if (s.charAt(k)<'0'||'9'<s.charAt(k))
						is=false;
				int x=0;
				for (int k=i+1;k<j;k++)
				{
					x=x*10+(s.charAt(k)-'0');
					if (x>a.size()) is=false;
				}
				if (x==0) is=false;
				if (is)
				{
					System.out.print(a.get(x-1));
					i=j;
				}
				else System.out.print(s.charAt(i));
			}
			else if (s.charAt(i)=='\\') System.out.print(s.charAt(++i));
			else System.out.print(s.charAt(i));
		}
		System.out.println();
		cin.close();
	}
}
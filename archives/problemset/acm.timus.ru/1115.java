/*
PROGRAM: $PROGRAM
AUTHOR: Su Jiao
DATE: 2011-11-18
DESCRIPTION:
$DESCRIPTION
*/

import java.io.*;
import java.util.*;
import java.util.Comparator;
import java.math.*;

public class Ural {
	public static void main(String args[])
	{
		new Ural();
	}
	private int n,m,ships[],rows[],used[];
	private boolean found;
	private void dfs(int rowid,int starter)
	{
		if (!found)
		{
			if (rowid==m)
			{
				found=true;
				for (int i=0;i<m;i++)
				{
					int count=0;
					for (int j=0;j<n;j++)
						if (used[j]==i)
							count++;
					System.out.println(count);
					for (int j=0;j<n;j++)
						if (used[j]==i)
						{
							count--;
							System.out.printf("%d%c",ships[j],count==0?'\n':' ');
						}
				}
			}
			else if (rows[rowid]==0) dfs(rowid+1,0);
			else
			{
				for (int i=starter;i<n;i++)
					if (used[i]==-1&&rows[rowid]>=ships[i])
					{
						rows[rowid]-=ships[i];
						used[i]=rowid;
						dfs(rowid,i);
						used[i]=-1;
						rows[rowid]+=ships[i];
					}
			}
		}
	}
	public Ural()
	{
		Scanner cin=new Scanner(new BufferedInputStream(System.in));
		n=cin.nextInt();
		m=cin.nextInt();
		ships=new int[n];
		rows=new int[m];
		for (int i=0;i<n;i++) ships[i]=-cin.nextInt();
		Arrays.sort(ships);
		for (int i=0;i<n;i++) ships[i]=-ships[i];
		for (int i=0;i<m;i++) rows[i]=cin.nextInt();
		found=false;
		used=new int[n];
		Arrays.fill(used,-1);
		dfs(0,0);
	}
}
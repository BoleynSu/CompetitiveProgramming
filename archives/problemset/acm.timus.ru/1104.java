/*
PROGRAM: $PROGRAM
AUTHOR: Su Jiao
DATE: 2011-11-18
DESCRIPTION:
$DESCRIPTION
*/

import java.io.*;
import java.util.*;

public class Ural {
	public static void main(String args[])
	{
		new Ural();
	}
	public int c2i(char c)
	{
		if ('A'<=c&&c<='Z') return (int)(c-'A')+10;
		else return (int)(c-'0');
	}
	public Ural()
	{
		Scanner cin=new Scanner(new BufferedInputStream(System.in));
		String s=cin.nextLine();
		int sum=0;
		int mink=2;
		for (int i=0;i<s.length();i++)
		{
			sum+=c2i(s.charAt(i));
			if (c2i(s.charAt(i))>=mink) mink=c2i(s.charAt(i))+1;
		}
		for (int k=mink;k<=36;k++)
		{
			if (sum%(k-1)==0)
			{
				System.out.println(k);
				return;
			}
		}
		System.out.println("No solution.");
	}
}
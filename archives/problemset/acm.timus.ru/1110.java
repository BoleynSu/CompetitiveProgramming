/*
PROGRAM: $PROGRAM
AUTHOR: Su Jiao
DATE: 2011-11-18
DESCRIPTION:
$DESCRIPTION
*/

import java.io.*;
import java.util.*;
import java.math.*;

public class Ural {
	public static void main(String args[])
	{
		new Ural();
	}
	private int n,m,y;
	private int pow(int x,int y)
	{
		int z=1;
		for (int i=1;i<=y;i<<=1)
		{
			if ((y&i)!=0) z=(z*x)%m;
			x=(x*x)%m;
		}
		return z;
	}
	public Ural()
	{
		Scanner cin=new Scanner(new BufferedInputStream(System.in));
		n=cin.nextInt();
		m=cin.nextInt();
		y=cin.nextInt();
		int answers=0;
		int answer[]=new int[m];
		for (int i=0;i<m;i++)
			if (pow(i,n)==y) answer[answers++]=i;
		for (int i=0;i<answers;i++)
			System.out.printf("%d%c",answer[i],i+1==answers?'\n':' ');
		if (answers==0) System.out.println(-1);
	}
}
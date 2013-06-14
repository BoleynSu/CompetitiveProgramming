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
	public Ural()
	{
		Scanner cin=new Scanner(new BufferedInputStream(System.in));
		int n=cin.nextInt();
		int a[]=new int[n],b[]=new int[n];
		for (int i=0;i<n;i++)
		{
			a[i]=cin.nextInt();
			b[i]=cin.nextInt();
			if (a[i]>b[i])
			{
				int swap=a[i];
				a[i]=b[i];
				b[i]=swap;
			}
		}
		int answer=0;
		int aa[]=new int[n],ab[]=new int[n];
		while (n>0)
		{
			aa[answer]=a[0];
			ab[answer]=b[0];
			for (int i=1;i<n;i++)
				if (b[i]<ab[answer])
				{
					aa[answer]=a[i];
					ab[answer]=b[i];
				}
			for (int i=0;i<n;i++)
				if (a[i]<ab[answer])
				{
					n--;
					a[i]=a[n];
					b[i]=b[n];
					i--;
				}
			answer++;
		}
		System.out.println(answer);
		for (int i=0;i<answer;i++)
			System.out.println(aa[i]+" "+ab[i]);
	}
}

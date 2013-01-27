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
	private class F{public int A,B,Y;}
	public Ural()
	{
		Scanner cin=new Scanner(new BufferedInputStream(System.in));
		int n[]=new int[2];
		F f[][]=new F[2][];
		for (int i=0;i<2;i++)
		{
			n[i]=cin.nextInt();
			f[i]=new F[n[i]];
			for (int j=0;j<n[i];j++)
			{
				f[i][j]=new F();
				f[i][j].A=cin.nextInt();
				f[i][j].B=cin.nextInt();
				f[i][j].Y=cin.nextInt();
			}
		}
		int answers=0;
		F answer[]=new F[n[0]+n[1]];
		for (int i[]=new int[]{0,0};i[0]<n[0];)
		{
			if (i[1]==n[1]||f[0][i[0]].B<=f[1][i[1]].A)
			{
				answer[answers]=new F();
				answer[answers].A=f[0][i[0]].A;
				answer[answers].B=f[0][i[0]].B;
				answer[answers].Y=f[0][i[0]].Y;
				answers++;
				i[0]++;
			}
			else if (f[0][i[0]].A>=f[1][i[1]].B) i[1]++;
			else if (f[1][i[1]].A<=f[0][i[0]].A&&f[0][i[0]].B<=f[1][i[1]].B) i[0]++;
			else if (f[0][i[0]].A<f[1][i[1]].A&&f[0][i[0]].B<=f[1][i[1]].B)
			{
				answer[answers]=new F();
				answer[answers].A=f[0][i[0]].A;
				answer[answers].B=f[1][i[1]].A;
				answer[answers].Y=f[0][i[0]].Y;
				answers++;
				i[0]++;
			}
			else if (f[0][i[0]].A<f[1][i[1]].A&&f[1][i[1]].B<f[0][i[0]].B)
			{
				answer[answers]=new F();
				answer[answers].A=f[0][i[0]].A;
				answer[answers].B=f[1][i[1]].A;
				answer[answers].Y=f[0][i[0]].Y;
				answers++;
				f[0][i[0]].A=f[1][i[1]].B;
				i[1]++;
			}
			else if (f[1][i[1]].A<=f[0][i[0]].A&&f[1][i[1]].B<f[0][i[0]].B)
			{
				f[0][i[0]].A=f[1][i[1]].B;
				i[1]++;
			}
		}
		System.out.print(answers);
		for (int i=0;i<answers;i++)
			System.out.printf(" %d %d %d",answer[i].A,answer[i].B,answer[i].Y);
		System.out.println();
	}
}
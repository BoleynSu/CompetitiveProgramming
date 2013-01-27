import java.io.*;
import java.util.*;

public class Ural {
	public static void main(String args[])
	{
		new Ural();
	}
	public String exp;
	public int N,M,K;
	public int mx[],my[],kx[],ky[],iv[];
	public boolean vars[];
	public final int DIRS=4;
	public int dir,x,y;
	public int dx[],dy[];
	public int getid(char ch)
	{
		return (int)(ch-'A');
	}
	public boolean calc()
	{
		Stack<Boolean> va=new Stack<Boolean>();
		Stack<Character> op=new Stack<Character>();
		for (int i=0;i<exp.length();i++)
		{
			boolean opn1,opn2;
			switch (exp.charAt(i))
			{
				case '!':
					op.push('!');
					break;
				case '&':
					while (!op.empty())
					{
						if (op.peek()=='!')
						{
							opn1=va.pop();
							va.push(!opn1);
						}
						else if (op.peek()=='&')
						{
							opn1=va.pop();
							opn2=va.pop();
							va.push(opn1&&opn2);
						}
						else break;
						op.pop();
					}
					op.push('&');
					break;
				case '|':
					while (!op.empty())
					{
						if (op.peek()=='!')
						{
							opn1=va.pop();
							va.push(!opn1);
						}
						else if (op.peek()=='&')
						{
							opn1=va.pop();
							opn2=va.pop();
							va.push(opn1&&opn2);
						}
						else if (op.peek()=='|')
						{
							opn1=va.pop();
							opn2=va.pop();
							va.push(opn1||opn2);
						}
						else break;
						op.pop();
					}
					op.push('|');
					break;
				case '(':
					op.push('(');
					break;
				case ')':
					while (op.peek()!='(')
					{
						if (op.peek()=='!')
						{
							opn1=va.pop();
							va.push(!opn1);
						}
						else if (op.peek()=='&')
						{
							opn1=va.pop();
							opn2=va.pop();
							va.push(opn1&&opn2);
						}
						else if (op.peek()=='|')
						{
							opn1=va.pop();
							opn2=va.pop();
							va.push(opn1||opn2);
						}
						else break;
						op.pop();
					}
					op.pop();
					break;
				case '0':
					va.push(false);
					break;
				case '1':
					va.push(true);
					break;
				default:
					va.push(vars[getid(exp.charAt(i))]);
					break;
			}
		}
		return va.pop();
	}
	public Ural()
	{
		Scanner cin=new Scanner(new BufferedInputStream(System.in));
		exp=cin.nextLine();
		N=cin.nextInt();
		M=cin.nextInt();
		K=cin.nextInt();
		mx=new int[M];
		my=new int[M];
		kx=new int[K];
		ky=new int[K];
		iv=new int[K];
		for (int i=0;i<M;i++)
		{
			mx[i]=cin.nextInt();
			my[i]=cin.nextInt();
		}
		for (int i=0;i<K;i++)
		{
			kx[i]=cin.nextInt();
			ky[i]=cin.nextInt();
			iv[i]=getid(cin.next().charAt(0));
		}
		exp=exp.replaceAll("NOT","!");
		exp=exp.replaceAll("AND","&");
		exp=exp.replaceAll("OR","|");
		exp=exp.replaceAll("TRUE","1");
		exp=exp.replaceAll("FALSE","0");
		exp=exp.replaceAll(" ","");
		exp="("+exp+")";
		vars=new boolean[26];
		Arrays.fill(vars,false);
		dir=0;
		x=0;
		y=0;
		dx=new int[]{1,0,-1,0};
		dy=new int[]{0,1,0,-1};
		while (Math.abs(x)<=N&&Math.abs(y)<=N)
		{
			System.out.println(x+" "+y);
			for (int i=0;i<M;i++)
				if (mx[i]==x&&my[i]==y)
				{
					if (calc())
					{
						if (dir==0) dir+=DIRS;
						dir--;
					}
					else
					{
						dir++;
						if (dir==DIRS) dir-=DIRS;
					}
				}
			for (int i=0;i<K;i++)
				if (kx[i]==x&&ky[i]==y)
					vars[iv[i]]=!vars[iv[i]];
			x+=dx[dir];
			y+=dy[dir];
		}
	}
}
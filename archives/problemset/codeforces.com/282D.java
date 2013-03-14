import java.io.BufferedInputStream;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] arg)
	{
		new Main();
	}
	Main()
	{
		Scanner cin=new Scanner(new BufferedInputStream(System.in));
		int n=cin.nextInt();
		int a0=n>0?cin.nextInt():0,a1=n>1?cin.nextInt():0,a2=n>2?cin.nextInt():0;
		boolean[][][] f=new boolean[a0+1][a1+1][a2+1];
		for (int i=0;i<=a0;i++)
			for (int j=0;j<=a1;j++)
				for (int k=0;k<=a2;k++)
					f[i][j][k]=false;
		
		for (int i=0;i<=a0;i++)
			for (int j=0;j<=a1;j++)
				for (int k=0;k<=a2;k++)
					if (!f[i][j][k])
					{
						if (n==1)
						{
							int end=a0-i;
							for (int l=1;l<=end;l++) f[i+l][j][k]=true;
						}
						else if (n==2)
						{
							int end=Math.min(a0-i,a1-j);
							for (int l=1;l<=end;l++) f[i+l][j+l][k]=true;
							end=a0-i;
							for (int l=1;l<=end;l++) f[i+l][j][k]=true;
							end=a1-j;
							for (int l=1;l<=end;l++) f[i][j+l][k]=true;
						}
						else if (n==3)
						{
							int end=Math.min(Math.min(a0-i,a1-j),a2-k);
							for (int l=1;l<=end;l++) f[i+l][j+l][k+l]=true;	
							end=a0-i;
							for (int l=1;l<=end;l++) f[i+l][j][k]=true;
							end=a1-j;
							for (int l=1;l<=end;l++) f[i][j+l][k]=true;
							end=a2-k;
							for (int l=1;l<=end;l++) f[i][j][k+l]=true;
						}
					}
		System.out.println(f[a0][a1][a2]?"BitLGM":"BitAryo");
		cin.close();
	}
}

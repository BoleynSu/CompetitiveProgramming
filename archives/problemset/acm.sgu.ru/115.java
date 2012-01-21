import java.util.*;
import java.io.*;

public class Solution {
	public static void main(String arg[])
	{
		new Solution();
	}
	Solution()
	{
		Scanner cin=new Scanner(new BufferedInputStream(System.in));
		int M=cin.nextInt(),N=cin.nextInt();
		if (!(1<=N&&N<=12)||((N==2)&&!(1<=M&&M<=28))||((N==1||N==3||N==5||N==7||N==8||N==10||N==12)&&!(1<=M&&M<=31))||((N==4||N==6||N==9||N==11)&&!(1<=M&&M<=30))) System.out.println("Impossible");
		else
		{
			if (N>1) M+=31;
			if (N>2) M+=28;
			if (N>3) M+=31;
			if (N>4) M+=30;
			if (N>5) M+=31;
			if (N>6) M+=30;
			if (N>7) M+=31;
			if (N>8) M+=31;
			if (N>9) M+=30;
			if (N>10) M+=31;
			if (N>11) M+=30;
			if (N>12) M+=31;
			System.out.println((M+6)%7+1);
		}
	}
}

import java.util.*;

public class Main {
	public static void main(String arg[])
	{
		new Main();
	}
	Main()
	{
		String s;
		Scanner cin=new Scanner(System.in);
		s=cin.next();
		s=s.replaceAll("WUB"," ");
		s=s.replaceAll("  "," ");
		s=s.replaceAll("  "," ");
		s=s.replaceAll("  "," ");
		s=s.replaceAll("  "," ");
		s=s.replaceAll("  "," ");
		s=s.replaceAll("  "," ");
		s=s.replaceAll("  "," ");
		s=s.replaceAll("  "," ");
		s=s.replaceAll("  "," ");
		s=s.replaceAll("  "," ");
		s=s.replaceAll("  "," ");
		s=s.replaceAll("  "," ");
		s=s.replaceAll("  "," ");
		s=s.replaceAll("  "," ");
		s=s.replaceAll("  "," ");
		s=s.replaceAll("  "," ");
		if (s.charAt(0)==' ') s=s.substring(1,s.length());
		if (s.charAt(s.length()-1)==' ') s=s.substring(0,s.length()-1);
		System.out.println(s);
	}
}


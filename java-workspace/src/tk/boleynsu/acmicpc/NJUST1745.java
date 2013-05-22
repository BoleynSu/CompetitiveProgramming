package tk.boleynsu.acmicpc;

import java.io.BufferedInputStream;
import java.util.Map;
import java.util.Scanner;
import java.util.TreeMap;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

class BigInteger
{
	String s;
	BigInteger(String s)
	{
		this.s=s;
	}
	public String toString()
	{
		return s;
	}
}

public class NJUST1745
{
	public static void main(String[] args)
	{
		Scanner cin=new Scanner(new BufferedInputStream(System.in));
		int T=Integer.parseInt(cin.nextLine());
		for (int t=0;t<T;t++)
		{
			int n=Integer.parseInt(cin.nextLine());
			boolean errorReportOn=true;
			Map<String,Object> var=new TreeMap<String,Object>();
			boolean killed=false;
			for (int i=0;i<n;i++)
			{
				String line=cin.nextLine();
				if (!killed)
				{
					String stmt=line.replaceAll("[ \t]+"," ").trim();
					if (stmt.indexOf('=')!=-1)
					{
						String[] part=stmt.split("[ ]*=[ ]*");
						String varName=part[0];
						Object value=null;
						Pattern pattern=Pattern.compile("\".*\"");
						Matcher matcher=pattern.matcher(line);
						if (matcher.find())
						{
							value=matcher.group();
							value=((String)value).substring(1,((String)value).length()-1);
						}
						else value=new BigInteger(part[1]);
						if (var.get(varName)!=null&&!varName.startsWith("$"))
						{
							if (errorReportOn) System.out.println("WARNING: Constant "+varName+" Already Defined!");
						}
						else var.put(varName,value);
					}
					else if (stmt.startsWith("Print"))
					{
						String varName=stmt.substring("Print".length()+1);
						Object value=var.get(varName);
						if (value instanceof BigInteger)
						{
							System.out.println(value);
						}
						else if (value instanceof String)
						{
							System.out.println(value);
						}
						else
						{
							if (varName.startsWith("$"))
							{
								System.out.println("NULL");
								if (errorReportOn) System.out.println("NOTICE: Undefined Variable "+varName+".");
							}
							else
							{
								System.out.println(varName);
								if (errorReportOn) System.out.println("NOTICE: Undefined Constant "+varName+".");
							}
						}
					}
					else if (stmt.startsWith("Dump"))
					{
						String varName=stmt.substring("Dump".length()+1);
						Object value=var.get(varName);
						if (value instanceof BigInteger)
							System.out.print("integer: ");
						else if (value  instanceof String||!varName.startsWith("$"))
							System.out.print("string: ");
						if (value instanceof BigInteger)
						{
							System.out.println(value);
						}
						else if (value instanceof String)
						{
							System.out.println("\""+value+"\"");
						}
						else
						{
							if (varName.startsWith("$"))
							{
								System.out.println("NULL");
								if (errorReportOn) System.out.println("NOTICE: Undefined Variable "+varName+".");
							}
							else
							{
								System.out.println("\""+varName+"\"");
								if (errorReportOn) System.out.println("NOTICE: Undefined Constant "+varName+".");
							}
						}
					}
					else if (stmt.equals("Errmsg ON")) errorReportOn=true;
					else if (stmt.equals("Errmsg OFF")) errorReportOn=false;
					else if (stmt.equals("Panic"))
					{
						killed=true;
						System.out.println("Script was KILLED.");
					}
					else ;//a blank line
				}
			}
			if (t+1!=T) System.out.println();
		}
	}
}
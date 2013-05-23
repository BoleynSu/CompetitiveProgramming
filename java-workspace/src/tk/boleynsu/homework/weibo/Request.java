package tk.boleynsu.homework.weibo;

import java.io.InputStream;
import java.io.OutputStream;
import java.sql.PreparedStatement;
import java.util.Scanner;

public class Request implements Runnable
{
	private InputStream in;
	private OutputStream out;
	public Request(InputStream in,OutputStream out)
	{
		this.in=in;
		this.out=out;
	}
	public void run()
	{
		try
		{
			System.out.println("running!");
			Scanner scanner=new Scanner(in);
			while (scanner.hasNextLine())
			{
				int user=Integer.parseInt(scanner.nextLine());
				String text=scanner.nextLine();
				String image=scanner.nextLine();
				PreparedStatement ps=SQL.prepareStatement("insert into microblog values(?,?,?);");
				ps.setInt(1,user);
				ps.setString(2,text);
				ps.setString(3,image);
				ps.execute();
				System.out.println("inserted!");
			}
			in.close();
			out.close();
		}
		catch (Exception e)
		{
			e.printStackTrace();
		}
	}
	public static void main(String[] args)
	{
		Request request=new Request(System.in,System.out);
		request.run();
	}
}

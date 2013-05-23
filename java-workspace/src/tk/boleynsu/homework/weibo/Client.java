package tk.boleynsu.homework.weibo;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.net.Socket;
import java.net.UnknownHostException;
import java.util.Scanner;

public class Client
{
	public static void main(String[] args) throws UnknownHostException, IOException, InterruptedException
	{
		LoginDialogBackup loginDialog=new LoginDialogBackup();
		/*
		Socket socket=new Socket(Config.getServerHost(),Config.getServerPort());
		InputStream in=socket.getInputStream();
		OutputStream out=socket.getOutputStream();
		Scanner cin=new Scanner(System.in);
		PrintWriter cout=new PrintWriter(out);
		while (cin.hasNextLine())
		{
			String command=cin.nextLine();
			cout.println(command);
			cout.flush();
		}
		socket.close();
		*/
	}
}

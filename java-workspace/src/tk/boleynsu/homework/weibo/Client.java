package tk.boleynsu.homework.weibo;

import java.io.IOException;
import java.net.UnknownHostException;

import javax.swing.UIManager;
import javax.swing.UnsupportedLookAndFeelException;

public class Client
{
	public static void main(String[] args) throws UnknownHostException, IOException, InterruptedException, ClassNotFoundException, InstantiationException, IllegalAccessException, UnsupportedLookAndFeelException
	{
		UIManager.setLookAndFeel(UIManager.getSystemLookAndFeelClassName());
		LoginDialog loginDialog=new LoginDialog();
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

package tk.boleynsu.homework.weibo;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class Server
{
	public static void main(String[] args) throws IOException
	{
		ServerSocket serverSocket=new ServerSocket(Config.getServerPort());
		for (;;)
		{
			Socket socket=serverSocket.accept();
			Thread thread=new Thread(new Request(socket.getInputStream(),socket.getOutputStream()));
			thread.start();
		}
	}
}

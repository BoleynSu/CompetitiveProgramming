package tk.boleynsu.homework;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.nio.ByteBuffer;

/*
协议:
1. receive query type
	query type format:
	1 byte 0 for download 1 for upload
	4 byte =x for file path length
	x byte for file path
3. if download then send file content
   if upload then receive file content
	file content format:
	8 byte =y for file content length
	y byte for file content
*/

public class Server
{
	public static void main(String[] args) throws IOException
	{
		ServerSocket serverSocket=new ServerSocket(1993);
		for (;;)
		{
			Socket socket=serverSocket.accept();
			Thread thread=new Thread(new Runnable() {
				private InputStream in;
				private OutputStream out;
				private byte[] integerToByte(int x)
				{
					ByteBuffer bb = ByteBuffer.allocate(4);
					bb.putInt(x);
					return bb.array();
				}
				private int byteToInteger(byte[] x)
				{
					ByteBuffer bb = ByteBuffer.allocate(x.length);
					bb.put(x);
					bb.position(0);
					return bb.getInt();
				}
				private byte[] longToByte(long x)
				{
					ByteBuffer bb = ByteBuffer.allocate(8);
					bb.putLong(x);
					return bb.array();
				}
				private long byteToLong(byte[] x)
				{
					ByteBuffer bb = ByteBuffer.allocate(x.length);
					bb.put(x);
					bb.position(0);
					return bb.getLong();
				}
				public void run() {
					try {
						int queryType = in.read();
						byte[] plb = new byte[4];
						in.read(plb);
						int pl = byteToInteger(plb);
						byte[] p = new byte[pl];
						in.read(p);
						String path = new String(p,"utf-8");
						System.out.println((queryType==0?"download":"upload")+" "+path);

						InputStream fileReader = null;
						OutputStream fileWriter = null;
						long total = 0;
						if (queryType==0)
						{
							File file = new File(path);
							total = file.length();
							out.write(longToByte(total));
							fileReader = new FileInputStream(file);
							fileWriter = out;
						}
						else if (queryType==1)
						{
							byte[] tb = new byte[8];
							in.read(tb);
							total = byteToLong(tb);
							fileReader = in;
							fileWriter = new FileOutputStream(path);
						}
						System.out.println("file size "+total);

						byte[] buffer=new byte[1024];
						int length;
						while ((length=fileReader.read(buffer))!=-1)
						{
							if (length==buffer.length)
								try {
									fileWriter.write(buffer);
								} catch (IOException e) {
									// TODO Auto-generated catch block
									e.printStackTrace();
								}
							else
								try {
									fileWriter.write(buffer,0,length);
								} catch (IOException e) {
									// TODO Auto-generated catch block
									e.printStackTrace();
								}
							fileWriter.flush();
							//System.out.println("copy"+current);
						}
						fileReader.close();
						fileWriter.close();
					
					} catch (IOException e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
					}
				}
				public Runnable set(InputStream in,OutputStream out) {
					this.in = in;
					this.out = out;
					return this;
				}
			}.set(socket.getInputStream(),socket.getOutputStream()));
			thread.start();
		}
	}
}

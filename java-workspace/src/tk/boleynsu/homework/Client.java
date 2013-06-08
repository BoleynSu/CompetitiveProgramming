package tk.boleynsu.homework;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.Socket;
import java.nio.ByteBuffer;
import java.util.concurrent.Semaphore;

import javax.swing.ButtonGroup;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JProgressBar;
import javax.swing.JRadioButton;
import javax.swing.JTextField;
import javax.swing.WindowConstants;

/*
协议:
1. send query type
	query type format:
	1 byte 0 for download 1 for upload
	4 byte =x for file path length
	x byte for file path
3. if download then receive file content
   if upload then send file content
	file content format:
	8 byte =y for file content length
	y byte for file content
*/

public class Client extends JFrame {
	private Semaphore semaphore;
	private JTextField source,target;
	private long total,current;
	private JProgressBar progressBar;
	private JRadioButton download;
	private JRadioButton upload;
	private final ButtonGroup buttonGroup = new ButtonGroup();
	private class CopyThread implements Runnable {
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
				Socket socket =  new Socket("localhost",1993);
				InputStream in = socket.getInputStream();
				OutputStream out = socket.getOutputStream();
				if (download.isSelected())
				{
					out.write(0);
					byte[] fileName = source.getText().getBytes("utf-8");
					out.write(integerToByte(fileName.length));
					out.write(fileName);
				}
				else if (upload.isSelected())
				{
					out.write(1);
					byte[] fileName = target.getText().getBytes("utf-8");
					out.write(integerToByte(fileName.length));
					out.write(fileName);
				}
				else throw new RuntimeException();
				
				InputStream fileReader = null;
				OutputStream fileWriter = null;
				if (download.isSelected())
				{
					byte tb[] = new byte[8];
					in.read(tb);
					total = byteToLong(tb);
					fileReader = socket.getInputStream();
					fileWriter = new FileOutputStream(target.getText());
				}
				else if (upload.isSelected())
				{
					File file = new File(source.getText());
					total = file.length();
					out.write(longToByte(total));
					fileReader = new FileInputStream(source.getText());
					fileWriter = out;
				}
				current = 0;
				semaphore.release();

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
					current+=length;
					//System.out.println("copy"+current);
				}
				fileReader.close();
				fileWriter.close();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	}
	private class BarThread implements Runnable {
		public void run() {
			try {
				semaphore.acquire();
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			progressBar.setValue(0);
			while (current!=total) {
				progressBar.setValue((int)(current*100/total));
				try {
					Thread.sleep(50);
				} catch (InterruptedException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
				//System.out.println("bar"+current);
			}
			progressBar.setValue(100);
		}
	}
	Client() {
		setTitle("文件拷贝工具");
		setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);

		getContentPane().setLayout(new FlowLayout());
		getContentPane().add(new JLabel("源："));
		source = new JTextField(10);
		getContentPane().add(source);
		getContentPane().add(new JLabel("目标："));
		target = new JTextField(10);
		getContentPane().add(target);
		getContentPane().add(new JLabel("进度："));
		progressBar = new JProgressBar();
		progressBar.setPreferredSize(new Dimension(200,20));
		progressBar.setStringPainted(true);
		getContentPane().add(progressBar);
		
		JButton start = new JButton("开始");
		semaphore = new Semaphore(0);
		start.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e) {
				Thread copyThread=new Thread(new CopyThread());
				copyThread.start();
				Thread barThread=new Thread(new BarThread());
				barThread.start();
			}
		});
		
		download = new JRadioButton("下载");
		buttonGroup.add(download);
		getContentPane().add(download);
		
		upload = new JRadioButton("上传");
		buttonGroup.add(upload);
		getContentPane().add(upload);
		getContentPane().add(start);
		setResizable(false);
		pack();
		setVisible(true);
	}
	public static void main(String[] args) {
		Client copy = new Client();
	}
}

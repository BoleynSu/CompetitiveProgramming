package tk.boleynsu.homework;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.Arrays;
import java.util.concurrent.Semaphore;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JProgressBar;
import javax.swing.JTextField;
import javax.swing.WindowConstants;


public class Copy extends JFrame {
	private Semaphore semaphore;
	private JTextField source,target;
	private long total,current;
	private JProgressBar progressBar;
	private class CopyThread implements Runnable {
		public void run() {
			byte[] buffer=new byte[1024];
			int length;
			try {
				File file = new File(source.getText());
				FileInputStream fileReader = new FileInputStream(file);
				FileOutputStream fileWriter = new FileOutputStream(target.getText());
				total = file.length();
				current = 0;
				semaphore.release();
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
							fileWriter.write(Arrays.copyOf(buffer,length));
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
	Copy() {
		setTitle("文件拷贝工具");
		setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);

		setLayout(new FlowLayout());
		add(new JLabel("源："));
		source = new JTextField(10);
		add(source);
		add(new JLabel("目标："));
		target = new JTextField(10);
		add(target);
		add(new JLabel("进度："));
		progressBar = new JProgressBar();
		progressBar.setPreferredSize(new Dimension(200,20));
		progressBar.setStringPainted(true);
		add(progressBar);
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
		add(start);
		pack();
		setVisible(true);
	}
	public static void main(String[] args) {
		Copy copy = new Copy();
	}
}

package tk.boleynsu.homework.weibo;

import java.awt.EventQueue;
import java.awt.Font;
import java.awt.Toolkit;
import java.math.BigInteger;
import java.net.MalformedURLException;
import java.net.URL;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

import javax.swing.ImageIcon;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTabbedPane;
import javax.swing.UIManager;
import javax.swing.UnsupportedLookAndFeelException;
import javax.swing.JSplitPane;

public class MainWindow extends JFrame {

	private Connection connection;

	public static void main(String[] args) throws ClassNotFoundException, InstantiationException, IllegalAccessException, UnsupportedLookAndFeelException {
		UIManager.setLookAndFeel(UIManager.getSystemLookAndFeelClassName());
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					Connection connection=new Connection();
					connection.login("boleyn.su@gmail.com",new char[]{'a'});
					MainWindow window = new MainWindow(connection);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	public MainWindow(Connection connection) throws NoSuchAlgorithmException, MalformedURLException {
		
		this.connection=connection;
		
		setTitle("金融微博");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(((int)Toolkit.getDefaultToolkit().getScreenSize().getWidth()-340)*7/8, ((int)Toolkit.getDefaultToolkit().getScreenSize().getHeight()-700)/3, 340, 700);
		setResizable(false);
		getContentPane().setLayout(null);
		
		JLabel avatar = new JLabel();
		avatar.setBounds(252, 0, 80, 80);
		getContentPane().add(avatar);
		String email=connection.getUsername().toLowerCase();
		MessageDigest messageDigest=MessageDigest.getInstance("md5");
		String md5=new BigInteger(1,messageDigest.digest(email.getBytes())).toString(16);
		avatar.setIcon(new ImageIcon(new URL("https://secure.gravatar.com/avatar/"+md5+"?s=80")));

		JTabbedPane tabbedPane = new JTabbedPane(JTabbedPane.TOP);
		tabbedPane.setFont(new Font("微软雅黑", Font.PLAIN, 12));
		tabbedPane.setBounds(3, 61, 329, 560);
		getContentPane().add(tabbedPane);
		
		JPanel panel_1 = new JPanel();
		tabbedPane.addTab("我的首页", null, panel_1, null);
		
		JPanel panel_2 = new JPanel();
		tabbedPane.addTab("@提到我的", null, panel_2, null);
		
		JScrollPane scrollPane = new JScrollPane();
		tabbedPane.addTab("评论列表", null, scrollPane, null);
		
		JScrollPane scrollPane_1 = new JScrollPane();
		tabbedPane.addTab("我的好友", null, scrollPane_1, null);
		
		JPanel panel = new JPanel();
		panel.setBounds(20, 5, 55, 45);
		getContentPane().add(panel);
		
		JPanel panel_3 = new JPanel();
		panel_3.setBounds(95, 5, 55, 45);
		getContentPane().add(panel_3);
		
		JPanel panel_4 = new JPanel();
		panel_4.setBounds(170, 5, 55, 45);
		getContentPane().add(panel_4);
		
		setVisible(true);
	}
}

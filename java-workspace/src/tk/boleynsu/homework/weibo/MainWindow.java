package tk.boleynsu.homework.weibo;

import java.awt.BorderLayout;
import java.awt.Cursor;
import java.awt.EventQueue;
import java.awt.Font;
import java.awt.Toolkit;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.math.BigInteger;
import java.net.MalformedURLException;
import java.net.URL;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTabbedPane;
import javax.swing.SwingConstants;
import javax.swing.UIManager;
import javax.swing.UnsupportedLookAndFeelException;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

public class MainWindow extends JFrame {

	private Connection connection;
	private JLabel followee,follower,weibo;
	private WriteDialog writeDialog=null;

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
		addWindowListener(new WindowAdapter() {
			@Override
			public void windowClosed(WindowEvent e) {
				if (writeDialog!=null&&writeDialog.isDisplayable())
					writeDialog.dispose();
			}
		});
		
		this.connection=connection;
		
		setTitle("金融微博");
		setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
		setBounds(((int)Toolkit.getDefaultToolkit().getScreenSize().getWidth()-340)*7/8, ((int)Toolkit.getDefaultToolkit().getScreenSize().getHeight()-700)/3, 340, 700);
		setResizable(false);
		getContentPane().setLayout(null);
		
		JLabel avatar = new JLabel();
		avatar.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				System.out.println("打开个人主页。");
			}
			@Override
			public void mouseEntered(MouseEvent e) {
				 setCursor(new Cursor(Cursor.HAND_CURSOR));
			}
			@Override
			public void mouseExited(MouseEvent e) {
				 setCursor(new Cursor(Cursor.DEFAULT_CURSOR));
			}
		});
		avatar.setBounds(249, 3, 80, 80);
		getContentPane().add(avatar);
		String email=connection.getUsername().toLowerCase();
		MessageDigest messageDigest=MessageDigest.getInstance("md5");
		String md5=new BigInteger(1,messageDigest.digest(email.getBytes())).toString(16);
		avatar.setIcon(new ImageIcon(new URL("https://secure.gravatar.com/avatar/"+md5+"?s=80")));

		JTabbedPane tabbedPane = new JTabbedPane(JTabbedPane.TOP);
		tabbedPane.setBounds(2, 65, 332, 550);
		getContentPane().add(tabbedPane);
		
		JScrollPane homepage = new JScrollPane();
		tabbedPane.addTab("我的首页", null, homepage, null);
		
		JScrollPane at = new JScrollPane();
		tabbedPane.addTab("@提到我的", null, at, null);
		
		JScrollPane reply = new JScrollPane();
		tabbedPane.addTab("评论列表", null, reply, null);
		
		JScrollPane friends = new JScrollPane();
		tabbedPane.addTab("我的好友", null, friends, null);
		
		JPanel followeePanel = new JPanel();
		followeePanel.setBounds(10, 10, 65, 45);
		getContentPane().add(followeePanel);
		followeePanel.setLayout(new BorderLayout(0, 0));
		
		followee = new JLabel("New label");
		followee.setFont(new Font("宋体", Font.PLAIN, 15));
		followeePanel.add(followee, BorderLayout.NORTH);
		
		followeePanel.add(new JLabel("关注",SwingConstants.CENTER), BorderLayout.SOUTH);
		
		JPanel followerPanel = new JPanel();
		followerPanel.setBounds(85, 10, 65, 45);
		getContentPane().add(followerPanel);
		followerPanel.setLayout(new BorderLayout(0, 0));
		
		follower = new JLabel("New label");
		follower.setFont(new Font("宋体", Font.PLAIN, 15));
		followerPanel.add(follower, BorderLayout.NORTH);
		
		followerPanel.add(new JLabel("粉丝",SwingConstants.CENTER), BorderLayout.SOUTH);
		
		JPanel weiboPanel = new JPanel();
		weiboPanel.setBounds(160, 10, 65, 45);
		getContentPane().add(weiboPanel);
		weiboPanel.setLayout(new BorderLayout(0, 0));
		
		weibo = new JLabel("New label");
		weibo.setFont(new Font("宋体", Font.PLAIN, 15));
		weiboPanel.add(weibo, BorderLayout.NORTH);
		
		weiboPanel.add(new JLabel("微博",SwingConstants.CENTER), BorderLayout.SOUTH);
		
		JMenuBar menuBar = new JMenuBar();
		menuBar.setBounds(20, 630, 30, 30);
		getContentPane().add(menuBar);
		
		JMenu menu = new JMenu("菜单");
		menuBar.add(menu);
		
		JMenuItem switchUser = new JMenuItem("切换用户");
		switchUser.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				MainWindow.this.dispose();
				try {
					new LoginDialog();
				} catch (MalformedURLException ex) {
					ex.printStackTrace();
				}
			}
		});
		menu.add(switchUser);
		
		JMenuItem quit = new JMenuItem("退出");
		quit.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				MainWindow.this.dispose();
			}
		});
		menu.add(quit);
		
		JButton button = new JButton("写微博");
		button.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				if (writeDialog==null||!writeDialog.isDisplayable()) writeDialog=new WriteDialog(MainWindow.this.connection);
				else writeDialog.requestFocus();
			}
		});
		button.setBounds(90, 630, 90, 30);
		getContentPane().add(button);
		
		JButton btnNewButton = new JButton("搜索");
		btnNewButton.setBounds(220, 630, 93, 30);
		getContentPane().add(btnNewButton);
		
		setVisible(true);
	}
}

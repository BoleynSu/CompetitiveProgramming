package tk.boleynsu.homework.weibo;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Component;
import java.awt.Cursor;
import java.awt.Dimension;
import java.awt.EventQueue;
import java.awt.Font;
import java.awt.Toolkit;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.math.BigInteger;
import java.net.MalformedURLException;
import java.net.URL;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.List;

import javax.swing.BoxLayout;
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
import javax.swing.JTextArea;
import javax.swing.SwingConstants;
import javax.swing.UIManager;
import javax.swing.UnsupportedLookAndFeelException;

class Microblog {
	public long id,parentId,repostNumber;
	public String author,parent,text,time,email;
	Microblog(long id,String author,String parent,String text,String time,String email,long parentId,long repostNumber)
	{
		this.id=id;
		this.author=author;
		this.parent=parent;
		this.text=text;
		this.time=time;
		this.email=email;
		this.parentId=parentId;
		this.repostNumber=repostNumber;
	}
}
class User {
	public long id;
	public String username,nickname;
	User(long id,String username,String nickname)
	{
		this.id=id;
		this.username=username;
		this.nickname=nickname;
	}
}

public class MainWindow extends JFrame {

	private Connection connection;
	JLabel avatar;
	private JLabel followee,follower,microblog;
	private WriteDialog writeDialog;
	private RepostDialog repostDialog;
	private SearchDialog searchDialog;
	private Thread updateThread;
	private JScrollPane homepage,at,followeePane,followerPane;
	

	public static void main(String[] args) throws ClassNotFoundException, InstantiationException, IllegalAccessException, UnsupportedLookAndFeelException {
		UIManager.setLookAndFeel(UIManager.getSystemLookAndFeelClassName());
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					Connection connection=new Connection();
					if (connection.login("boleyn.su@gmail.com","b42e548db05db1db1ee796dd85c017f1"))
					{
						MainWindow window = new MainWindow(connection);
					}
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	private JPanel getPanelByMicroblog(Microblog mb)
	{
		JPanel panel=new JPanel();
		panel.setLayout(new BoxLayout(panel, BoxLayout.Y_AXIS));
		
		JPanel authorPanel=new JPanel();
		authorPanel.setPreferredSize(new Dimension(305,25));
		authorPanel.setMinimumSize(new Dimension(305,20));
		authorPanel.setMaximumSize(new Dimension(305,20));
		authorPanel.setLayout(null);
		JLabel avatar=new JLabel();
		avatar.setBounds(0, 0, 20, 20);
		authorPanel.add(avatar);
		MessageDigest messageDigest;
		try {
			messageDigest = MessageDigest.getInstance("md5");
			String md5=new BigInteger(1,messageDigest.digest(mb.email.toLowerCase().getBytes())).toString(16);
			avatar.setIcon(new ImageIcon(new URL("https://secure.gravatar.com/avatar/"+md5+"?s=20")));
		} catch (NoSuchAlgorithmException e) {
			e.printStackTrace();
		} catch (MalformedURLException e) {
			e.printStackTrace();
		}
		JButton authorButton=new JButton("@"+mb.author+":");
		authorButton.setHorizontalAlignment(JButton.LEFT);
		authorButton.setBounds(20, 0, 285, 20);
		authorButton.setOpaque(false);
		authorButton.setContentAreaFilled(false);
		authorButton.setBorderPainted(false);
		authorPanel.add(authorButton);
		panel.add(authorPanel);

		JPanel textPanel=new JPanel();
		textPanel.setLayout(new BorderLayout());
		JTextArea textArea=new JTextArea(mb.text);
		textArea.setLineWrap(true);
		textArea.setBackground(new Color(0,102,255));
		textArea.setEditable(false);
		textPanel.add(textArea);
		panel.add(textPanel);
		
		if (mb.parent!=null)
		{
			JPanel parentPanel=new JPanel();
			parentPanel.setLayout(new BorderLayout());
			String parentNickname=connection.getNicknameByMicroblogId(mb.parentId);
			JTextArea parentArea=new JTextArea("//@"+parentNickname+":"+mb.parent);
			parentArea.setLineWrap(true);
			parentArea.setBackground(new Color(51,204,204));
			parentArea.setEditable(false);
			parentPanel.add(parentArea);
			panel.add(parentPanel);
		}
		
		JPanel misPanel=new JPanel();
		misPanel.setPreferredSize(new Dimension(305,25));
		misPanel.setMinimumSize(new Dimension(305,20));
		misPanel.setMaximumSize(new Dimension(305,25));
		misPanel.setLayout(null);
		JLabel timeLabel=new JLabel("发布于:"+mb.time);
		timeLabel.setBounds(0, 0, 175, 25);
		misPanel.add(timeLabel);
		JButton repostButton=new JButton("转发");
		repostButton.addActionListener(new ActionListener() {
			private long parent;
			private String curmb,premb;
			@Override
			public void actionPerformed(ActionEvent e) {
				if (repostDialog==null||!repostDialog.isDisplayable()) repostDialog=new RepostDialog(MainWindow.this.connection,parent,premb,curmb);
				else repostDialog.requestFocus();
			}
			public ActionListener set(long parent,String pmb,String cmb)
			{
				this.parent=parent;
				this.premb=pmb;
				this.curmb=cmb;
				return this;
			}
		}.set(mb.parentId==0?mb.id:mb.parentId,mb.parentId==0?"//@"+mb.author+":"+mb.text:"//@"+connection.getNicknameByMicroblogId(mb.parentId)+":"+mb.parent,mb.parentId==0?"":"//@"+mb.author+":"+mb.text));
		repostButton.setBounds(175, 0, 70, 25);
		repostButton.setOpaque(false);
		repostButton.setContentAreaFilled(false);
		repostButton.setBorderPainted(false);
		misPanel.add(repostButton);
		JButton viewRepostButton=new JButton(new Long(mb.repostNumber).toString());
		viewRepostButton.setBounds(245, 0, 60, 25);
		viewRepostButton.setOpaque(false);
		viewRepostButton.setContentAreaFilled(false);
		viewRepostButton.setBorderPainted(false);
		misPanel.add(viewRepostButton);
		panel.add(misPanel);
		
		return panel;
	}
	
	private Component getPanelByUser(User user) {
		JPanel panel=new JPanel();
		panel.setLayout(new BoxLayout(panel, BoxLayout.Y_AXIS));
		
		JPanel authorPanel=new JPanel();
		authorPanel.setPreferredSize(new Dimension(305,25));
		authorPanel.setMinimumSize(new Dimension(305,20));
		authorPanel.setMaximumSize(new Dimension(305,20));
		authorPanel.setLayout(null);
		JLabel avatar=new JLabel();
		avatar.setBounds(0, 0, 20, 20);
		authorPanel.add(avatar);
		MessageDigest messageDigest;
		try {
			messageDigest = MessageDigest.getInstance("md5");
			String md5=new BigInteger(1,messageDigest.digest(user.username.toLowerCase().getBytes())).toString(16);
			avatar.setIcon(new ImageIcon(new URL("https://secure.gravatar.com/avatar/"+md5+"?s=20")));
		} catch (NoSuchAlgorithmException e) {
			e.printStackTrace();
		} catch (MalformedURLException e) {
			e.printStackTrace();
		}
		JButton authorButton=new JButton(user.nickname);
		authorButton.setHorizontalAlignment(JButton.LEFT);
		authorButton.setBounds(20, 0, 285, 20);
		authorButton.setOpaque(false);
		authorButton.setContentAreaFilled(false);
		authorButton.setBorderPainted(false);
		authorPanel.add(authorButton);
		authorPanel.setBackground(Color.red);
		panel.add(authorPanel);

		return panel;
	}
	
	private void update() throws NoSuchAlgorithmException, MalformedURLException
	{
		setTitle(connection.getNickname());
		
		String email=connection.getUsername().toLowerCase();
		MessageDigest messageDigest=MessageDigest.getInstance("md5");
		String md5=new BigInteger(1,messageDigest.digest(email.getBytes())).toString(16);
		avatar.setIcon(new ImageIcon(new URL("https://secure.gravatar.com/avatar/"+md5+"?s=80")));
		
		followee.setText(connection.getFolloweeNumber().toString());
		follower.setText(connection.getFollowerNumber().toString());
		microblog.setText(connection.getMicroblogNumber().toString());
		{
			List<Microblog> fetch=connection.getNewerMicroblog();
			JPanel panel = new JPanel();
			panel.setLayout(new BoxLayout(panel, BoxLayout.Y_AXIS));
			
			int value=homepage.getVerticalScrollBar().getValue();
			for (int i=0;i<fetch.size();i++)
				panel.add(getPanelByMicroblog(fetch.get(i)));
			homepage.setViewportView(panel);
			homepage.getVerticalScrollBar().setValue(value);
		}
		{
			List<Microblog> fetch=connection.getNewerAt();
			JPanel panel = new JPanel();
			panel.setLayout(new BoxLayout(panel, BoxLayout.Y_AXIS));
			
			int value=at.getVerticalScrollBar().getValue();
			for (int i=0;i<fetch.size();i++)
				panel.add(getPanelByMicroblog(fetch.get(i)));
			at.setViewportView(panel);
			at.getVerticalScrollBar().setValue(value);
		}
		{
			List<User> fetch=connection.getFolloweeList();
			JPanel panel = new JPanel();
			panel.setLayout(new BoxLayout(panel, BoxLayout.Y_AXIS));
			
			int value=followeePane.getVerticalScrollBar().getValue();
			for (int i=0;i<fetch.size();i++)
				panel.add(getPanelByUser(fetch.get(i)));
			followeePane.setViewportView(panel);
			followeePane.getVerticalScrollBar().setValue(value);
		}
		{
			List<User> fetch=connection.getFollowerList();
			JPanel panel = new JPanel();
			panel.setLayout(new BoxLayout(panel, BoxLayout.Y_AXIS));
			
			int value=followerPane.getVerticalScrollBar().getValue();
			for (int i=0;i<fetch.size();i++)
				panel.add(getPanelByUser(fetch.get(i)));
			followerPane.setViewportView(panel);
			followerPane.getVerticalScrollBar().setValue(value);
		}
	}

	public MainWindow(Connection connection) {
		addWindowListener(new WindowAdapter() {
			@Override
			public void windowClosed(WindowEvent e) {
				if (writeDialog!=null&&writeDialog.isDisplayable())
					writeDialog.dispose();
				if (repostDialog!=null&&repostDialog.isDisplayable())
					repostDialog.dispose();
				if (searchDialog!=null&&searchDialog.isDisplayable())
					searchDialog.dispose();
				if (updateThread.isAlive()) updateThread.stop();
			}
		});
		
		this.connection=connection;
		
		setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
		setBounds(((int)Toolkit.getDefaultToolkit().getScreenSize().getWidth()-340)*7/8, ((int)Toolkit.getDefaultToolkit().getScreenSize().getHeight()-700)/3, 340, 700);
		setResizable(false);
		getContentPane().setLayout(null);
		
		avatar = new JLabel();
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

		JTabbedPane tabbedPane = new JTabbedPane(JTabbedPane.TOP);
		tabbedPane.setBounds(2, 65, 332, 550);
		getContentPane().add(tabbedPane);

		homepage = new JScrollPane();
		tabbedPane.addTab("我的首页", null, homepage, null);
		repostDialog=null;
		
		at = new JScrollPane();
		tabbedPane.addTab("@提到我的", null, at, null);
		
		/*
		 * TODO 可以添加评论功能 和@是类似的
		JScrollPane reply = new JScrollPane();
		tabbedPane.addTab("评论列表", null, reply, null);
		*/
		
		JTabbedPane friends = new JTabbedPane(JTabbedPane.TOP);
		tabbedPane.addTab("我的好友", null, friends, null);
		
		followeePane = new JScrollPane();
		friends.addTab("我的关注", null, followeePane, null);
		
		followerPane = new JScrollPane();
		friends.addTab("我的好友", null, followerPane, null);

		JPanel followeePanel = new JPanel();
		followeePanel.setBounds(10, 10, 65, 45);
		getContentPane().add(followeePanel);
		followeePanel.setLayout(new BorderLayout(0, 0));
		
		followee = new JLabel();
		followee.setHorizontalAlignment(SwingConstants.CENTER);
		followee.setFont(new Font("宋体", Font.PLAIN, 15));
		followeePanel.add(followee, BorderLayout.NORTH);
		
		followeePanel.add(new JLabel("关注",SwingConstants.CENTER), BorderLayout.SOUTH);
		
		JPanel followerPanel = new JPanel();
		followerPanel.setBounds(85, 10, 65, 45);
		getContentPane().add(followerPanel);
		followerPanel.setLayout(new BorderLayout(0, 0));
		
		follower = new JLabel();
		follower.setHorizontalAlignment(SwingConstants.CENTER);
		follower.setFont(new Font("宋体", Font.PLAIN, 15));
		followerPanel.add(follower, BorderLayout.NORTH);
		
		followerPanel.add(new JLabel("粉丝",SwingConstants.CENTER), BorderLayout.SOUTH);
		
		JPanel microblogPanel = new JPanel();
		microblogPanel.setBounds(160, 10, 65, 45);
		getContentPane().add(microblogPanel);
		microblogPanel.setLayout(new BorderLayout(0, 0));
		
		microblog = new JLabel();
		microblog.setHorizontalAlignment(SwingConstants.CENTER);
		microblog.setFont(new Font("宋体", Font.PLAIN, 15));
		microblogPanel.add(microblog, BorderLayout.NORTH);
		
		microblogPanel.add(new JLabel("微博",SwingConstants.CENTER), BorderLayout.SOUTH);
		
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
		
		writeDialog=null;
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
		btnNewButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				if (searchDialog==null||!searchDialog.isDisplayable()) searchDialog=new SearchDialog(MainWindow.this.connection);
				else searchDialog.requestFocus();
			}
		});
		btnNewButton.setBounds(220, 630, 93, 30);
		getContentPane().add(btnNewButton);

		setVisible(true);
		
		updateThread=new Thread(new Runnable() {
			@Override
			public void run() {
				while (MainWindow.this.isDisplayable())
				{
					try {
						update();
						//TODO Thread.sleep(1000*60*5);//五分钟更新一次
						Thread.sleep(1000*5);//五秒更新一次
					} catch (NoSuchAlgorithmException e) {
						e.printStackTrace();
					} catch (MalformedURLException e) {
						e.printStackTrace();
					} catch (InterruptedException e) {
						e.printStackTrace();
					}
				}
			}
		});
		updateThread.start();
	}
}

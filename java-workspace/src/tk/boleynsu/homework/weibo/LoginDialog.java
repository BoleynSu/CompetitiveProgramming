package tk.boleynsu.homework.weibo;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.EventQueue;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.Image;
import java.awt.Point;
import java.awt.Toolkit;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.MouseMotionAdapter;
import java.math.BigInteger;
import java.net.MalformedURLException;
import java.net.URL;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JPasswordField;
import javax.swing.JTextField;
import javax.swing.SwingConstants;
import javax.swing.UIManager;
import javax.swing.event.DocumentEvent;
import javax.swing.event.DocumentListener;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;

class BackgroundPanel extends JPanel {
	private Image bg;
	BackgroundPanel(String path) {
		this.bg=new ImageIcon(path).getImage();
	}
	@Override
	public void paintComponent(Graphics g) {
		g.drawImage(bg, 0, 0, getWidth(), getHeight(), this);
	}
}

class BackgroundButton extends JButton {
	private ImageIcon normal,press;
	public BackgroundButton(String normalPath,String pressPath) {
		normal=new ImageIcon(normalPath);
		press=new ImageIcon(pressPath);
		addMouseListener(new MouseAdapter() {
			@Override
			public void mousePressed(MouseEvent e) {
				setIcon(press);
			}
			@Override
			public void mouseReleased(MouseEvent e) {
				setIcon(normal);
			}
		});
		setOpaque(false);
		setContentAreaFilled(false);
		setBorderPainted(false);
		setIcon(normal);
	}
}

public class LoginDialog extends JFrame {

	private Point origin = new Point();
	private JPanel contentPane;
	private JPanel loginPane;
	private JLabel avatar;
	private JTextField username;
	private JPasswordField password;
	private JButton close,minimize,login;

	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					LoginDialog frame = new LoginDialog();
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	public LoginDialog() throws MalformedURLException {
		addMouseListener(new MouseAdapter() {
			@Override
			public void mousePressed(MouseEvent e) {
				origin.x = e.getX();
				origin.y = e.getY();
			}
		});
		addMouseMotionListener(new MouseMotionAdapter() {
			@Override
			public void mouseDragged(MouseEvent e) {
				Point p = getLocation();
				setLocation(p.x + e.getX() - origin.x, p.y + e.getY() - origin.y);
			}
		});
		setUndecorated(true);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds((int)(Toolkit.getDefaultToolkit().getScreenSize().getWidth()-340)/2, ((int)Toolkit.getDefaultToolkit().getScreenSize().getHeight()-220)/3, 340, 220);
		setResizable(false);
		contentPane = new BackgroundPanel("E:\\Documents\\ACM\\workspace\\acmicpc-codes\\java-workspace\\src\\tk\\boleynsu\\homework\\weibo\\images\\login.png");
		contentPane.setLayout(new BorderLayout());
		loginPane=new JPanel();
		loginPane.setOpaque(false);
		loginPane.setSize(340, 220);
		contentPane.add(loginPane, BorderLayout.CENTER);
		
		loginPane.setLayout(null);
		
		close = new BackgroundButton("E:\\Documents\\ACM\\workspace\\acmicpc-codes\\java-workspace\\src\\tk\\boleynsu\\homework\\weibo\\images\\close~normal.png","E:\\Documents\\ACM\\workspace\\acmicpc-codes\\java-workspace\\src\\tk\\boleynsu\\homework\\weibo\\images\\close~press.png");
		close.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				LoginDialog.this.dispose();
			}
		});
		close.setBounds(316, 0, 24, 24);
		loginPane.add(close);
		
		minimize = new BackgroundButton("E:\\Documents\\ACM\\workspace\\acmicpc-codes\\java-workspace\\src\\tk\\boleynsu\\homework\\weibo\\images\\minimize~normal.png","E:\\Documents\\ACM\\workspace\\acmicpc-codes\\java-workspace\\src\\tk\\boleynsu\\homework\\weibo\\images\\minimize~press.png");
		minimize.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				LoginDialog.this.setState(ICONIFIED);
			}
		});
		minimize.setBounds(292, 0, 24, 24);
		loginPane.add(minimize);
		
		avatar = new JLabel(new ImageIcon(new URL("https://secure.gravatar.com/avatar/?s=80")));
		avatar.setBounds(20, 90, 80, 80);
		loginPane.add(avatar);
		
		username = new JTextField();
		username.addKeyListener(new KeyAdapter() {
			@Override
			public void keyPressed(KeyEvent e) {
				if (e.getKeyCode()==KeyEvent.VK_ENTER)
				{
					Connection connection=new Connection();
					if (!connection.login(username.getText(),password.getPassword()))
					{
						username.setText("用户名或者密码错误！");
					}
					else
					{
						LoginDialog.this.dispose();
						try {
							new MainWindow(connection);
						} catch (NoSuchAlgorithmException ex) {
							ex.printStackTrace();
						} catch (MalformedURLException ex) {
							ex.printStackTrace();
						}
					}
				}	
			}
		});
		username.setFont(new Font("宋体", Font.PLAIN, 15));
		username.setBounds(120, 100, 200, 24);
		loginPane.add(username);
		username.setColumns(10);
		username.getDocument().addDocumentListener(new DocumentListener()
		{
			private void update()
			{
				new Thread(new Runnable()
				{
					public void run()
					{
						try {
							String email=username.getText().toLowerCase();
							MessageDigest messageDigest=MessageDigest.getInstance("md5");
							String md5=new BigInteger(1,messageDigest.digest(email.getBytes())).toString(16);
							avatar.setIcon(new ImageIcon(new URL("https://secure.gravatar.com/avatar/"+md5+"?s=80")));
						} catch (NoSuchAlgorithmException e) {
							e.printStackTrace();
						} catch (MalformedURLException e) {
							e.printStackTrace();
						}
					}
				}).start();
			}
			@Override
			public void changedUpdate(DocumentEvent e) {
			}

			@Override
			public void insertUpdate(DocumentEvent e) {
				update();
			}

			@Override
			public void removeUpdate(DocumentEvent e) {
				update();
			}
			
		});

		password = new JPasswordField();
		password.addKeyListener(new KeyAdapter() {
			@Override
			public void keyPressed(KeyEvent e) {
				if (e.getKeyCode()==KeyEvent.VK_ENTER)
				{
					Connection connection=new Connection();
					if (!connection.login(username.getText(),password.getPassword()))
					{
						username.setText("用户名或者密码错误！");
					}
					else
					{
						LoginDialog.this.dispose();
						try {
							new MainWindow(connection);
						} catch (NoSuchAlgorithmException ex) {
							ex.printStackTrace();
						} catch (MalformedURLException ex) {
							ex.printStackTrace();
						}
					}
				}	
			}
		});
		password.setFont(new Font("宋体", Font.PLAIN, 15));
		password.setBounds(120, 140, 200, 24);
		loginPane.add(password);
		password.setColumns(10);
		
		login = new BackgroundButton("E:\\Documents\\ACM\\workspace\\acmicpc-codes\\java-workspace\\src\\tk\\boleynsu\\homework\\weibo\\images\\button~normal.png","E:\\Documents\\ACM\\workspace\\acmicpc-codes\\java-workspace\\src\\tk\\boleynsu\\homework\\weibo\\images\\button~press.png");
		login.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				Connection connection=new Connection();
				if (!connection.login(username.getText(),password.getPassword()))
				{
					username.setText("用户名或者密码错误！");
				}
				else
				{
					LoginDialog.this.dispose();
					try {
						new MainWindow(connection);
					} catch (NoSuchAlgorithmException ex) {
						ex.printStackTrace();
					} catch (MalformedURLException ex) {
						ex.printStackTrace();
					}
				}
			}
		});
		login.setBounds(150, 175, 148, 36);
		login.setLayout(null);
		JLabel loginLabel = new JLabel("登陆 ");
		loginLabel.setBounds(24, 3, 100, 30);
		loginLabel.setFont(new Font("微软雅黑", Font.PLAIN, 20));
		loginLabel.setHorizontalAlignment(SwingConstants.CENTER);
		login.add(loginLabel);
		loginPane.add(login);
		
		JLabel title = new JLabel();
		title.setIcon(new ImageIcon("E:\\Documents\\ACM\\workspace\\acmicpc-codes\\java-workspace\\src\\tk\\boleynsu\\homework\\weibo\\images\\title.png"));
		title.setBounds(0, 0, 292, 24);
		JLabel titleLabel = new JLabel("金融微博",JLabel.CENTER);
		titleLabel.setForeground(Color.WHITE);
		titleLabel.setFont(new Font("微软雅黑", Font.PLAIN, 18));
		titleLabel.setBounds(0, 0, 292, 24);
		title.add(titleLabel);
		loginPane.add(title);
		
		setContentPane(contentPane);
		
		setVisible(true);
	}
}

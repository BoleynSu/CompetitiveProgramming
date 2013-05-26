package tk.boleynsu.homework.weibo;

import java.awt.BorderLayout;
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
import javax.swing.event.DocumentEvent;
import javax.swing.event.DocumentListener;

class BackgroundPanel extends JPanel {
	private Image bg = new ImageIcon("src/tk/boleynsu/homework/weibo/images/login.png").getImage();
	@Override
	public void paintComponent(Graphics g) {
		g.drawImage(bg, 0, 0, getWidth(), getHeight(), this);
	}
}

public class LoginDialog extends JFrame {

	private Point origin = new Point();
	private JPanel contentPane;
	private JPanel loginPane;
	private JLabel avatar;
	private JTextField username;
	private JPasswordField password;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					LoginDialog frame = new LoginDialog();
					frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the frame.
	 * @throws MalformedURLException 
	 */
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
		setBounds((int)Toolkit.getDefaultToolkit().getScreenSize().getWidth()/2-170, ((int)Toolkit.getDefaultToolkit().getScreenSize().getHeight()-220)/3, 340, 220);
		setResizable(false);
		contentPane = new BackgroundPanel();
		contentPane.setLayout(new BorderLayout());
		loginPane=new JPanel();
		loginPane.setOpaque(false);
		loginPane.setSize(340, 220);
		contentPane.add(loginPane, BorderLayout.CENTER);
		
		loginPane.setLayout(null);
		
		JButton close = new JButton();
		close.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				LoginDialog.this.dispose();
			}
		});
		close.setBounds(316, 0, 24, 24);
		//close.setBorderPainted(false);
		//close.setContentAreaFilled(false);
		loginPane.add(close);
		
		JButton minimize = new JButton();
		minimize.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				LoginDialog.this.setState(ICONIFIED);
			}
		});
		minimize.setBounds(292, 0, 24, 24);
		//minimize.setBorderPainted(false);
		//minimize.setContentAreaFilled(false);
		loginPane.add(minimize);
		
		avatar = new JLabel(new ImageIcon(new URL("https://secure.gravatar.com/avatar/?s=80")));
		avatar.setBounds(20, 90, 80, 80);
		loginPane.add(avatar);
		
		username = new JTextField();
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
							String email=username.getText();
							MessageDigest messageDigest=MessageDigest.getInstance("md5");
							String md5=new BigInteger(1,messageDigest.digest(email.getBytes())).toString(16);
							avatar.setIcon(new ImageIcon(new URL("https://secure.gravatar.com/avatar/"+md5+"?s=80")));
						} catch (NoSuchAlgorithmException e) {
							// TODO Auto-generated catch block
							e.printStackTrace();
						} catch (MalformedURLException e) {
							// TODO Auto-generated catch block
							e.printStackTrace();
						}
					}
				}).start();
			}
			@Override
			public void changedUpdate(DocumentEvent e) {
				// TODO Auto-generated method stub
			}

			@Override
			public void insertUpdate(DocumentEvent e) {
				// TODO Auto-generated method stub
				update();
			}

			@Override
			public void removeUpdate(DocumentEvent e) {
				// TODO Auto-generated method stub
				update();
			}
			
		});

		password = new JPasswordField();
		password.setFont(new Font("宋体", Font.PLAIN, 15));
		password.setBounds(120, 140, 200, 24);
		loginPane.add(password);
		password.setColumns(10);
		
		JButton login = new JButton("登陆");
		login.setFont(new Font("宋体", Font.PLAIN, 12));
		login.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				System.out.println(username.getText());
				System.out.println(password.getText());
			}
		});
		login.setBounds(220, 180, 100, 24);
		loginPane.add(login);
		
		JButton register = new JButton("注册");
		register.setFont(new Font("宋体", Font.PLAIN, 12));
		register.setBounds(20, 180, 80, 24);
		loginPane.add(register);
		setContentPane(contentPane);
	}
}

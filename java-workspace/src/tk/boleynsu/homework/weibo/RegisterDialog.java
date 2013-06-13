package tk.boleynsu.homework.weibo;

import java.awt.EventQueue;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.math.BigInteger;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JPasswordField;
import javax.swing.JTextField;
import javax.swing.UIManager;
import javax.swing.UnsupportedLookAndFeelException;
import javax.swing.border.EmptyBorder;

public class RegisterDialog extends JFrame {

	private Connection connection;
	private JPanel contentPane;
	private JTextField nickname;
	private JPasswordField pwd;
	private JPasswordField repeatPwd;
	private JTextField username;
	private JLabel message;

	public static void main(String[] args) throws ClassNotFoundException, InstantiationException, IllegalAccessException, UnsupportedLookAndFeelException {
		UIManager.setLookAndFeel(UIManager.getSystemLookAndFeelClassName());
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					Connection connection=new Connection();
					RegisterDialog frame = new RegisterDialog(connection);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	public RegisterDialog(Connection connection) {
		this.connection=connection;
		setTitle("注册");
		setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
		setBounds(100, 100, 330, 230);
		setResizable(false);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		contentPane.setLayout(null);

		setContentPane(contentPane);
		
		JLabel label = new JLabel("用户名");
		label.setBounds(10, 26, 54, 15);
		contentPane.add(label);
		
		JLabel label_1 = new JLabel("昵称");
		label_1.setBounds(10, 60, 54, 15);
		contentPane.add(label_1);
		
		JLabel label_2 = new JLabel("密码");
		label_2.setBounds(10, 95, 54, 15);
		contentPane.add(label_2);
		
		JLabel label_3 = new JLabel("重复密码");
		label_3.setBounds(10, 131, 54, 15);
		contentPane.add(label_3);
		
		nickname = new JTextField();
		nickname.setBounds(73, 54, 241, 21);
		contentPane.add(nickname);
		nickname.setColumns(10);
		
		pwd = new JPasswordField();
		pwd.setColumns(10);
		pwd.setBounds(73, 92, 241, 21);
		contentPane.add(pwd);
		
		repeatPwd = new JPasswordField();
		repeatPwd.setColumns(10);
		repeatPwd.setBounds(73, 128, 241, 21);
		contentPane.add(repeatPwd);
		
		username = new JTextField();
		username.setColumns(10);
		username.setBounds(73, 23, 241, 21);
		contentPane.add(username);
		
		JButton button = new JButton("注册");
		button.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				if (!pwd.getText().equals(repeatPwd.getText()))
				{
					message.setText("两次输入的密码不一样！");
					return ;
				}
				String password=new String(pwd.getPassword());
				String pwd=new String(password.toLowerCase());
				MessageDigest messageDigest;
				try {
					messageDigest = MessageDigest.getInstance("md5");
					String md5=new BigInteger(1,messageDigest.digest(pwd.getBytes())).toString(16);
					if (RegisterDialog.this.connection.register(username.getText(), nickname.getText(), md5))
					{
						message.setText("注册成功！");
						return ;
					}
				} catch (NoSuchAlgorithmException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}
				message.setText("注册失败！");
			}
		});
		button.setBounds(201, 168, 93, 23);
		contentPane.add(button);
		
		message = new JLabel("");
		message.setBounds(22, 172, 160, 19);
		contentPane.add(message);
		
		setVisible(true);
	}
}

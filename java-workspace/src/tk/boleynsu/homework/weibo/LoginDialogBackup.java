package tk.boleynsu.homework.weibo;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.Box;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JPasswordField;
import javax.swing.JTextField;
import javax.swing.WindowConstants;

public class LoginDialogBackup extends JFrame
{
	private JTextField username=new JTextField();
	private JPasswordField password=new JPasswordField();
	private JPasswordField passwordAgain=new JPasswordField();
	private Box passwordAgainBox;
	private Box loginBox;
	private Box registerBox;
	LoginDialogBackup()
	{
		super("登陆");
		JPanel panel=new JPanel();
		Box box=Box.createVerticalBox();
		box.add(Box.createVerticalStrut(10));
		Box usernameBox=Box.createHorizontalBox();
		usernameBox.add(new JLabel("用户名："));
		usernameBox.add(Box.createHorizontalStrut(10));
		usernameBox.add(username);
		box.add(usernameBox);
		box.add(Box.createVerticalStrut(5));
		Box passwordBox=Box.createHorizontalBox();
		passwordBox.add(new JLabel("密码："));
		passwordBox.add(Box.createHorizontalStrut(10));
		passwordBox.add(password);
		box.add(passwordBox);
		passwordAgainBox=Box.createHorizontalBox();
		passwordAgainBox.add(new JLabel("密  码："));
		passwordAgainBox.add(Box.createHorizontalStrut(10));
		passwordAgainBox.add(passwordAgain);
		box.add(passwordAgainBox);
		passwordAgainBox.setVisible(false);
		box.add(Box.createVerticalStrut(5));
		loginBox=Box.createHorizontalBox();
		JButton toRegister=new JButton("去注册");
		loginBox.add(toRegister);
		toRegister.addActionListener(new ActionListener()
		{
			public void actionPerformed(ActionEvent e)
			{
				loginBox.setVisible(false);
				registerBox.setVisible(true);
				passwordAgainBox.setVisible(true);
				LoginDialogBackup.this.pack();
			}
		});
		loginBox.add(Box.createHorizontalStrut(10));
		JButton login=new JButton("登陆");
		loginBox.add(login);
		box.add(loginBox);
		registerBox=Box.createHorizontalBox();
		JButton toLogin=new JButton("去登陆");
		registerBox.add(toLogin);
		toLogin.addActionListener(new ActionListener()
		{
			public void actionPerformed(ActionEvent e)
			{
				passwordAgainBox.setVisible(false);
				registerBox.setVisible(false);
				loginBox.setVisible(true);
				LoginDialogBackup.this.pack();
			}
		});
		registerBox.add(Box.createHorizontalStrut(10));
		JButton register=new JButton("注册");
		registerBox.add(register);
		box.add(registerBox);
		registerBox.setVisible(false);
		box.add(Box.createVerticalStrut(5));
		panel.add(box);
		getContentPane().add(panel);
		setVisible(true);
		pack();
		setResizable(false);
		setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
	}
}

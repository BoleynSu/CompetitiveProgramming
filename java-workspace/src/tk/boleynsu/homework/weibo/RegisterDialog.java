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

public class RegisterDialog extends JFrame
{
	JTextField username=new JTextField(10);
	JPasswordField password=new JPasswordField(10);
	JButton register=new JButton("注册");
	JButton login=new JButton("登陆");
	RegisterDialog()
	{
		super("fsdf登陆");
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
		passwordBox.add(Box.createHorizontalStrut(22));
		passwordBox.add(password);
		box.add(passwordBox);
		box.add(Box.createVerticalStrut(5));
		Box loginBox=Box.createHorizontalBox();
		loginBox.add(register);
		register.addActionListener(new ActionListener()
		{
			public void actionPerformed(ActionEvent e)
			{
				RegisterDialog.this.setVisible(false);
				RegisterDialog registerDialog=new RegisterDialog();
				RegisterDialog.this.setVisible(true);
			}
		});
		loginBox.add(Box.createHorizontalStrut(10));
		loginBox.add(login);
		box.add(loginBox);
		panel.add(box);
		getContentPane().add(panel);
		pack();
		setResizable(false);
		setVisible(true);
		setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
	}
}

package tk.boleynsu.homework.weibo;

import java.awt.BorderLayout;
import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.UIManager;
import javax.swing.UnsupportedLookAndFeelException;
import javax.swing.border.EmptyBorder;
import javax.swing.event.DocumentEvent;
import javax.swing.event.DocumentListener;
import javax.swing.JScrollPane;
import javax.swing.JTextField;
import javax.swing.JButton;
import java.awt.FlowLayout;
import javax.swing.JLabel;
import javax.swing.JTextArea;
import javax.swing.ScrollPaneConstants;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.sql.SQLException;
import javax.swing.SwingConstants;

public class SearchDialog extends JFrame {

	private Connection connection;
	private JPanel contentPane;
	private JTextField textField;
	private JLabel message;

	public static void main(String[] args) throws ClassNotFoundException, InstantiationException, IllegalAccessException, UnsupportedLookAndFeelException {
		UIManager.setLookAndFeel(UIManager.getSystemLookAndFeelClassName());
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					Connection connection=new Connection();
					SearchDialog frame = new SearchDialog(connection);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	public SearchDialog(Connection connection) {
		this.connection=connection;
		setTitle("搜索");
		setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
		setBounds(100, 100, 330, 130);
		setResizable(false);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		contentPane.setLayout(null);

		setContentPane(contentPane);
		
		JButton follow = new JButton("搜索并关注");
		follow.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				if (SearchDialog.this.connection.follow(textField.getText()))
				{
					message.setText("成功关注"+textField.getText());
				}
				else
				{
					message.setText("关注"+textField.getText()+"失败");
				}
			}
		});
		follow.setBounds(10, 73, 138, 23);
		contentPane.add(follow);
		
		JButton unfollow = new JButton("搜索并取消关注");
		unfollow.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				if (SearchDialog.this.connection.unfollow(textField.getText()))
				{
					message.setText("成功取消关注"+textField.getText());
				}
				else
				{
					message.setText("取消关注"+textField.getText()+"失败");
				}
			}
		});
		unfollow.setBounds(176, 73, 138, 23);
		contentPane.add(unfollow);
		
		message = new JLabel();
		message.setBounds(10, 43, 304, 23);
		contentPane.add(message);
		
		textField = new JTextField();
		textField.setBounds(10, 10, 304, 23);
		contentPane.add(textField);
		textField.setColumns(10);
		
		setVisible(true);
	}
}

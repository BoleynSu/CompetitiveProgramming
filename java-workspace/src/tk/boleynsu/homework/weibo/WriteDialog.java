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

public class WriteDialog extends JFrame {

	private Connection connection;
	private JPanel contentPane;
	private JTextArea textField;
	private JLabel counter;
	private JButton button;

	public static void main(String[] args) throws ClassNotFoundException, InstantiationException, IllegalAccessException, UnsupportedLookAndFeelException {
		UIManager.setLookAndFeel(UIManager.getSystemLookAndFeelClassName());
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					Connection connection=new Connection();
					connection.login("boleyn.su@gmail.com",new char[]{'a'});
					WriteDialog frame = new WriteDialog(connection);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	public WriteDialog(Connection connection) {
		this.connection=connection;
		setTitle("写微博");
		setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
		setBounds(100, 100, 330, 200);
		setResizable(false);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		contentPane.setLayout(null);
		
		JScrollPane scrollPane = new JScrollPane();
		scrollPane.setHorizontalScrollBarPolicy(ScrollPaneConstants.HORIZONTAL_SCROLLBAR_NEVER);
		scrollPane.setBounds(2, 0, 320, 130);
		contentPane.add(scrollPane);
		
		textField = new JTextArea();
		textField.setLineWrap(true);
		scrollPane.setViewportView(textField);
		textField.setColumns(10);
		textField.getDocument().addDocumentListener(new DocumentListener() {
			
			private void update()
			{
				int length=textField.getText().length();
				button.setEnabled(0<length&&length<=140);
				counter.setText(new Integer(140-length).toString());
			}
			
			@Override
			public void removeUpdate(DocumentEvent e) {
				update();
			}
			
			@Override
			public void insertUpdate(DocumentEvent e) {
				update();
			}
			
			@Override
			public void changedUpdate(DocumentEvent e) {
				update();
			}
		});
		
		JPanel panel = new JPanel();
		panel.setBounds(2, 135, 320, 30);
		contentPane.add(panel);
		panel.setLayout(null);
		
		button = new JButton("发布");
		button.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				WriteDialog.this.connection.post(textField.getText());
				WriteDialog.this.dispose();
			}
		});
		button.setBounds(220, 5, 57, 23);
		button.setEnabled(false);
		panel.add(button);

		JLabel label ;
		label = new JLabel("还可以输入");
		label.setBounds(25, 9, 60, 15);
		panel.add(label);
		
		counter = new JLabel("140");
		counter.setBounds(88, 9, 23, 15);
		panel.add(counter);
		
		label = new JLabel("个字。");
		label.setBounds(110, 9, 54, 15);
		panel.add(label);
		
		setContentPane(contentPane);

		setVisible(true);
	}

}

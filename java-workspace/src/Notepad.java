import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import javax.swing.BorderFactory;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFileChooser;
import javax.swing.JFrame;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.JToolBar;
import javax.swing.WindowConstants;

public class Notepad extends JFrame {
	
	private JTextArea textArea;

	private class openActionListener implements ActionListener {
		public void actionPerformed(ActionEvent e) {
			JFileChooser fileChooser = new JFileChooser();
			fileChooser.setDialogTitle("打开");
			if (fileChooser.showOpenDialog(Notepad.this) == JFileChooser.APPROVE_OPTION) {
				File file = fileChooser.getSelectedFile();
				try {
					FileReader fileReader = new FileReader(file);
					char[] buffer = new char[1024];
					int length;
					StringBuffer string = new StringBuffer();
					while ((length = fileReader.read(buffer)) != -1) {
						string.append(new String(Arrays.copyOfRange(buffer,0,length)));
					}
					textArea.setText(string.toString());
					fileReader.close();
				} catch (IOException ioe) {
				}
			}
		}
	}
	private class saveActionListener implements ActionListener {
		public void actionPerformed(ActionEvent e) {
			JFileChooser fileChooser = new JFileChooser();
			fileChooser.setDialogTitle("另存为");
			if (fileChooser.showSaveDialog(Notepad.this) == JFileChooser.APPROVE_OPTION) {
				File file = fileChooser.getSelectedFile();
				try {
					FileWriter fileWriter = new FileWriter(file);
					fileWriter.write(textArea.getText().toCharArray());
					fileWriter.close();
				} catch (IOException ioe) {
				}
			}
		}
	}
	private class quitActionListener implements ActionListener {
		public void actionPerformed(ActionEvent e) {
			Notepad.this.dispose();
		}
	}
	
	Notepad() {
		super("记事本");
		setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
		
		JMenuBar menuBar = new JMenuBar();
		JMenu fileMenu = new JMenu("文件(F)");
		JMenuItem newMenu = new JMenuItem("打开(O)");
		newMenu.addActionListener(new openActionListener());
		JMenuItem saveMenu = new JMenuItem("保存(S)");
		saveMenu.addActionListener(new saveActionListener());
		JMenuItem quitMenu = new JMenuItem("退出(X)");
		quitMenu.addActionListener(new quitActionListener());
		fileMenu.add(newMenu);
		fileMenu.add(saveMenu);
		fileMenu.add(quitMenu);
		menuBar.add(fileMenu);
		setJMenuBar(menuBar);

		JToolBar toolBar = new JToolBar();
		toolBar.setBorder(BorderFactory.createLineBorder(new Color(204,204,204)));
		JButton openButton = new JButton(new ImageIcon("icons/openFile.png"));
		openButton.addActionListener(new openActionListener());
		toolBar.add(openButton);
		JButton saveButton = new JButton(new ImageIcon("icons/saveFile.png"));
		saveButton.addActionListener(new saveActionListener());
		toolBar.add(saveButton);
		JButton quitButton = new JButton(new ImageIcon("icons/closeFile.png"));
		quitButton.addActionListener(new quitActionListener());
		toolBar.add(quitButton);
		getContentPane().add(toolBar,BorderLayout.NORTH);
		
		textArea = new JTextArea();
		JScrollPane scrollPane = new JScrollPane(textArea); 
		textArea.setEditable(true);
		getContentPane().add(scrollPane);
		
		setSize(800,600);
		setVisible(true);
	}
	
	public static void main(String[] args) {
		Notepad notepad = new Notepad();
	}
}

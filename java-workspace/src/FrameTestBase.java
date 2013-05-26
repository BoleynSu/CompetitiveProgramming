import java.awt.*;
import javax.swing.*;

class BgPanel extends JPanel {
    Image bg = new ImageIcon("login.png").getImage();
    @Override
    public void paintComponent(Graphics g) {
        g.drawImage(bg, 0, 0, getWidth(), getHeight(), this);
    }
}

class LoginPanel extends JPanel {
    LoginPanel() {
        setOpaque(false);
        setLayout(new FlowLayout());
        add(new JLabel("username: ")); add(new JTextField(10));
        add(new JLabel("password: ")); add(new JPasswordField(10));
    }
}

public class FrameTestBase extends JFrame {
    public static void main(String args[]) {
        JPanel bgPanel = new BgPanel();
        bgPanel.setLayout(new BorderLayout());
        bgPanel.add(new LoginPanel(), BorderLayout.CENTER);

        FrameTestBase t = new FrameTestBase();
        t.
		setUndecorated(true);
        t.setContentPane(bgPanel);
        t.setDefaultCloseOperation(EXIT_ON_CLOSE);
        t.setSize(250, 100);
        t.setVisible(true);
    }
}
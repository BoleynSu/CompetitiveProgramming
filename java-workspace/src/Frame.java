
import javax.swing.*;
import java.awt.*;

public class Frame extends JFrame {
private static final long serialVersionUID = -8718841593379704122L;
    

private JTextField field1,field2;
private JButton button1,button2,button3,button4,button5;
private JCheckBox check1,check2;
private JLabel label1,label2;
private JPanel panel1,panel2;
public Frame(){
label1=new JLabel("QQ号码");
label2=new JLabel("QQ密码",JLabel.CENTER);
button1=new JButton("申请号码");
button2=new JButton("安全");
button3=new JButton("设置");
button4=new JButton("登录");
button5=new JButton("忘了密码");
check1=new JCheckBox("自动登录");
check2=new JCheckBox("隐身登录",true);
field1=new JTextField(10);
field2=new JTextField(10);
button1.setPreferredSize(new Dimension(100,15));
button5.setPreferredSize(new Dimension(100,15));
Box q1=Box.createHorizontalBox();
Box q2=Box.createHorizontalBox();
Box q3=Box.createHorizontalBox();
Box w=Box.createVerticalBox();
q1.add(label1);
q1.add(Box.createHorizontalStrut(30));
q1.add(field1);
q1.add(Box.createHorizontalStrut(30));
q1.add(button1);
q2.add(label2);
q2.add(Box.createHorizontalStrut(30));
q2.add(field2);
q2.add(Box.createHorizontalStrut(30));
q2.add(button5);
q3.add(check1);
q3.add(Box.createHorizontalStrut(30));
q3.add(check2);
w.add(q1);
w.add(Box.createVerticalStrut(10));
w.add(q2);
w.add(Box.createVerticalStrut(10));
w.add(q3);
panel1=new JPanel();
panel1.add(w);
panel1.setBorder(BorderFactory.createLineBorder(Color.BLACK));

panel2=new JPanel(new FlowLayout(FlowLayout.CENTER));
panel2.add(button2);
panel2.add(button3);
panel2.add(button4);


getContentPane().setLayout(new BorderLayout());
getContentPane().add(panel1,BorderLayout.CENTER);
getContentPane().add(panel2,BorderLayout.SOUTH);
}
public static void main(String[] args) {
// TODO Auto-generated method stub
Frame frame=new Frame();
Toolkit kit=frame.getToolkit();
Dimension wndsize=kit.getScreenSize();
frame.setBounds(wndsize.width/4,wndsize.height/4,wndsize.width/2,wndsize.height/2);
frame.pack();
frame.setVisible(true);


}

}
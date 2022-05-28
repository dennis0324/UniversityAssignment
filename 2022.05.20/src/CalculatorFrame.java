import javax.swing.*;
import javax.swing.plaf.PanelUI;

import java.awt.*;

class NorthPanel extends JPanel{
    private JLabel search;
    private JTextField searchTextField;
    NorthPanel(){
        setLayout(new FlowLayout(FlowLayout.CENTER, 20, 20));
        search = new JLabel("검색");
        searchTextField = new JTextField(15);
        search.setFont(new Font("", Font.BOLD, 20));
        
        setBackground(Color.gray);
        add(search);
        add(searchTextField);
    }
}

class CenterPanel extends JPanel{
    private String[] btnName = {"CE","계산"};
    private String[] operator = {"+","-","x","/"};
    CenterPanel(){
        setLayout(new GridLayout(4,4,5,5));

        for(int i = 0; i < 10; i++){
            JButton btn = new JButton(Integer.toString(i));
            add(btn);
        }
        for(int i = 0; i < btnName.length; i++){
            JButton btn = new JButton(btnName[i]);
            add(btn);
        }
        for(int i = 0; i < operator.length; i++){
            JButton btn = new JButton(operator[i]);
            btn.setBackground(Color.cyan);
            add(btn);
        }
    }
}

class SouthPanel extends JPanel{
    private JLabel search;
    private JTextField searchTextField;
    SouthPanel(){
        setLayout(new FlowLayout(FlowLayout.LEFT, 20, 20));
        search = new JLabel("계산 결과");
        searchTextField = new JTextField("",15);
        setBackground(Color.yellow);
        search.setFont(new Font("", Font.BOLD, 20));

        add(search);
        add(searchTextField);
    }
}

public class CalculatorFrame extends JFrame {
    public CalculatorFrame(){
        super("계산기 프레임");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        Container c = getContentPane();
        c.setLayout(new BorderLayout());
        c.add(new NorthPanel(),BorderLayout.NORTH);
        c.add(new CenterPanel(),BorderLayout.CENTER);
        c.add(new SouthPanel(),BorderLayout.SOUTH);
        setSize(500,700);
        setVisible(true);

    }
    public static void main(String[] args) throws Exception {
        new CalculatorFrame();
    }


}

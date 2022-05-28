import javax.swing.*;
import java.awt.event.*;
import java.util.Random;
import java.awt.*;

public class RandomLocationApp extends JFrame {
    private JLabel label = new JLabel("C");
    private int width;
    private int height;
    public RandomLocationApp(){

        setTitle("클릭 연습 용 응용 프로그램");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        Container c = getContentPane();
        c.setLayout(null);
        c.add(label);

        label.setLocation(100, 100);
        label.setSize(10,10);
        label.addMouseListener(new CustomClickEvent());

        setSize(300,300);
        setVisible(true);
        this.width = c.getWidth();
        this.height = c.getHeight();
    }
    public static void main(String[] args){
        new RandomLocationApp();
    }

    class CustomClickEvent extends MouseAdapter{
        @Override
        public void mouseClicked(MouseEvent e) {
            JLabel label = (JLabel)e.getSource();
            Random random = new Random();
            int randomLocationX = random.nextInt(width - label.getWidth());
            int randomLocationY = random.nextInt(height - label.getHeight());
            label.setLocation(randomLocationX,randomLocationY);
        }
    }
}

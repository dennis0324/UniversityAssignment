import java.awt.Container;

import javax.swing.*;
import java.awt.event.*;
import java.awt.*;



public class App extends JFrame {


    public App(){
        
        setTitle("마우스 올리기");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        Container c = getContentPane();
        MyMouseListener myMouseListener = new MyMouseListener();
        c.setLayout(new FlowLayout());
        c.addMouseListener(myMouseListener);
        
        JLabel la = new JLabel("사랑해");
        c.add(la);
        setSize(250,250);
        setVisible(true);
    }

    public static void main(String[] args) throws Exception {
        new App();
    }

    class MyMouseListener extends MouseAdapter{
        @Override
        public void mouseEntered(MouseEvent e) {
            JLabel label = (JLabel)e.getSource();
            label.setText("사랑해");
            
        }

        @Override
        public void mouseExited(MouseEvent e) {
            JLabel label = (JLabel)e.getSource();
            label.setText("I love java");
        }
    
    }

}

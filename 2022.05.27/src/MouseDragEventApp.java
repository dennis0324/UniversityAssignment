
import javax.swing.*;
import java.awt.event.*;
import java.awt.*;


public class MouseDragEventApp extends JFrame{
    // private Container container;
    public MouseDragEventApp(){
        setTitle("드래깅동안 yellow로 변경");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        Container container = getContentPane();

        container.addMouseListener(new MyMouseListener());
        container.addMouseMotionListener(new MyMouseListener());

        container.setBackground(Color.GREEN);
        setSize(300,300);
        setVisible(true);
    }
    public static void main(String[] args){
        new MouseDragEventApp();
    }

    class MyMouseListener extends MouseAdapter{
        @Override
        public void mouseDragged(MouseEvent e) {
            Container container = (Container)e.getSource();
            container.setBackground(Color.YELLOW);
        }


        @Override
        public void mouseReleased(MouseEvent e) {
            Container container = (Container)e.getSource();
            container.setBackground(Color.GREEN);
        }
    }
}

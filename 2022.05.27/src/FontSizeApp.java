import javax.swing.*;
import java.awt.event.*;
import java.awt.*;

public class FontSizeApp extends JFrame {
    private int fontSize;
    private JLabel label = new JLabel("Love Java");

    private boolean isShiftPressed = false;

    public FontSizeApp(){
        setTitle("+,-키로 폰트 크기 조절");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        // font = new Font();
        fontSize = 10;
        label.setFont(new Font("SansSerif", Font.BOLD, fontSize));
        
        Container container = getContentPane();
        container.setLayout(new FlowLayout());
        container.add(label);
        container.addKeyListener(new CustomKeyEvent());

        setSize(300,300);
        setVisible(true);

        container.setFocusable(true);
        container.requestFocus();
    }

    class CustomKeyEvent extends KeyAdapter{
        @Override
        public void keyPressed(KeyEvent e) {
            System.out.println(e.getKeyCode());
            switch (e.getKeyCode()) {
                case 61:
                    if(isShiftPressed){
                        fontSize += 5;
                        label.setFont(new Font("SansSerif", Font.BOLD, fontSize));
                    }
                    break;
                case 45:
                    if(isShiftPressed){
                        if(fontSize >= 10){
                            fontSize -= 5;
                            label.setFont(new Font("SansSerif", Font.BOLD, fontSize));
                        }
                    }
                    break;
                case 16:
                    isShiftPressed = true;
                    break;
                default:
                    break;
            }
        }

        @Override
        public void keyReleased(KeyEvent e) {
            switch(e.getKeyCode()){
                case 16:
                    isShiftPressed = false;
                    break;
            }
        }
    }
    public static void main(String[] args){
        new FontSizeApp();
    }
}

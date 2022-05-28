import java.util.Random;
import java.util.Scanner;

class Lnk{
    Lnk next;
    int value;
    public Lnk(int num){
        value = num;
    }
    public void draw(){
        System.out.println("Lnk");
    }
}

class extend extends Lnk{
    public extend(int num){
        super(num);
    }
    public void draw(){
        System.out.println("Extend" + value);
    }
}
public class App {
    public static void main(String[] args){
        Random rand = new Random();
        Lnk lnk = new extend(rand.nextInt(5));
        Lnk p = lnk;
        for(int i = 0; i < 5; i++){
            p.next = new extend(rand.nextInt(5));
            p = p.next;
        }
        p = lnk;
        for(int i = 0; i < 5;i++){
            p.draw();
            p = p.next;
        }

    }
}

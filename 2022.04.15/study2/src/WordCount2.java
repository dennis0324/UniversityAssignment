import java.util.Scanner;

public class WordCount2 {
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);

        while(true){
            String line = scanner.nextLine();
            if(line.equals("그만"))
                break;
            String count[] = line.split(" ");
            System.out.println(count.length);
        }
        scanner.close();
    }
}

import java.util.Scanner;
import java.util.StringTokenizer;

public class wordCount {
    public static void main(String[] args) throws Exception {
        Scanner scanner = new Scanner(System.in);
        
        while(true){
            String input = scanner.nextLine();
            if(input.equals("그만")){
                System.out.println("종료합니다.");
                break;
            }
            StringTokenizer strToken = new StringTokenizer(input," ");
            System.out.println(strToken.countTokens());


        }
        scanner.close();
    }
}

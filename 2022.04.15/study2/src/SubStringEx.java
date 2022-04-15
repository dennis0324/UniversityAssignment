import java.util.Scanner;

public class SubStringEx {
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        String line = scanner.nextLine();
        for(int i = 0; i < line.length() - 1; i++){
            String frontLine  = line.substring(i+1, line.length());
            String subLine = line.substring(0, i+1);
            System.out.println(frontLine + subLine);
        }
        scanner.close();
    }
}

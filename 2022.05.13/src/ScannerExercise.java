import java.io.File;
import java.io.FileWriter;
import java.util.Scanner;

public class ScannerExercise {
    public static void main(String[] args) throws Exception {
        Scanner scanner = new Scanner(System.in);
        File file = new File("./test.txt");
        FileWriter fout = new FileWriter(file);
        while(true){
            String input;
            System.out.print("이름 전화번호>> ");
            input = scanner.nextLine();
            if(input.equals("그만")){
                break;
            }
            fout.write(input,0,input.length());
            fout.write("\r\n",0,2);
        }
        System.out.println(file.toString() + "에 저장되었습니다");
        fout.close();
        scanner.close();
    }
}

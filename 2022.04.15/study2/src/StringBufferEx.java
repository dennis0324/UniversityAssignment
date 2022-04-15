import java.util.Scanner;

public class StringBufferEx {
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        StringBuffer line = new StringBuffer(scanner.nextLine());

        while(true){
            String input = scanner.nextLine();
            if(input.equals("그만")){
                break;
            }
            String cmd[] = input.split("!"); 
            if(cmd.length < 2) {
                System.out.println("올바른 명령어가 아닙니다.");
                continue;
            }
            if(cmd[0].equals("")){
                System.out.println("올바른 명령어가 아닙니다.");
                continue;
            }
            int targetIndex = line.indexOf(cmd[0], 0);
            if(targetIndex == - 1){
                System.out.println("찾으시는 단어를 찾을 수 없습니다.");
                continue;
            }
            line = line.replace(targetIndex, targetIndex + cmd[0].length(), cmd[1]);
            System.out.println(line);
        }
        scanner.close();
    }

}

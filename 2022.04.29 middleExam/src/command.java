import java.util.Scanner;

public class command {
    
    public static void main(String[] args){
        System.out.print(">>");
        Scanner scanner = new Scanner(System.in);
        StringBuffer line = new StringBuffer(scanner.nextLine());

        while(true){
            System.out.print("명령(종료시 '그만'): ");
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
            System.out.println(cmd[1]);
            
            int startTargetIndex = line.indexOf(cmd[1], 0);
            if(startTargetIndex == - 1){
                System.out.println("찾으시는 단어를 찾을 수 없습니다.");
                continue;
            }
            int endTargeIndex = startTargetIndex + cmd[1].length();
            String reverse = "";
            if(cmd[0].equals("reverse")){

                for(int i = endTargeIndex - 1; i >= startTargetIndex ; i--){
                    reverse += line.charAt(i);
                }
                line.replace(startTargetIndex,endTargeIndex,reverse);
                System.out.println(line);
            }
            if(cmd[0].equals("delete")){
                char lastChar = line.charAt(endTargeIndex);
                if( lastChar == ' '){
                    endTargeIndex += 1;
                }
                line.replace(startTargetIndex,endTargeIndex,"");
                System.out.println(line);

            }
        }
        scanner.close();
    }

}

import java.util.Collections;
import java.util.Scanner;
import java.util.Vector;

public class biggest {
    public static void main(String[] args) throws Exception {
        Vector<Integer> vec = new Vector<>();
        Scanner scanner = new Scanner(System.in);
        System.out.print("정수(-1이 입력될 때까지)>> ");
        while(true){
            int input = scanner.nextInt();
            if(input == -1){
                break;
            }
            vec.add(input);
        }

        if(vec.size() == 0){
            System.out.println("정수가 아무것도 없습니다.");
            scanner.close();
            return ;
        }

        Collections.sort(vec,Collections.reverseOrder());
        
        System.out.println("가장 큰 수는 "+ vec.get(0));
        scanner.close();
    }
}

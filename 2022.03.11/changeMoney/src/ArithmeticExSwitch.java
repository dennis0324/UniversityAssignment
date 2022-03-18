import java.util.Scanner;

public class ArithmeticExSwitch {
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);

        System.out.print("연산식입력>>");
        int a = scanner.nextInt();
        String oper = scanner.next();
        int b =  scanner.nextInt();

        int result = 0;
        
        switch (oper){
            case "+":
                result = a + b;
                break;
            case "-":
                result = a - b;
                break;
            case "*":
                result = a * b;
                break;
            case "/":
                if(b == 0) {
                    System.out.println("0으로 나눌 수 없습니다.");
                    scanner.close();
                    return;
                }
                result = a / b;
                break;
            default:
                System.out.println("사칙연산만 지원합니다.");
                scanner.close();
                return;

        }
        System.out.println(a + oper + b + "의 계산결과는 " + result);
        scanner.close();
    }
}

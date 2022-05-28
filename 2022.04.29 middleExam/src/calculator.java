import java.util.InputMismatchException;
import java.util.Scanner;

public class calculator {
    public static void main(String[] args){
        int num1 = 0 , num2 = 0;
        String oper = "";
        int result = 0;
        Scanner scanner = new Scanner(System.in);
        while(true){
            System.out.print("연산(종료시: q)>> ");
            try{
                num1 = scanner.nextInt();
                oper = scanner.next();
                num2 = scanner.nextInt();
            }
            catch(InputMismatchException e){
                String temp = scanner.next();
                if(temp.equals("q")){
                    scanner.close();
                    return;
                }
                System.out.println("형식에 맞게 입력하세요.");
            }

            if(oper.equals("+")){
                result = num1 + num2;
            }
            else if(oper.equals("-")){
                result = num1 - num2;
            }
            else if(oper.equals("/")){
                if(num2 == 0){
                    System.out.println("0으로 나눌 수 없습니다.");
                    break;
                }
                result = num1 / num2;
            }
            else if(oper.equals("*")){
                result = num1 * num2;
            }
            else{
                System.out.println("사칙 연산을 기입해주세요.");
            }
            System.out.println(num1 + " " + oper + " " + num2 + " = " + result);
        }
        scanner.close();
    }
}

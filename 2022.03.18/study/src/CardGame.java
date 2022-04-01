import java.util.InputMismatchException;
import java.util.Scanner;

public class CardGame {
    //Y,y,N,n 값을 받기 위한 함수
    //scanner -> 메인 함수에서 사용하고 있는 스캐너 변수
    //answer -> 사용자가 입력한 문자
    public static boolean checkAnswer(Scanner scanner){
        String answer;
        while(true){
            answer = scanner.next();
            if(answer.toLowerCase().equals("n")) {
                return true;
            } else if(answer.toLowerCase().equals("y")){ 
                return false;
            }
            else System.out.println("Y,N,y,n 중 입력하세요");
        }
    }
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        int randomNum; //난수 값
        int high,low; //선택 범위 저장 값
        int count = 0; //추측 횟수
        int guessNum; //사용자 추측 숫자
        while(true){
            randomNum = (int)(Math.random() * 100); //난수 생성
            count = 0;
            high = 99; //최대 선택 수 초기화
            low = 0; //최소 선택 수 초기화
            System.out.println("수를 결정하였습니다. 맞추어 보세요.");
            while(true){
                System.out.println(low + "-" + high);
                System.out.print((count + 1)+ "번째 >>");
                try{
                    guessNum = scanner.nextInt(); //정수만을 받기 위한 try문
                }
                catch(InputMismatchException e){
                    scanner.nextLine();
                    System.out.println("1-100의 정수를 입력해주세요"); //정수가 아닐 경우 출력
                    continue;
                }
                if( guessNum > high || guessNum < low){
                    System.out.println("범위를 벗어났습니다.");
                }
                else{
                    if(randomNum > guessNum){ //난수 > 추측한 수
                        System.out.println("더 높게"); 
                        count++;
                        low = guessNum; //선택 범위 최댓값 수정
                    }
                    else if(randomNum < guessNum){//난수 < 추측한 수
                        System.out.println("더 낮게");
                        count++;
                        high = guessNum; //선택 범위 최댓값 수정
                    }
                    else{
                        break;
                    }
                }

            }
            System.out.println("맞았습니다.\n다시하시겠습니까(y/n)>>");
            if(checkAnswer(scanner)) { //y Y n N 이외의 문자를 받지 않기 위함
                break;
            } 
        }
        scanner.close();
    }
}

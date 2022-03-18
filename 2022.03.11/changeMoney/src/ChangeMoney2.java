import java.util.Scanner;

public class ChangeMoney2 {
    public static void main(String[] args) {
        //배열을 사용하여 for구문 사용을 원활하게 함
        int[] arr = {50000,10000,5000,1000,500,100,50,10,1};
        //받은 돈과 거스름돈 선언
        int money, change;
        System.out.print("금액을 입력하시오>>>");
        //스캐너 클래스 정의 및 초기화
        Scanner scanner = new Scanner(System.in);
        //입력받은 값으로 받은 돈 초기화
        money = scanner.nextInt();
        for(int i = 0; i < 9;i++){ //8가지의 돈이 있으니 8번 돌림
            change = money / arr[i]; //내야하는 돈
            if(change > 0)
                System.out.println(arr[i] + "원: " + change + "매"); //출력
            money %= arr[i];  //거스름돈
        }
        scanner.close(); //스캐너 닫기
    }
}

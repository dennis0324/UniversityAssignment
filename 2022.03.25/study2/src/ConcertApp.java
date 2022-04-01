import java.util.Scanner;

public class ConcertApp {
    Concert concert = new Concert("명품콘서트홀");
    Scanner scanner;

    ConcertApp(){
        scanner = new Scanner(System.in);
    }

    void reserve(){
        System.out.print("좌석 구분 S(1), A(2), B(3)>>");
        int select = scanner.nextInt();


    }

    void serach(){
        
    }

    void cancel(){

    }

    void run(){
        System.out.println(concert.getHallName()+" 예약 시스템입니다.");
        while(true){
            System.out.print("예약: 1 조회: 2 취소: 3 끝내기: 4 >>>");
            int select = scanner.nextInt();
            if(select == 1) reserve();
            else if(select == 2) reserve();
            else if(select == 3) reserve();
            else break;
        }
        scanner.close();
    }


}

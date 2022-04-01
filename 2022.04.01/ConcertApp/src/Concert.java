import java.util.Scanner;


public class Concert {
    private String hallName;
    private Scanner scanner;
    private Group[] groups = new Group[3]; //S, A, B

    public Concert(String hallName){
        this.hallName = hallName;
        this.scanner = new Scanner(System.in);
        groups[0] = new Group('S',10);
        groups[1] = new Group('A',10);
        groups[2] = new Group('B',10);
    }

    private void reserve(){
        System.out.print("좌석 구분 S(1), A(2), B(3) >>>");
        int type = scanner.nextInt();
        if( type < 1 || type > 3){
            System.out.println("잘못된 자석 타입입니다.");
            return;
        }
        groups[type - 1].reserve(scanner);
    }

    private void search(){
        for(int i = 0; i < groups.length; i++)
            groups[i].show();
        System.out.println("<<<조회를 완료하였습니다.>>>");
    }

    private void cancel(){
        System.out.println("좌석 S: 1 A: 2 b: 3>>>");
        int type = scanner.nextInt();
        if (type < 1 || type > 3){
            System.out.println("잘못된 좌석 타입입니다.");
            return;
        }

        groups[type - 1].cancel(scanner);
    }

    public void run(){
        System.out.println(hallName + "예약 시스템입니다.");
        int choice = 0;
        while(choice != 4){
            System.out.print("예약: 1, 조회: 2, 취소: 3, 끝내기: 4 >>>");
            choice = scanner.nextInt();

            switch(choice){
                case 1: //예약
                    reserve();
                    break;
                case 2: //조회
                    search();
                    break;
                case 3: //취소
                    cancel();
                    break;
                case 4: //끝내기
                    break;
                default:
                    System.out.println("잘못 입력하셨습니다.");
                    break;
            } //end of switch
        } //end of while
        scanner.close();
    }//end of run()

}

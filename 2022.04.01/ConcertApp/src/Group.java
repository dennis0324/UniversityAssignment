import java.util.Scanner;



public class Group {
    private Seat seats[];
    private char type;
    public Group(char type,int count){
        this.type = type;
        seats = new Seat[count];
        for(int i = 0; i< count;i++){
            seats[i] = new Seat();
        }
    }

    public boolean cancel(Scanner scanner){
        show();
        System.out.print("이름 >>>");
        String name = scanner.next();

        if(name != null){
            for(int i =0; i < seats.length; i++){
                if(seats[i].match(name)){
                    seats[i].cancel();
                    return true;
                }
            }
            System.out.println("예약자 이름을 찾을 수 없습니다.");
        }
        return false;
    }
    public void show(){
        System.out.println(type + ">>");
        for (int i = 0; i < seats.length; i++){
            if(seats[i].isOccupied())
                System.out.print(seats[i].getName());
            else
                System.out.print("---");
            System.out.print(" ");
        }
        System.out.println();
    }
    public boolean reserve(Scanner scanner){
        String name; //예약 이름
        int no; //예약 좌석번호

        show();
        System.out.print("이름>>>");
        name = scanner.next();

        System.out.print("번호>>>");
        no = scanner.nextInt();

        if(no < 1 || no >= seats.length){
            System.out.println("잘못된 좌석 번호입니다.");
            return false;
        }
        if(seats[no - 1].isOccupied()){
            System.out.println("이미 예약된 좌석입니다.");
            return false;
        }

        seats[no - 1].reserve(name);
        return true;
    }
}

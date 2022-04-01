import java.util.Scanner;

class Phone {
    private String name;
    private String tel;

    Phone(String name, String tel){
        this.name = name;
        this.tel = tel;
    }

    public String getName() {
        return name;
    }

    public String getTel() {
        return tel;
    }
}

public class Phonebook {
    private Phone[] pArr;
    private Scanner scanner;

    Phonebook(){
        scanner = new Scanner(System.in);
    }

    void run(){
        read();

        while(true){
            System.out.print("검색할 이름>>");
            String name = scanner.next();
            if(name.equals("그만")){
                break;
            }

            String tel = search(name);

            if(tel == null){
                System.out.println(name + " 이 없습니다.");
            }
            else{
                System.out.println(name + " 의 번호는 " + tel + " 입니다.");
            }


        }
        scanner.close();
    }

    String search(String name){
        for(int i = 0; i < pArr.length; i++){
            if(pArr[i].getName().equals(name)){
                return pArr[i].getTel();
            }
        }
        return null;
    }
    void read(){
        System.out.print("인원수 >>");
        int n = scanner.nextInt();
        pArr = new Phone[n]; //n개의 phone 객체 배열 선언

        for(int i = 0; i < n; i++){
            System.out.print("이름과 전화번호 입력>>>");
            String name = scanner.next();
            String tel = scanner.next();
            pArr[i] = new Phone(name,tel);    
        }
        System.out.println("저장되었습니다...");
    }

    public static void main(String[] args){
        new Phonebook().run();
    }
}

import java.util.ArrayList;
import java.util.Iterator;
import java.util.Scanner;


public class grade {
    public static void main(String[] args){
        double grade = 0;
        Scanner scanner = new Scanner(System.in);
        ArrayList<String> arrlist = new ArrayList<>();
        System.out.print("6개의 학점을 빈 칸으로 분리 입력(A/B/C/D/F)>> ");
        for(int i = 0; i< 6;i++){
            String temp = scanner.next();
            if(temp.length() != 1){
                System.out.println("학점이 아닙니다.");
                scanner.close();
                return;
            }
            char ch = temp.charAt(0);
            if((ch >= 'A' && ch < 'D') || ch == 'F' ){
                arrlist.add(temp);
            }
            else{
                System.out.println("invalid");
                scanner.close();
                return;
            }
        }

        Iterator<String> temp = arrlist.iterator();
        while(temp.hasNext()){
            String str = temp.next();
            switch(str){
                case "A":
                    grade += 4.0;
                    break;
                case "B":
                    grade += 3.0;
                    break;
                case "C":
                    grade += 2.0;
                    break;
                case "D":
                    grade += 1.0;
                    break;
                case "F":
                    grade += 0.0;
                    break;
                default:
                    break;                    
            }
            
        }
        System.out.println("평균점수는: " +(grade / 6));
        
        scanner.close();
    }

}

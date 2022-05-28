

public class game369 {
    public static void main(String[] args){
        
        for(int num = 1; num < 100; num++){
            int count = 0;
            int a,b;
            a = num / 10;
            b = num % 10;

            if( a!= 0 && a % 3 == 0)
                count++;
            if( b != 0 && b % 3 == 0)
                count++;

            if(count == 2){
                System.out.println(num + " 박수 짝짝");
            }
            else if(count == 1)
                System.out.println(num + " 박수 짝");
        }
    }
}
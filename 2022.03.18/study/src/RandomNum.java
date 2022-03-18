import java.util.Arrays;
import java.util.Scanner;

public class RandomNum {
    public static boolean exists(int a[],int i,int r){
        for (int j = 0; j < i; j++){
            if(a[j] == r) return true;
        }
        return false;
    }
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        int ranNum = 0;
        System.out.print("정수 몇개? >>");
        int repeatCount = scanner.nextInt();
        if(repeatCount <= 0 || repeatCount > 100){
            System.out.println("1-100 사이의 수를 입력하세요");
            scanner.close();
            return;
        }
        int arr [] = new int[repeatCount];
        boolean checkCalled [] = new boolean[100];
        Arrays.fill(arr,0);
        for(int i = 0; i < repeatCount; i++){
            ranNum = (int)(Math.random() * 100);
            if(checkCalled[ranNum] == false){
                arr[i] = ranNum + 1;
                checkCalled[ranNum] = true;
            }
        }

        for(int i = 0; i < repeatCount; i++){
            System.out.print(arr[i] + " ");
        }
        scanner.close();
    }
}

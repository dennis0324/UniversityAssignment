import java.util.HashMap;
import java.util.Scanner;

public class country {
    //1. hashmap 객체 생성 (key = String, value = integer)
    //2. scanner 객체 생성
    //3. 화면 출력
    //4. 무한 루프 나라와 인구수 입력받음 end 조건 = "그만"
    //4-1. hashmap에 국가와 인구 저장
    //5. 무한 루프 국가명 입력 받음
    //5-1. hashmap에서 국가명으로 인구수 검색
    //5-2. 검색결과가 있는 경우 오류처리
    //5-3. 검색 결과가 없는 경우 출력
    //6. close up
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        System.out.println("나라 이름과 인구를 입력하세요.(예: korea 50000)");
        HashMap<String,Integer> hash = new HashMap<>();
        while(true){
            System.out.print("나라 이름, 인구 >> ");
            String country = scanner.next();

            if(country.equals("그만")){
                break;
            }

            int population = scanner.nextInt();
            hash.put(country, population);

        }
        if(hash.size() == 0){
            System.out.println("입력 받은 값이 아무것도 없습니다.");
            scanner.close();
            return ;
        }
        while(true){
            System.out.print("인구 검색 >> ");
            String country = scanner.next();
            
            if(country.equals("그만")){
                break;
            }
            Integer result = hash.get(country);
            if(result == null){
                System.out.println(country +"(이)란 나라는 없습니다.");
                continue;
            }
            System.out.println(country + "의 인구는 " + result);

        }

        scanner.close();

    }
}

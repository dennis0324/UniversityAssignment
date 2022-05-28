#include <stdio.h>
#pragma warning(disable : 4996)
int recursive_prime_number(int num, int i){
    int result = 0;
    
    if (i <= 0) return 0;
 
    if (num % i == 0) result = 1;
    else result = 0;
 
    result += recursive_prime_number(num, i-1);
 
    return result;
}

int recursive_sumTotal(int n)
{
    if (n == 1)      // n이 1일 때
        return 1;    // 1을 반환하고 재귀호출을 끝냄

    return n + recursive_sumTotal(n - 1);    // n과 factorial 함수에 n - 1을 넣어서 반환된 값을 곱함
}

int recursive_power(int x, int n){
    if (n == 0) return 1;

    if ((n % 2) == 0)
        return recursive_power(x * x,n/2);
    else 
        return x * recursive_power(x * x, (n -1 ) / 2);
}

int recursive_gcd(int m, int n)
{ 
    if(n == 0) 
        return m; 
    else 
        return recursive_gcd(n, m%n); 
}

void print_menu(){
    printf("------------------------\n");
    printf("소수 찾기           :1\n");
    printf("1부터 n까지 더한 값 :2\n");
    printf("거듭제곱            :3\n");
    printf("최대 공약수         :4\n");
    printf("종료                :-1\n");
    printf("------------------------\n");

    printf("진행하고 싶은 연산을 입력하세요: ");

}
int main(){
    int select = 0;
    int num = 0;
    int num2 = 0;
    int result = 0;
    while(1){
        print_menu();
        scanf("%d",&select);
        switch (select)
        {
        case 1:
            printf("소수 찾기를 선택했습니다.\n");
            printf("1 ~ 100사이의 정수를 입력하세요: ");
            scanf("%d",&num);
            result = recursive_prime_number(num,num);
            if(result == 2) 
                printf("%d은 소수입니다.\n", num);        
            else        
                printf("%d은 소수가 아닙니다.\n", num); 
            break;
        case 2:
            printf("1부터 n까지의 합을 선택했습니다.\n");
            printf("n값을 입력하세요: ");
            scanf("%d",&num);
            result = recursive_sumTotal(num);
            printf("결과: %d\n",result);
            break;
        case 3:
            printf("거듭제곱을 선택했습니다.\n");
            printf("정수 n과 지수a를 입력하세요: ");
            scanf("%d %d",&num,&num2);
            if(num2 < 0){}
            printf("결과 %d\n",recursive_power(num,num2));
            break;
        case 4:
            printf("최대공약수를 선택했습니다.\n");
            printf("두 수를 입력하세요: ");
            scanf("%d %d",&num,&num2);
            result = recursive_gcd(num,num2);
            
            printf("결과: %d\n",result);
            break;
        default:
            if(select != -1)
                printf("메뉴에 나와있는 숫자만 눌러주세요");
            else
                return;
            break;
        }
    }
}
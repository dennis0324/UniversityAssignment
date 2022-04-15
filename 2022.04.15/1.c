#include <stdio.h>
#include "stack.h" //스택이 정의된 헤더 파일

int main(){
    stack_t s1; //스택 선언
    init(&s1);
    int count; //입력 받을 개수
    int temp; //스캔 받을 임시 변수
    printf("정수 배열의 크기:");
    scanf("%d",&count);
    printf("정수를 입력하시오: ");
    for(int i =0; i< count; i++){
        scanf("%d",&temp);
        push(&s1,temp);
    }

    printf("반전된 배열의 크기: ");
    for(int i =0; i < count; i++){
        printf("%d ",pop(&s1));
    }
}


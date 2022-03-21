/*
작성일: 2022.03.21
작성자: 고동현
프로그램명: 사칙연산 실행시간 비교 프로그램
프로그램설명: 알고리즘을 선택해서 원하는 답을 도출하기까지 걸리는 시간을 출력해주는 프로그램이다.
*/

#include <stdio.h>
#include <time.h>

int main(){
  char oper; //연산자
  long long num = 0; //반복하는 횟수 int의 최대 범위를 넘어가기 때문에 long long으로 정의해준다.
  float result; //초 결과
  long long i; //for구문 역시 반복하는 횟수가 int형의 최대 범위를 넘어가므로 long long으로 정의
  int mum1 = 20; //기본 연산용 숫자1
  int mum2 = 30; //기본 연산용 숫자1

  clock_t start, end; //clock()이라는 함수의 반환형은 clock_t라는 구조체 이기 때문에 시작과 끝점을 정의해준다.

  printf("연산을 입력하세요.(+,-,*,/):");
  scanf("%c",&oper); //연산자를 받는다.
  printf("반복할 횟수를 입력하시오: ");
  scanf("%lld",&num); //반복할 횟수를 받는다.

  switch (oper) //연산자로 switch문을 돌린다.
  {
  case '+': //+일 경우
    start = clock(); //카운터 시작
    for(i = 0; i < num; i++){
      result = mum1 + mum2;
    }
    end = clock(); //카운터 끝
    break;
  case '-': //-일 경우
    start = clock(); //카운터 시작
    for(i = 0; i < num; i++){
      result = mum1 - mum2;
    }
    end = clock(); //카운터 끝
    break;
  case '*': //*인 경우
    start = clock(); //카운터 시작
    for(i = 0; i < num; i++){
      result = mum1 * mum2;
    }
    end = clock(); //카운터 끝
    break;
  case '/': // /인 경우
    start = clock(); //카운터 시작
    for(i = 0; i < num; i++){
      result = mum1 / mum2;
    }
    end = clock(); //카운터 끝
    break;
  default: //사칙연산을 선택하지 않을 시 강제 종료함
    printf("사칙연산을 선태가히지 않아서 종료됩니다.");
    return 0;
    break;
  }
  result = (float)(end - start) / CLOCKS_PER_SEC; //단위가 ms이기 때문에 s로 바꿔주기 위해 정의되어 있는 상우인 CLOCK PER SEC으로 나눈다.
  printf("걸린 시간: %f",result);
}
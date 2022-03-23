/*
작성일: 2022.03.21
작성자: 고동현
프로그램명: 알고리름 선택 테스터기
프로그램설명: 알고리즘을 선택해서 원하는 답을 도출하기까지 걸리는 시간을 출력해주는 프로그램이다.
*/

#include <stdio.h>
#include <time.h>
/*
함수 이름:algorithm1
함수 설명: O(1)를 설명하기 위함
매개변수:
  n -> 숫자를 입력받아 제곱을 출력해준다.
반환값: n의 제곱 long long 형
*/

long long algorithm1(long long n){
  long long sum = n * n;
  return sum;
}
/*
함수 이름:algorithm2
함수 설명: O(n)를 설명하기 위함
매개변수:
  n -> 숫자를 입력받아 제곱을 출력해준다.
반환값: n의 제곱 long long형
*/
long long algorithm2(long long n){
  long long sum = 0;
  for(int i = 0; i < n; i++){
    sum = sum + n;
  }
  return sum;
}
/*
함수 이름:algorithm3
함수 설명: O(n^2)를 설명하기 위함
매개변수:
  n -> 숫자를 입력받아 제곱을 출력해준다.
반환값: n의 제곱 long long 형
*/
long long algorithm3(long long n){
  long long sum = 0;
  for(int i = 0; i < n; i++){
    for( int j = 0; j < n; j++){
      sum = sum + 1;
    }
  }
  return sum;
}


int main(){
  int algorithm = 0; //알고리즘 선택 수
  long long num = 0; //입력 값
  long long multiple; //곱한 값을 결과창
  clock_t start, end; //clock()이라는 함수의 반환형은 clock_t라는 구조체 이기 때문에 시작과 끝점을 정의해준다.
  printf("알고리즘을 선택하시오.(1,2,3):");
  scanf("%d",&algorithm); //알고리즘 번호 입력
  printf("숫자를 입력하시오: ");
  scanf("%lld",&num); //제곱할 수 입력

  switch (algorithm) //스위치 알고리즘 번호
  {
  case 1: 
    start = clock(); //타이머 시작
    multiple = algorithm1(num);
    end = clock(); //타이머 끝
    break;
  case 2:
    start = clock(); //타이머 시작
    multiple = algorithm2(num);
    end = clock(); //타이머 끝
    break;
  case 3:
    start = clock(); //타이머 시작
    multiple = algorithm3(num);
    end = clock(); //타이머 끝
    break;
  default:
    printf("1-3에서 선택하지 않아 종료합니다.");
    return 0;
    break;
  }
  float result = (float)(end - start) / CLOCKS_PER_SEC; //단위가 ms이기 때문에 s로 바꿔주기 위해 정의되어 있는 상수 인 CLOCK PER SEC으로 나눈다.
  printf("답: %lld",multiple);
  printf("걸린 시간: %f",result);
}
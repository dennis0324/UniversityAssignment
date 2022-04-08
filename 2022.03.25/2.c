#include <stdio.h>
#include <stdlib.h>

int factorial (int n){
    if( n == 1)
        return 1;
    return n * factorial(n - 1);
}
int power(int x,int n){
    if (n == 0) return 1;
    if ( n % 2 == 0){
        return power(x * x, n /2);
    }
    else return x * power(x* x, (n - 1) / 2);
}

int length(char * str){
    if (*str == '\0')
        return 0;
    else
        return 1 + length(str + 1);
}

void printStr(char * str){
    if (*str == '\0'){
        printf("\n",str);
        return 0;
    }
    else{
        return printStr(str + 1);
    }
        
}

void printReverseStr(char * str){
    if (*str == '\0'){
        return;
    }
    else{
        
        printReverseStr(str + 1);
        printf("%c",*str);
    }
}

int search(int data[], int n, int target){

    //data: 검색 대상 정수 배열
    //n : 배열 킈
    //target: 검색 숫자
    //return : 배열 인덱스, 검색 대산 숫자가 없으면 -1 리턴
    
}

int main(){

    // printf("factorial: %d",factorial(5));
    // printf("%d",power(2,5));
    // printStr("testing");
    printReverseStr("testing");
}
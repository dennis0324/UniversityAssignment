#include <stdio.h>
#include <stdlib.h>

void swap(int * a, int * b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    int count = 0; //입력 받은 숫자의 개수
    int input; //입력 받은 수 임시 변수
    int * arr; //동적 할당 변수
    FILE * fp = fopen("data3.txt","r");
    if (fp == NULL){
        printf("error\n"); //파일이 없을 경우 반환한다.
        return 0;
    }
    while(!feof(fp)){
        fscanf(fp,"%d",&input); //파일을 읽어드려서 EOF을 본 후 개수를 만들어준다.
        count++;
    }
    arr = (int *)malloc(sizeof(int) * count); //동적 배열 할당

    rewind(fp); //파일 포인터 위치를 다시 앞으로 이동 시켜준다.
    for(int i = 0; i< count; i++){
        fscanf(fp,"%d",&arr[i]); //파일을 읽는다.
    }

    printf("input array:\n");
    for(int i = 0; i < count; i++){
        (i != count - 1) ? printf("%5d",arr[i]) : printf("%5d\n",arr[i]); //마지막이 아니면 %5d로 출력하고 마지막이면 %5d\n으로 출력한다.
    }
    for(int i = count - 1; i > 0; i--){
        for(int  j = 0; j < i; j++){
            if(arr[j] >arr[j+1]) swap(&arr[j],&arr[j+1]); //두 수를 바꾸기 위함이다.
        }
    }
    printf("ouput array:\n");
    for(int i = 0; i < count; i++){
        (i != count - 1) ? printf("%5d",arr[i]) : printf("%5d\n",arr[i]);
    }
    fclose(fp);
    return 0;
}

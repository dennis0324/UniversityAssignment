#include <stdio.h>

int main(){
    int data[8][13];
    int average[9];
    FILE * fp;
    int count = 0;
    int sum;
    //파일 열기
    fp = fopen("data.txt","r");
    //비정상적 접근으로 인한 강제 종료
    if(fp == NULL){
        printf("파일을 찾을 수 없습니다.");
        return 0;
    }
    //eof 나올때까지 반복
    while(!feof(fp)){
        sum = 0;
        for(int i = 0; i < 12; i++){
            fscanf(fp,"%d",&data[count][i]);
            sum += data[count][i];
        }
        data[count][12] = sum; //더한 값을 마지막 배열에다가 바로 넣어준다.
        count++; //증가시킨다.
    }
    //for 구문의 순서를 바꿔서 열끼리의 합을 원활하게 해준다.
    count--;//count가 while문에서 1이 증가하여 나왔으므로 
    for(int i = 0; i < 12; i++){
        sum = 0;
        for(int j = 0; j < count; j++){
            sum += data[j][i];
        }
        average[i] = sum / (count + 1); //더한 값을 앞에서 카운트 했던 수 만큼 나눈다.
    }
    //기존 정보 출력
    printf("%7s","월:");
    for(int j = 0; j < 13; j++)
        (j >= 12)? printf("%15s\n","년별총합"):printf("%5d%s",j + 1,"월");
    //2차원 배열 출력
    for(int i = 0;i <count; i++){
        printf("%d년",2000 + i);
        for(int j = 0; j < 13; j++){
            printf("%7d",data[i][j]);
        }
        printf("\n");
    }
    //월평균 출력
    printf("평월균");
    for(int i = 0; i <12; i++){
        printf("%7d",average[i]);
    }
    printf("\n");
    return 0;
}
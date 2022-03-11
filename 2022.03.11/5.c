#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE * fp;
    int count = 0;
    int sum;
    //파일 열기
    fp = fopen("data.txt","r");
    //파일을 열지 못했을 시 비정상으로 인식후 프로그램 종료
    if(fp == NULL){
        printf("파일을 찾을 수 없습니다.");
        return 0;
    }
    //파일을 한번읽어서 전체 줄 파악
    while(!feof(fp)){
        if(fgetc(fp) == '\n'){
            count++;
        }
    }
    //더블 포인터 할당
    int ** dynamicArr = (int **)malloc(sizeof(int*) * (count + 1));
    for(int i = 0; i < count; i++){
        dynamicArr[i] = (int *)malloc(sizeof(int) * 4);
    }
    fseek(fp,0,SEEK_SET); //다시 파일포인터의 위치를 앞으로 옮겨준다.

    //값을 다시 받아준다.
    for(int i = 0; i < count; i++){
        for(int j = 0; j < 4; j++){
            fscanf(fp,"%d",&dynamicArr[i][j]);
        }
    }

    for(int i = 0; i <count; i++){
        //학번 국 영 수 총 평 순임
        sum = dynamicArr[i][1] + dynamicArr[i][2] + dynamicArr[i][2];
        printf("%8d: %8d %8d %8d %8d %8.4f\n",dynamicArr[i][0],dynamicArr[i][1],dynamicArr[i][2],dynamicArr[i][3],sum,sum / (double)3);
    }


    for(int i = 0;i < count; i++)
        free(dynamicArr[i]);
    free(dynamicArr);
    fclose(fp);
    return 0;
}
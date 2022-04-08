#include <stdio.h>
#define SIZE 100

int main(){
    int nAr[SIZE][SIZE];
    int transAr[SIZE][SIZE];

    int nTemp;
    char chTemp = '0';
    int nCount = 0;
    int nRow = 0;
    FILE *fp = fopen("data.txt","r");
    if(fp == NULL){
        printf("file can't open");
        return 0;
    }

    for( int i = 0; i < SIZE; i++){
        for( int j = 0; j < SIZE; j++){
            nAr[i][j] = -1;
            transAr[i][j] = -1;
        }   
    }

    while(!feof(fp)){
        if(chTemp == '\n')
            break;
        fscanf(fp, "%d%c",&nTemp, &chTemp);
        nCount++;
    }

    rewind(fp);
    //원본 해렬 2차원 배열에 파일 데이터 입력
    while (!feof(fp)){
        for (int i = 0; i< nCount; i++){
            fscanf(fp,"%d",&nAr[nRow][i]);
        }
        nRow++;
    }
    printf("원본 행렬을 출력\n");
    for(int i = 0; i< nRow; i++){
        for(int j = 0; j < nCount; j++){
            printf("%5d", nAr[i][j]);
        }
        printf("\n");
    }

    //전치 행렬 변환
    for(int i = 0; i < nRow; i++){
        for(int j =0; j < nCount; j++){
            transAr[j][i] = nAr[i][j];
        }
    }

    printf("전치 행렬을 출력\n");
    for(int i = 0; i< nCount; i++){
        for(int j = 0; j < nRow; j++){
            printf("%5d", transAr[i][j]);
        }
        printf("\n");
    }


    return 0;
}
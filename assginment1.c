#include <stdio.h>
#include <stdlib.h>

void printTitle(int num){
    for(int i =0; i<num; i++){
        printf("%8d",i + 1);
    }
    printf("\n");
}
void printLine(int num){
    for(int i =0; i<num; i++){
        printf("========",i);
    }
    printf("\n");
}
void printNums(int * arr, int count,int lineCount){

}

typedef struct 
{
    int * arr;
    int val;
    int count;
}NUMDATA;


int main(){
    FILE * fp;
    NUMDATA big;
    NUMDATA small;
    big.arr = (int * )malloc(sizeof(int)*1);
    small.arr = (int *)malloc(sizeof(int)*1);

    int count = 0;
    int lineCount = 0;
    int * arr = (int *)malloc(sizeof(int) * 1);
    int num;

    scanf("%d",&lineCount);

    fp = fopen("test.txt","r+");
    if(fp == NULL){
        printf("파일이 존재하지 않습니다.");
        return 0;
    }
    while(!feof(fp)){
        fscanf(fp,"%d",&num);
        if(count == 0){
            big.val = small.val = num;
            big.arr[0] = small.arr[0] = 0;
            big.count = small.count = 0;
        }
            
        count++;
        arr = (int *)realloc(arr,sizeof(int) * count );
        arr[count - 1] = num;

        if(num == big.val){
            big.count++;
            big.arr = (int *)realloc(big.arr,sizeof(int) * big.count);
            big.arr[big.count - 1] = count;
        }
        else if(num > big.val){
            big.val = num;
            big.count = 1;
            big.arr = (int *)realloc(big.arr,sizeof(int) * 1);
            big.arr[0] = count;
        }

        if(num == small.val){
            small.count++;
            small.arr = (int *)realloc(small.arr,sizeof(int) * small.count);
            small.arr[small.count - 1] = count;
        }
        else if(num < small.val){
            small.val = num;
            small.count = 1;
            small.arr = (int *)realloc(small.arr,sizeof(int) * 1);
            small.arr[0] = count;
        }

        // printf("%d\n",big.val);


    }

    printTitle(lineCount);
    printLine(lineCount);
    for(int i =0; i < count / lineCount + 1; i++){
        for(int j = 0; j < lineCount; j++){
            if(i * lineCount + j >= count) continue;
            printf("%8d",arr[i * lineCount + j]);
        }
        printf("\n");
        for(int j = 0; j < lineCount; j++){
            if(i * lineCount + j >= count) continue;
            int index = i * lineCount + j;
            int numResult = 0;
            for(int a = 0;a < small.count; a++){
                if(index == small.arr[a]) numResult = 1;
            }
            for(int a = 0;a < big.count; a++){
                if(index == big.arr[a]) numResult = 2;
            }

            if(numResult == 1){
                printf("%*s",11,"최솟값");
            }
            else if(numResult == 2){
                printf("%*s",11,"최댓값");
            }
            else{
                printf("%*s",8,"");
            }
        }
        printf("\n");
    }
 
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)
typedef struct point{
    int x;
    int y;
}Point_t;

int main(){
    int count; //카운트
    int a,b;

    FILE * fp = fopen("data.txt","r");
    if(fp == NULL){
        printf("file not found");
        return 0;
    }

    while(!feof(fp)){
        fscanf(fp,"%d %d",&a,&b);
        count++;
    }
    
    fseek(fp, 0, SEEK_SET);

    Point_t * arr = (Point_t *)malloc(sizeof(Point_t) * count);
    for(int i = 0; i < count; i++){
        fscanf(fp,"%d %d",&arr[i].x,&arr[i].y);
    }
    for(int i = 0; i < count;i++){
        if(arr[i].x > 0 && arr[i].y > 0){
            printf("%d %d는 %d사분면 입니다.\n",arr[i].x,arr[i].y,1);
        }
        else if(arr[i].x > 0 && arr[i].y < 0){ // + -
            printf("%d %d는 %d사분면 입니다.\n",arr[i].x,arr[i].y,2);
        }
        else if(arr[i].x < 0 && arr[i].y < 0){// - -
            printf("%d %d는 %d사분면 입니다.\n",arr[i].x,arr[i].y,3);
        }
        else if(arr[i].x < 0 && arr[i].y > 0){// - +
            printf("%d %d는 %d사분면 입니다.\n",arr[i].x,arr[i].y,4);
        }
    }

    free(arr);

    return 0;
}
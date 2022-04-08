#include <stdio.h>
int Is_ISBN(int isbn[]){
    int total =0;
    for( int i = 0; i < 13; i++){
        if( i % 2 == 1)
            total += isbn[i] * 3;
        else 
            total += isbn[i];
    }
    if (total % 10 == 0)
        return 1;
    else 
        return -1;
}
int main(){
    int nISBN[13];
    FILE * fp = fopen("data.txt","r");
    int nCount = 0;
    int nResult = 0;
    if(fp ==NULL){
        printf("file not found");
        return 0;
    }

    while(!feof(fp)){
        if(nCount > 13){
            printf("ISBN코드는 13자리입니다.");
            return 0;
        }
        fscanf(fp,"%d",&nISBN[nCount++]);
    }

    nResult = Is_ISBN(nISBN);

    for(int i = 0; i < 13; i++){
        printf("%d",nISBN[i]);
    }

    (nResult == -1) ? printf("은 유효하지 않는 ISBN입니다.\n") : printf("은 유효한 ISBN입니다.\n");
    
    return 0;
}
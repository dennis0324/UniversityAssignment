#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char * origin, char * reverse){
    int count = strlen(origin);
    int i;
    for(int i = 0; i < count; i++){
        *(reverse + i) = *(origin + count - i - 1);
    }
    *(reverse + count) = '\0';
}

int main(){

    FILE * fp;
    char* name;
    char* result;
    int count = 0;

    fp = fopen("data1.txt","r");
    if(fp == NULL){
        return 0;
    }
    while(!feof(fp))
    {
        fgetc(fp);
        count++;
    }
    name = (char *)malloc(count);
    result = (char *)malloc(count);
    rewind(fp);
    for( int i = 0; i < count; i++){
        fscanf(fp,"%c",&name[i]);
    }

    swap(name,result);

    printf("뒤집은 이름은 %s",result);
    fclose(fp);

    return 0;
    
}
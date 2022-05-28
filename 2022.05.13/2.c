#include <stdio.h>
#include "linkArray.h"

int main(){
    FILE * fp = fopen("data.txt","r");
    if(fp == NULL){
        printf("file not found");
        return 0;
    }
    ListType list;
    init(&list);
    int count = 0;
    int temp_value;

    while(!feof(fp)){
        fscanf(fp,"%d",&temp_value);
        // printf("%d",temp_value);
        add_last(&list,temp_value);

    }
    print_list(list.head);

    // print_list(list);
    return 0;
}
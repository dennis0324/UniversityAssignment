#include <stdio.h>
#include "linkArray.h"

int main(){
    int count = 0;
    int total = 0;
    ListType list;
    init(&list);
    printf("노드의 개수: ");
    scanf("%d",&count);
    int temp = 0;

    for(int i = 0; i< count;i++){
        printf("노드 #%d 데이터 : ",i + 1);
        scanf("%d",&temp);
        add_last(&list,temp); 
    }

    for(ListNode * p = list.head; p != NULL; p = p->link){
        total += p->data;
    }

    printf("연결 리스트의 데이터 합: %d\n",total);
    clear(&list);
    return 0;
}
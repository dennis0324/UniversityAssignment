#include <stdio.h>
#include "linkArray.h"


int main(){
    int count = 0;
    int total = 0;
    int input;
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

    count = 0;
    printf("탐색할 값을 입력하시오: ");
    scanf("%d",&input);
    for(ListNode * p = list.head; p != NULL; p = p->link){
        if(input == p->data){
            count++;
        }
    }

    
    printf("%d는 연결 리스트에서  %d번 나타납니다.\n",input,count);
    clear(&list);
    return 0;
}
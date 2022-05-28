#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node * link;
} ListNode;

typedef struct {
    ListNode * head;
    int length;
} ListType;


void init(ListType * list){
    if(list == NULL) return;
    list->head = NULL;
    list->length = 0;
}

int get_length(ListType * list){
    return list->length;
}

ListNode * get_node_at(ListType * list,int pos){
    ListNode * p = list->head;
    if(list->length < pos || pos < 0) return NULL;
    for(int i = 0; i < pos; i++){
        p = p->link;
    }
    return p;
}


void insert(ListNode** head,ListNode* pre, ListNode * new_node){
    if(*head == NULL){
        new_node->link = NULL;
        *head = new_node;
    }
    else if(pre ==NULL){
        new_node->link = *head;
        *head = new_node;
    }
    else{
        new_node->link = pre->link;
        pre->link = new_node;

    }
}

ListNode * delete_(ListNode* head,ListNode * pre){
    ListNode* removed;
    if(head == NULL){ //head
        return NULL;
    }
    else if(pre == head){
        removed = head;
        head = removed->link;
    }
    else{
        removed = pre->link;
        pre->link = removed->link;

    }

    free(removed);
    return head;
}

void print_list(ListNode * head){
    for(ListNode *p=head;p != NULL;p = p->link){
        printf("%d ->",p->data);
    }
    printf("NULL\n");
}


void add(ListType * list, int pos,int value){
    ListNode * pre;
    if((list->length > pos) || (pos < 0)){
        fprintf(stderr,"out of index");
        exit(0);
    }
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    if( node == NULL){
        fprintf(stderr,"allocation error");
        exit(0);
    }
    node->data = value;
    pre = get_node_at(list,pos - 1);
    insert(&(list->head),pre,node);
    list->length++;

}
void add_first(ListType * list,int value){
    add(list,0,value);
}

void add_last(ListType * list, int value){
    add(list,get_length(list),value);
}

void remove_(ListType * list, int pos){
    ListNode * pre = get_node_at(list,pos);
    list->head = delete_((list->head),pre);
}
void remove_first(ListType * list){
    remove_(list,0);
}
void remove_last(ListType * list){
    remove_(list,get_length(list));
}

void clear(ListType * list){
    ListNode * removed_link;
    for(ListNode * p = list->head; p->link !=NULL;p = removed_link){
        removed_link = p->link;
        free(p);
    }
}


void printSequence(ListType * list){
    printf("1. 연결 리스트 출력: ");
    print_list(list->head);
}

void printCount(ListType * list){
    printf("2. 연결 리스트 노드의 개수 = %d\n",get_length(list));
}

void printSum(ListType * list){
    int total = 0;
    for(ListNode * p = list->head; p != NULL; p = p->link){
        total += p->data;
    }
    printf("3. 연결 리스트의 데이터 합: %d\n",total);
}

void printDuplicate(ListType * list){
    int input;
    int count = 0;
    printf("탐색할 값을 입력하시오: ");
    scanf("%d",&input);
    for(ListNode * p = list->head; p != NULL; p = p->link){
        if(input == p->data){
            count++;
        }
    }

    printf("4. %d는 연결 리스트에서  %d번 나타납니다.\n",input,count);
}


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

    printSequence(&list);
    printCount(&list);
    printSum(&list);
    printDuplicate(&list);

    clear(&list);
    return 0;
}


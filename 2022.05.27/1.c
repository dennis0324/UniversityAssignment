#include <stdio.h>
#include <stdlib.h>
#ifndef DOUBLEARRAYLIST
    #define DOUBLEARRAYLIST
    #include <stdio.h>
    #include <stdlib.h>
#endif

typedef struct dList_Node{
    int data;
    struct dList_Node* llink;
    struct dList_Node* rlink;
}DListNode;

DListNode * createDList(){
    DListNode * head;
    init(head);
    return head;
}

void init(DListNode * pHead){
    pHead->data = 0;
    pHead->llink = pHead->rlink = pHead;
}

void dinsert(DListNode * before, int data){
    DListNode * node = (DListNode *)malloc(sizeof(DListNode));
    node->data = data;
    node->llink = before;
    node->rlink = before->rlink;
    before->rlink->llink = node;
    before->rlink = node;
}

void ddelete(DListNode * head,DListNode * removed){
    if(removed == head) return;
    removed->llink->rlink = removed->rlink;
    removed->rlink->llink = removed->llink;
    free(removed);
}

void dclear(DListNode * phead){
    DListNode * p;
    for(p = phead->rlink; p != phead; p = p->rlink){
        free(p);
    }
    free(phead);
}
void print_dlist(DListNode * phead){
    DListNode * p;
    for(p = phead->rlink; p != phead; p = p->rlink){
        printf("<-| |%d| |->",p->data);
    }
    printf("\n");
}




int main(){
    DListNode * head = (DListNode *)malloc(sizeof(DListNode));
    init(head);
    printf("추가 단계\n");
    for(int i = 0; i < 5; i++){
        //헤드 노드의 오른쪽에 삽입
        dinsert(head,i);
        print_dlist(head);
    }

    printf("\n삭제 단계\n");
    for(int i = 0; i < 5;i++){
        print_dlist(head);
        ddelete(head,head->rlink);
    }
    free(head);
    return 0;
}

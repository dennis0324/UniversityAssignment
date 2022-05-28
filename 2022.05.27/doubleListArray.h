#ifndef DOUBLEARRAYLIST
    #define DOUBLEARRAYLIST
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
#endif

typedef struct dList_Node{
    char data[30];
    struct dList_Node* llink;
    struct dList_Node* rlink;
}DListNode;

void createDList(DListNode * testing){
    testing = (DListNode *)malloc(sizeof(DListNode));
}

void dinit(DListNode * pHead){
    pHead->llink = pHead;
    pHead->rlink = pHead;
}

void dinsert(DListNode * before, char* data){
    DListNode * node = (DListNode *)malloc(sizeof(DListNode));
    strcpy(node->data,data);
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




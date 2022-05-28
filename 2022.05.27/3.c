#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student_data
{
    int id;
    char name[30];
    int scores[3];
}StudentData;

typedef struct dList_Node{
    StudentData data;
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

void dinsert(DListNode * before, StudentData data){
    DListNode * node = (DListNode *)malloc(sizeof(DListNode));
    memcpy(&(node->data),&data,sizeof(DListNode));
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
    printf("%-11s %-11s %-11s %-11s %-11s\n","번호","이름","국어","영어","수학");
    DListNode * p;
    for(p = phead->rlink; p != phead; p = p->rlink){
        printf("%-10d",p->data.id);
        printf("%-10s",p->data.name);
        for(int i = 0; i< 3; i++){
            printf("%-10d",p->data.scores[i]);
        }
        printf("\n");
    }
}


void addStudent(DListNode * phead){
    StudentData data;
    printf("학번 :");
    scanf("%d",&data.id);
    printf("이름 :");
    scanf("%s",data.name);
    printf("국어 성적 :");
    scanf("%d",&data.scores[0]);
    printf("영어 성적 :");
    scanf("%d",&data.scores[1]);
    printf("수학 성적 :");
    scanf("%d",&data.scores[2]);

    dinsert(phead,data);
}

void deleteStudent(DListNode * phead){
    int input;
    DListNode * p;
    printf("삭제할 학생 번호");
    scanf("%d",&input);
    for(p = phead->rlink; p != phead; p = p->rlink){
        if(input == p->data.id){
            ddelete(phead,p);
            printf("삭제되었습니다.\n");
            return;
        }
    }
    printf("학생 번호를 찾을 수 없니다.\n");
}

void searchStudent(DListNode * phead){
    int input;
    DListNode * p;
    printf("검색할 학생 번호");
    scanf("%d",&input);
    for(p = phead->rlink; p != phead; p = p->rlink){
        if(input == p->data.id){
            printf("학번: %d\n",p->data.id);
            printf("이름: %s\n",p->data.name);
            printf("국어 점수: %d\n",p->data.scores[0]);
            printf("영어 점수: %d\n",p->data.scores[1]);
            printf("수학 점수: %d\n",p->data.scores[2]);
            return;
        }
    }
    printf("학생 번호를 찾을 수 없니다.\n");
}

int main(){
    int input;
    char inputdata[30];
    DListNode * list = (DListNode *)malloc(sizeof(DListNode));
    dinit(list);
    do{
        printf("성적 관리 프로그램(0: 종료, 1: 추가, 2: 삭제, 3: 학생 검색 4: 목록 보기): ");
        scanf("%d",&input);
        switch (input)
        {
        case 1:
            addStudent(list);
            break;
        case 2:
            deleteStudent(list);
            break;
        case 3:
            searchStudent(list);
            break;
        case 4:
            print_dlist(list);
            break;
        default:
            break;
        }

    }while(input != 0);
}




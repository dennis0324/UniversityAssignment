#include <stdio.h>
#include "stack.h"
#include <string.h>

/*
(2+3)*4+9
(1+5)*(3-2)
5*2+3+(4-2)
*/
int prec(char op){
    switch (op)
    {
    case '(':
    case ')':
        return 0;
        break;
    case '+':
    case '-':
        return 1;
        break;
    case '*':
    case '/':
        return 2;
        break;
    default:
        break;
    }
}
void infix_to_postfix(char * buf){
    stack_t s1;
    init(&s1);
    int length = strlen(buf);
    char top_op;
    char ch;
    for(int i =0; i < length; i++){
        ch = buf[i];

        switch (ch)
        {
        case '+':
        case '-':
        case '/':
        case '*':
            while(!is_empty(&s1) && (prec(ch) <= prec(peek(&s1))))
                printf("%c",pop(&s1));
            push(&s1,ch);
            break;
        case '(':
            push(&s1,ch);
            break;
        case ')':
            top_op = pop(&s1);
            //왼쪽 괄호를 만들때까지 반복
            while( top_op != '(') {
                printf("%c",top_op);
                top_op = pop(&s1);
            }
            break;
        
        default: //피연산자
            printf("%c",ch);
            break;
        }
    }

    while(!is_empty(&s1)){
        printf("%c",pop(&s1));
    }
    printf("\n");

}
int main(){
    char buf[1024];
    FILE * fp = fopen("data.txt","r");
    if(fp == NULL){
        printf("file not found");
        return 0;
    }

    while(!feof(fp)){
        fscanf(fp,"%s",buf);
        infix_to_postfix(buf);
    }
    return 0;
}
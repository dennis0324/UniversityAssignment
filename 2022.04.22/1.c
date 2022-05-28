#include <stdio.h>
#include "stack.h"
#include <string.h>

/*
{A[(i+1)]=0}
{B[100-(i+5)]*5}
{C/(5/5*(5-4)}
(10+5)-(30-20)
*/
int check_matching(char * buffer){
    stack_t stack1;
    init(&stack1);
    int length = strlen(buffer);
    char ch,pop_ch;
    for(int i = 0; i < length; i++){
        ch = buffer[i];
        switch (ch)
        {
        case '{':
        case '(':
        case '[':
            push(&stack1,ch);
            break;
        case '}':
        case ')':
        case ']':

            if(is_empty(&stack1)){
                return 0;
            }
            else{
                pop_ch = pop(&stack1);
                if(((pop_ch == '{') && (ch != '}')) |
                ((pop_ch == '(') && (ch != ')')) |
                ((pop_ch == '[') && (ch != ']')))
                    return 0;
            }

            break;
        default:
            break;
        }
    }
    if(!is_empty(&stack1))
        return 0;

    return 1;
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
        if(check_matching(buf) == 1){
            printf("괄호 검사 성공: %s\n",buf);
        }
        else{
            printf("괄호 검사 실패: %s\n",buf);
        }
    } 
}

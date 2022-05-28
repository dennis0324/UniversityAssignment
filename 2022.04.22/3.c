#include <stdio.h>
#include "stack.h"
#include <string.h>
/*
23+4*9+
15+32-*
52*3+42-+
*/
int sum_postfix(char * buf){
    int length = strlen(buf);
    stack_t s;
    init(&s);
    char ch;
    int first, second;
    int num;
    for(int i = 0; i < length; i++){
        ch = buf[i];
        if(ch != '+' && ch != '-' && ch != '*' && ch != '/' ){
            num = ch - '0';
            push(&s,num);

        }
        else{
            second = pop(&s);
            first = pop(&s);
            switch (ch)
            {
            case '+':
                push(&s,first + second);
                break;
            case '-':
                push(&s,first - second);
                
                break;
            case '*':
                push(&s,first * second);
                
                break;
            case '/':
                if(second == 0)
                    printf("zero divsion");
                else{
                    push(&s,first / second);
                }

                break;
            default:
                break;
            }
        }
    }
    return pop(&s);
}

int main(){
    FILE * fp = fopen("data.txt","r");
    char buf[1024];
    int result;
    if(fp == NULL){
        printf("can't find file");
        return 0;
    }

    while(!feof(fp)){
        fscanf(fp,"%s",buf);
        result = sum_postfix(buf);
        printf("%s\n result: %d\n",buf,result);
    }
}
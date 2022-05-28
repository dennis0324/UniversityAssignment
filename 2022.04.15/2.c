#include <stdio.h>
#include <string.h>
#include "stack.h"

int check_matching(char * in){
    stack_t s;
    init(&s);
    char ch;
    int pnumber = 0; //출력할 숫자
    int n = strlen(in); //문자열 길이
    int open_ch;
    for(int i= 0; i < n; i++){
        ch = in[i];
        switch (ch)
        {
        case '(':
        case '[':
        case '{':
            printf("%d",++pnumber);
            push(&s,ch);
            break;
        case ')':
        case ']':
        case '}':
            if(is_empty(&s))
                return 0;
            else{
                printf("%d",pnumber--);
                open_ch = pop(&s);
                if((open_ch == '(' && ch != ')') ||
                (open_ch == '[' && ch != ']') ||
                (open_ch == '{' && ch != '}'))
                return 0;
            }
            break;
        default:
            break;
        }
    }
    if(!is_empty(&s))
        return 0;
    return 1;
}

int main(){
    char line[MAX];

    stack_t s1;
    init(&s1);
    char input;
    int num = 1;

    printf("수식: ");
    gets(line,100); //string으로 전부를 읽는다.``
    if(check_matching(line)){
        printf("\ntrue\n");
    }
    else
        printf("\nfalse\n");

    return 0;
}
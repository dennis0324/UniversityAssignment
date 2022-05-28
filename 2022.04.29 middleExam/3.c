#include <stdio.h>

#define MAX 100
#pragma warning(disable : 4996)

typedef struct
{
    int top;
    int arr[MAX];
}stack_t;

void init(stack_t * stack1){
    stack1 ->top = -1;
}
int is_full(stack_t * stack){
    if(stack ->top == MAX - 1){
        return 1;
    }
    return 0;
}
int is_empty(stack_t * stack){
    if(stack ->top <= -1){
        return 1;
    }
    return 0;
}
void push(stack_t * stack, int val){
    if(is_full(stack)){
        fprintf(stderr,"stack is full");
    }
    stack -> arr[++(stack->top)] = val;
}

int pop(stack_t * stack){
    if(is_empty(stack)){
        fprintf(stderr,"stack is empty");
    }
    return stack->arr[(stack->top)--];
}

int peek(stack_t * stack){
    if(is_empty(stack)){
        return -1;
    }
    return stack->arr[(stack->top)];
}

int main(){
    stack_t s;
    init(&s);
    unsigned long long input;
    int temp;
    printf("정수를 입력하세요: ");
    scanf("%lld",&input);

    while(input != 0){
        temp = input % 10;
        if(peek(&s) != temp){
            push(&s,temp);
        }
        input /= 10;
    }

    printf("결과: ");
    while(!is_empty(&s)){
        printf("%d",pop(&s));
    }
    printf("\n");
    return 0;

}
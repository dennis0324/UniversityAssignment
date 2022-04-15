#define MAX 100
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
    if(stack ->top == -1){
        return 1;
    }
    return 0;
}
void push(stack_t * stack, int val){
    if(is_full(stack)){
        fprintf(stderr,"out of index");
        exit(1);
    }
    stack -> arr[++(stack->top)] = val;
}

int pop(stack_t * stack){
    if(is_empty(stack)){
        fprintf(stderr,"stack empty!");
        exit(1);
    }
    return stack->arr[(stack->top)--];
}
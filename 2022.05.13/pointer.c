#include <stdio.h>
#include <stdlib.h>
typedef struct a
{
    int a;
} s;

void testing(s** a){
    printf("%s","testing");

    printf("%p",a);

}
int main(){
    
    s * p1 = (s *)malloc(sizeof(s));
    printf("%p",p1);
    testing(p1);
    s * p2 = (int *)malloc(sizeof(int));
    s * p3 = (int *)malloc(sizeof(int));

}
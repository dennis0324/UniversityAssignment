#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 101

typedef struct{
    float coef;
    int expon;
}polynomial;

polynomial terms[MAX_TERMS] = {{8,3},{7,1},{1,0},{10,3},{3,2},{1,0}};
int avail = 6;

char compare(int a, int b){
    if (a > b) return '>';
    else if(a == b) return '=';
    else return '<';
}

void attach(float coef, int expon){
    if(avail > MAX_TERMS){
        fprintf(stderr,"항의 개수가 너무 많음\n");
        exit(1);
    }
    terms[avail].coef = coef;
    terms[avail].expon = expon;
    avail++;
}

void poly_add(int As,int Ae,int Bs,int Be,int* Cs,int* Ce){
    float tempcoef;
    *Cs = avail;
    while(As <= Ae && Bs <= Be){
        switch(compare(terms[As].expon,terms[Bs].expon)){
            case '>':
                attach(terms[As].coef,terms[As].expon);
                As++;
            case '=':
                tempcoef = terms[As].coef + terms[Bs].coef;
                if(tempcoef)
                    attach(tempcoef,terms[As].expon);
                As++;
                Bs++;
                break;
            case '<':
                attach(terms[Bs].coef,terms[Bs].expon);
                Bs++;
                break;
        }
    }

    for(;As<= Ae;As++){
        attach(terms[As].coef,terms[As].expon);
    }
    for(;Bs <= Be;Bs++){
        attach(terms[Bs].coef,terms[Bs].expon);
    }
    *Ce = avail - 1;
}
void print_poly(int start, int end){
    for(int i = start; i < end; i++){
        printf("%3.1fx^%d +",terms[i].coef,terms[i].expon);
    }
    printf("%3.1f\n",terms[end].coef);

}
int main(){
    int startA = 0, endA = 2, startB = 3, endB = 5,startC,endC;
    poly_add(startA,endA,startB,endB,&startC,&endC);
    print_poly(startA,endA);
    print_poly(startB,endB);
    printf("다항식의 합\n");
    print_poly(startC,endC);
    return 0;
}
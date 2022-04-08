#include <stdio.h>
#define MAX_DEGREE 100
typedef struct {
    int degree;
    float coef[MAX_DEGREE];
}polynomial;


int compare(int a,int b){
    if( a > b){
        return 0;
    }
    return 1;
}

int print_poly(polynomial p){
    for(int i = p.degree; i > 0;i--){
        printf("%3.1fx^%d +",p.coef[p.degree - i],i);
    }
    printf("%3.1f\n",p.coef[p.degree]);
}

polynomial poly_add(polynomial a,polynomial b){
    polynomial c;
    int Apos = 0, Bpos =0, Cpos = 0;
    int degree_a = a.degree;
    int degree_b = b.degree;

    if(degree_a > degree_b)
        c.degree = a.degree;
    else
        c.degree = b.degree;

    while(Apos <= a.degree && Bpos <= b.degree){
        if(degree_a > degree_b){
            c.coef[Cpos++] = a.coef[Apos++];
            degree_a--;
        }
        else if (degree_a == degree_b){
            c.coef[Cpos++] = a.coef[Apos++] + b.coef[Bpos++];
            degree_a--;
            degree_b--;
        }
        else{
            c.coef[Cpos++] = b.coef[Bpos++];
            degree_b--;
        }
    }

    return c;
}
int main(){
    polynomial a = {5,{10,0,0,0,6,3}};
    polynomial b = {4,{7,0,5,0,1}};
    polynomial c;

    print_poly(a);
    print_poly(b);
    c = poly_add(a,b);
    print_poly(c);
    return 0;    
}



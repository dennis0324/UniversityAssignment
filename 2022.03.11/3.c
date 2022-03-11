#include <stdio.h>

int main(){
    int array[3] = {10,20,30};

    printf("%8x %8x %8x \n",array, array + 0, &array[0]);
    printf("         %8x %8x \n",array + 1, &array[1]);
    printf("         %8x %8x \n",array + 2, &array[2]);
    printf("%8d %d %d \n",sizeof(array), sizeof(array + 0), sizeof(&array[0]));

    printf("%d %d",sizeof(int),sizeof(int *));


    return 0;
}
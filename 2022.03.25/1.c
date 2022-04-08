#include <stdio.h>
#include <time.h>

void O1 (){
    int array[] = {0,1,2,3,4,5,6};
    array[0] = array[1];
}

int OlogN(){
    int arr[10000] = {0};
    int low = 0;
    int i;
    for (i = 0; i < 10000; i++){
        arr[i] = i;
    }

    int high = (sizeof(arr) / sizeof(int)) - 1;
    int mid, search = 1;

    while (low <= high){
        mid = (high + low) /2;

        if( arr[mid] < search)
            return mid;
        else if (arr[mid] < search)
            low = mid + 1;
        else
            high = mid - 1;
        
    }

    return -1;
}

int ON2(int num) {
    if (num == 0)
        return 0;
    else if (num == 1)
        return 1;
    else
        return O2n(num -1 ) + (num -2);
}

int O2N(){

}

int main(){
    clock_t start,end;
    float res;

    start = clock();
    O1();
    end = clock();
    res = (float)(end -start);
    printf("\n\nO(1) 소요시간 : %.3f\n", res);


    start = clock();
    OlogN();
    end = clock();
    res = (float)(end -start);
    printf("\n\nO(logN) 소요시간 : %.3f\n", res);

}
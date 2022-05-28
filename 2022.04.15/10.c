int main(){
    int arr[]={10,20,30,40,50,60,70,80,90,100};
    int * ptr1 = arr;
    int * ptr2 = &arr[3]
    ;

    int temp = *(++ptr1) - ((*ptr2)++);

    printf("%d\n",temp);


    for(int i = 0; i < 5;i++){
        *ptr2 += 2;
        printf("%d ",*ptr2);
    }

    
    for(int i = 0; i< 5; i++){
        printf("%d ",*ptr1);
        ptr1 +=2;
    }
}
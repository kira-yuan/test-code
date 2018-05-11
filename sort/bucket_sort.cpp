#include <stdio.h>


int bucket_sort( int array[], int length );

int  main(){

    //int arr[10] = {12,2,3,6,14,99,45,6,3,23,34,77,56,86,63,52,55,66,88,9,44,33,34,55,66,33,96};
    int arr[10] = {9,2,3,6,1,6,7,3,4,8};

    int i;
    for( i=0; i<10; i++ ){
        printf("%d  ", arr[i]);
    }
    printf("\n");

    bucket_sort( arr, 10 );    
    printf("\n====sorted:\n");

    for( i=0; i<10; i++ ){
        printf("%d  ", arr[i]);
    }
    printf("\n");

    return 0;
}


int bucket_sort( int* array, int length ){

    //其实默认处理的数组中最大值不超过数组长度。
    int* temp_arr = new int[length]();
    int i;

    for( i=0; i<length; i++ ){
        temp_arr[ array[i] ]++;
    }

    i=0;
    for(int j=0; j<length; j++){
        for( int k=0; k<temp_arr[j]; k++){
            array[i] = j;
            i++;
        }
    }

    return 0;
}


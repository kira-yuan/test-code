#include <stdio.h>

void merge_sort( int* arr, int length, int* temp);
void merge(int* a1, int a1_l, int* a2, int a2_l, int* temp);

int main()
{

    //int arr[10] = {12,2,3,6,14,99,45,6,3,23,34,77,56,86,63,52,55,66,88,9,44,33,34,55,66,33,96};
    int arr[10] = {9,2,3,6,1,6,7,3,4,8};

    int i;
    for( i=0; i<10; i++ ){
        printf( "%d  ", arr[i]);
    }
    printf("\n");

    int temp[10] = {0};
    merge_sort( arr, 10 , temp);

    for( i=0; i<10; i++ ){
        printf( "%d  ", arr[i]);
    }
    printf("\n");

    return 0;
}

void merge_sort( int* arr, int length , int* temp)
{
    if( 1==length ){
        return; 
    }

    int middle = length/2;
    merge_sort( arr, middle, temp);

    printf("====== merge_half_1:");
    for( int x=0; x<middle; x++ ){
        printf("%d  ", arr[x]);
    }
    printf("\n");

    merge_sort( arr+middle, length-middle, temp+middle);//后半段，用temp后半段

    printf("\t\t\t\t\t\t****** merge_half_2:");
    for( int x=0; x<length-middle; x++ ){
        printf("%d  ", arr[middle+x]);
    } 
    printf("\n");

    merge( arr, middle, arr+middle, length-middle, temp);
}

void merge( int* a1, int a1_l, int* a2, int a2_l, int* temp )
{
//   if( a1_l<=0 || a2_l<=0 ){
//        return false;
//   }

    int i,j;
    int k=0;    
    int len = a1_l+a2_l;
    
    for ( i=0,j=0; i<a1_l && j<a2_l; ){
        if( a1[i] <= a2[j] ){
            temp[k++] = a1[i++];
        }else{
            temp[k++] = a2[j++];
        }   
    }

    while(i<a1_l){
        temp[k++] = a1[i++];
    }

    while(j<a2_l){
        temp[k++] = a2[j++];
    }
/*    
    printf("&&&&   merge_temp:\n");
    for( int x=0; x<len; x++ ){
        printf("%d ", temp[x]);
    }
*/
    //a1数组原来的长度是包含 a2数组的；
    //不改变数组a1的地址，为了维护原数组(a1所指向)指向不变
    for( i=0; i<len; i++ ){
        a1[i] = temp[i];
//        temp[i] = 0;
    }
/*
    printf("#### merge_end:");
    for( int x=0; x<len; x++ ){
        printf("%d ", a1[x]);
    }
    printf("\n");
*/
}


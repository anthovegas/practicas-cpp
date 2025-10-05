#include "reverse.h"
void reverse (int *start, int *end){
    while(start < end){
        int temp=*start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

void rotleft(int arr[], int N, int k){
    reverse (arr, arr + k-1);
    reverse (arr + k, arr + N-1);
    reverse (arr, arr + N-1);
}

void rotright(int arr[], int N, int k){
    rotleft(arr, N, N-k);
}

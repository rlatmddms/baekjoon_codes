#include <stdio.h>
#define arr_size 10

int main() {
    int arr[arr_size] = {1,6,2,4,8,2,45,77,12,3};
    for(int i = 0; i < arr_size; i++) {
        int minidx = i;
        for(int j = i+1; j < arr_size; j++) {
            if(arr[minidx] > arr[j]) {
                minidx = j;
            }
        }
        int tmp = arr[i];
        arr[i] = arr[minidx];
        arr[minidx] = tmp;
    }
    for(int i = 0; i < arr_size; i++) 
        printf("%d, ",arr[i]);
    return 0;
}

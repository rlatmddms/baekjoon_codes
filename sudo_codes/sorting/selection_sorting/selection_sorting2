#include <stdio.h>

int main() {
    const int arr_size; scanf("%d",&arr_size);
    int arr[arr_size];
    for(int i = 0; i < arr_size; i++) 
        scanf("%d",&arr[i]);
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

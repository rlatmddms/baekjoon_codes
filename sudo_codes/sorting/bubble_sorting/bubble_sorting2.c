#include <stdio.h>

int main() {
    const int arr_size = 10;
    int arr[arr_size] = {1,2,4,6,8,3,7,3,12,5};
    for(int i = 0; i < arr_size; i++) {
        for(int j = i+1; j < arr_size; j++) {  //j = 0에서 j = i+1로 바뀜
            if(arr[i] > arr[j]) {
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
    for(int i = 0; i < arr_size; i++) 
        printf("%d, ",arr[i]);
    return 0;
}

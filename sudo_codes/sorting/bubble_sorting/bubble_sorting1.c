#include <stdio.h>
#define arr_size 10
//arr_size 라는 글자 자체를 10과 동일시 하게 만듦

int main() {
    int arr[arr_size] = {1,6,2,4,8,2,45,77,12,3};
    for(int i = 0; i < arr_size; i++) {
        for(int j = i+1; j < arr_size; j++) {
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

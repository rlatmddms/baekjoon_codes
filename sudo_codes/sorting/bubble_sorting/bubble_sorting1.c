#include <stdio.h>

int main() {
    const int arr_size = 10; //const란, 숫자 1,2,3... 처럼 상수로 사용하겠다는 선언
    int arr[arr_size] = {1,6,2,4,8,2,45,77,12,3};
    for(int i = 0; i < arr_size; i++) {
        for(int j = 0; j < arr_size; j++) {
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

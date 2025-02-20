#include<stdio.h>

int main() {
    char tmp;
    int arr[10] = {0};
    while(scanf("%c",&tmp) != -1) {
        arr[tmp-'0']++;
    }
    if(arr[0] == 0 || (arr[1] + arr[2]*2 + arr[4]*4 + arr[5]*5 + arr[7]*7 + arr[8]*8) % 3 != 0) {
        printf("-1");
    }
    else {
        for(int i = 9; i > -1; i--) {
            while(arr[i]--) putchar(i+48);
        }
    }
}
#include<stdio.h>
#include<stdlib.h>

int main() {
    int n,b,ck=1; scanf("%d %d", &n, &b);
    int* A = (int*)malloc(n*4);
    for(int i = 0; i < n; i++) {
        scanf("%d",&A[i]);
        if(A[i] >= b) {
            ck = 0;
            break;
        }
    }

    int l = 0, r = 0, sum = 0, min = 100001;
    if(ck){
    while (l <= n) {
        if(sum < b) {
            sum += A[l++];
        }
        else {
            if(l-r < min) min = l-r;
            sum -= A[r++];
        }
    }
    if(sum >= b && min > l-r) min = l-r;
    if(min == 100001) printf("0");
    else printf("%d", min);
    }
    else printf("1");
}
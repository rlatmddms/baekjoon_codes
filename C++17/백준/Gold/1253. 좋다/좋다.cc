#include<stdio.h>

int main() {
    int a, count = 0; scanf("%d", &a);
    int A[a+1]; for(int i = 0; i < a; i++) scanf("%d", &A[i]);
    
    for(int i = 0; i < a-1; i++) {
        for(int j = 0; j < a-1-i; j++) {
            if(A[j] > A[j+1]) {
                int tmp = A[j];
                A[j] = A[j+1];
                A[j+1] = tmp;
            }
        }
    }
    for(int i = 0; i < a; i++) {
        int g = A[i];
        int i1 = 0, i2 = a-1;
        while(i1 < i2) {
            if(A[i1] + A[i2] == g) {
                if(i1 != i && i2 != i) {count++; break;}
                else if(i1 == i) i1++;
                else i2--;
            }
            else if(A[i1] + A[i2] > g) i2--;
            else i1++;
        }
    }
    printf("%d", count);
}
#include<stdio.h>
#include<string.h>

int main(void) {
    char A[10032], B[10032], result[10033];
    scanf("%s %s", A, B);
    int Alen = strlen(A), Blen = strlen(B);
    int up = 0;
    if(Alen <= Blen) {
        for(int i = 0; i < Alen; i++) {
            int g = (A[Alen-1-i]-'0') + (B[Blen-1-i]-'0') + up;
            if(g>=10) up = 1;
            else up = 0;
            result[i] = g%10 +'0';
        }
        for(int i = Alen; i < Blen; i++) {
            int g = (B[Blen-1-i]-'0') + up;
            if(g>=10) up = 1;
            else up = 0;
            result[i] = g%10 +'0';
        }
        if(up == 1) result[Blen] = '1';
    }
    else {
        for(int i = 0; i < Blen; i++) {
            int g = (A[Alen-1-i]-'0') + (B[Blen-1-i]-'0') + up;
            if(g>=10) up = 1;
            else up = 0;
            result[i] = g%10 +'0';
        }
        for(int i = Blen; i < Alen; i++) {
            int g = (A[Alen-1-i]-'0') + up;
            if(g>=10) up = 1;
            else up = 0;
            result[i] = g%10 +'0';
        }
        if(up == 1) result[Alen] = '1';
    }
    int relen = strlen(result);
    for(int i = 0; i < relen; i++) 
    printf("%c", result[relen-1-i]);
}
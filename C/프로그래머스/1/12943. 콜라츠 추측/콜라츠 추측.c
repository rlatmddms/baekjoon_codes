#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(long long n) {
    int answer = 0;
    while(n != 1 && answer < 500) {
        if(n % 2 == 0) n /= 2;
        else n = 3*n + 1;
        answer++;
    }
    return (answer >= 500 ? -1 : answer);
}
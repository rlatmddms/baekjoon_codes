#include<stdio.h>

int main() {
    int n = getchar() - '0'; char n2 = getchar();
    if(n2 != '\n') {
        n = n*10 + n2 - '0';
        getchar();
    }
    char words[50][51];
    int lens[50] = {0}, word = 0;
    
    for(int i = 0; i < n; i++) {
        char tmp[51]; int tmplen = 0;
        while(1) {
            tmp[tmplen++] = getchar();
            if(tmp[tmplen-1] == '\n' || tmp[tmplen-1] == -1) {
                tmp[tmplen-1] = '\0';
                tmplen--;
                break;
            }
        }
        int put_this_word = 1;
        for(int j = 0; j < word; j++) {
            if(lens[j] == tmplen) {
                for(int l = 0; l < tmplen; l++) {
                    int is_all_same = 1;
                    for(int p = 0; p < tmplen; p++) {
                        if(words[j][p] != tmp[(l+p)%tmplen]) {
                            is_all_same = 0;
                            break;
                        }
                    }
                    if(is_all_same) {
                        put_this_word = 0;
                        j = 500;
                        break;
                    }
                }
            }
        }
        if(put_this_word) {
            lens[word] = tmplen;
            for(int j = 0; j < tmplen; j++) {
                words[word][j] = tmp[j];
            }
            // printf("%d %s %d\n",word, words[word],lens[word]);
            word++;
        }
    }
    printf("%d",word);
}
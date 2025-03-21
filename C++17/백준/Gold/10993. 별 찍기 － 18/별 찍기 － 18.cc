/*<입출력 라이브러리>*/
#include <iostream>
//#include <cstdio>
                        /*<c++ 컨테이너 라이브러리>*/
#include <vector>
// #include <queue>
// #include <deque>
// #include <stack>
// #include <list>
// #include <map>
// #include <set>
// #include <unordered_map>
// #include <unordered_set>
// #include <tuple>
                        /*<기타 라이브러리>*/
// #include <string>
// #include <algorithm>
// #include <random>
                        /*<기존 c표준 라이브러리>*/
// #include <cmath>
// #include <ctime>
// time_t start = clock();
// cout << endl << (double)(clock() - start) / CLOCKS_PER_SEC << "sec" << endl;
#define ABS(x) ((x<0)?(-x):(x))
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define For(j, start,end) for(int j = start; j < end; j++)

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef double llf;
typedef float f;

bool cmp(int a, int b) {
    return a > b;
}
//a<b 오름차순, a>b내림차순
//true면 변동x, false이면 순서 바뀜

bool board[2500][2500];
int p2w[13] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096};

void sol(int n,int x, int y) {
    if(n == 2) {
        board[y][x] = true;
        board[y][x+1] = true;
        board[y][x+2] = true;
        board[y][x+3] = true;
        board[y][x+4] = true;

        board[y+1][x+1] = true;
        board[y+1][x+2] = true;
        board[y+1][x+3] = true;

        board[y+2][x+2] = true;
        return;
    }
    if(n%2 == 0) {
        int xx = p2w[n+1]-3;
        for(int i = 0; i < xx;i++) {
            board[y][x+i] = true;
        }
        for(int i = 1; i < xx/2+1; i++) {
            board[y+i][x+i] = true;
            board[y+i][x+xx-i-1] = true;
        }
        n--;
        sol(n,x+p2w[n],y+p2w[n]-1);
    }
    else {
        int xx = p2w[n+1]-3;
        for(int i = 0; i < xx;i++) {
            board[y][x+i] = true;
        }
        for(int i = 1; i < xx/2+1; i++) {
            board[y-i][x+i] = true;
            board[y-i][x+xx-i-1] = true;
        }
        n--;
        sol(n,x+p2w[n],y-p2w[n]+1);
    }
}

int main() {
    FASTIO;
    int n; cin >> n;
    if(n == 1) {
        cout << '*';
        return 0;
    }
    if(n == 2) {
        cout << "*****\n ***\n  *";
        return 0;
    }
    For(i,0,2500) For(j,0,2500) board[i][j] = false;
    if(n%2 == 0) {
    sol(n,0,0);
    for(int i = 0; ;i++) {
        for(int j = 0; j < p2w[n+1] - 3-i; j++) {
            if(board[i][j]) cout << '*';
            else cout << ' ';
        }
        if(i == p2w[n]-2) break;
        cout << '\n';
    }
    }
    else {
    sol(n,0,p2w[n]-2);

    for(int i = 0; ;i++) {
        for(int j = 0; j < p2w[n]-1 + i; j++) {
            if(board[i][j]) cout << '*';
            else cout << ' ';
        }
        if(i == p2w[n]-2) break;
        cout << '\n';
    }
    }
    // system("pause>null");
}
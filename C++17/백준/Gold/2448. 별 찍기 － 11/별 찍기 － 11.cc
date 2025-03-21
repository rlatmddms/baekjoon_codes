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

bool board[3100][6200];
int p2w[11] = {1,2,4,8,16,32,64,128,256,512,1024};

void draw_basic_tri(int x, int y) {
    board[y][x-1] = true;
    board[y][x-2] = true;
    board[y-1][x-2] = true;
    board[y][x-3] = true;
    board[y-2][x-3] = true;
    board[y][x-4] = true;
    board[y-1][x-4] = true;
    board[y][x-5] = true;
}

void sol(int n,int x, int y) {
    if(n == 0) {
        draw_basic_tri(x,y);
        return;
    }
    sol(n-1,x-3*p2w[n-1],y-3*p2w[n-1]);

    sol(n-1,x-3*p2w[n],y);
    
    sol(n-1,x,y);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n; cin >> n; n/=3;
    For(i,0,3100)
    For(j,0,6200)
    board[i][j] = 0;
    int n_sqrt2 = 0,tmp_n = n;
    for(n_sqrt2 = 0; tmp_n > 1; n_sqrt2++) {
        tmp_n /= 2;
    }

    sol(n_sqrt2, 6*n, 3*n);

    for(int y = 1; y <= 3*n; y++) {
        for(int x = 1; x <= 6*n; x++) {
            cout << (board[y][x] ? '*' : ' ');
        }
        cout << '\n';
    }
}
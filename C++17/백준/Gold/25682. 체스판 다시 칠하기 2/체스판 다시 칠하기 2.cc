                        /*<입출력 라이브러리>*/
#include <iostream>
//#include <cstdio>
                        /*<c++ 컨테이너 라이브러리>*/
#include <vector>
#include <queue>
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m, k; cin >> n >> m >> k;
    int **board = new int*[n+1];
    board[0] = new int[m+1];
    for(int i = 0; i <= m; i++) board[0][i] = 0;
    for(int i = 1; i <= n; i++) {
        board[i] = new int[m+1];
        board[i][0] = 0;
        for(int j = 1; j <= m; j++) {
            char input; cin >> input;
            if(input == 'B' && (i+j)%2 == 0 || input == 'W' && (i+j)%2 == 1) board[i][j] = 1;
            else board[i][j] = 0;
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            board[i][j] = board[i][j] + board[i][j-1] + board[i-1][j] - board[i-1][j-1];
        }
    }
    int max = -1,min = 4000001;
    for(int i = k; i <= n; i++) {
        for(int j = k; j <= m; j++) {
            int tmp = board[i][j] - board[i-k][j] - board[i][j-k] + board[i-k][j-k];
            if(tmp < min) min = tmp;
            if(tmp > max) max = tmp;
        }
    }
    if(k*k - max < min) cout << k*k - max;
    else cout << min;
}

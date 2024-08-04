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
#include <string>
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

int n,m;
vector<string> board; 
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

void dfs(int x, int y) {
    if(board[y][x] == '0') {
        board[y][x] = '2';
        for(int i = 0; i < 4; i++) {
            int ax = x+dx[i], ay = y+dy[i];
            if(ax < 0 || ax == m || ay < 0 || ay == n) continue;
            dfs(ax,ay);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        string str;
        cin >> str;
        board.push_back(str);
    }
    for(int i = 0; i < m; i++) {
        dfs(i,0);
    }
    for(int i = 0; i < m; i++) {
        if(board[n-1][i] == '2') {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
}
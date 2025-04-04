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

string board[6562];

void jagyu(int x, int y, int size) {
    if(size == 1) {
        return;
    }
    int div3_size = size/3;

    jagyu(x,y,div3_size);
    jagyu(x+div3_size,y,div3_size);
    jagyu(x+div3_size*2,y,div3_size);
    jagyu(x,y+div3_size,div3_size);
    jagyu(x+div3_size*2,y+div3_size,div3_size);
    jagyu(x,y+div3_size*2,div3_size);
    jagyu(x+div3_size,y+div3_size*2,div3_size);
    jagyu(x+div3_size*2,y+div3_size*2,div3_size);
    for(int i = 0; i < div3_size; i++) {
        for(int j = 0; j < div3_size; j++) {
            board[x+div3_size+i][y+div3_size+j] = ' ';
        }
    }
}

void print_board(int size){
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            cout << board[i][j];
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        board[i] = "";
        for(int j = 0; j < n; j++) {
            board[i].push_back('*');
        }
    }

    jagyu(0,0,n);
    print_board(n);
}

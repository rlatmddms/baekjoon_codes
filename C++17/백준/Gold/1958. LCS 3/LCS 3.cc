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

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef double llf;
typedef float f;

int big(int a, int b, int c) {
    a = a > b ? a : b;
    return a > c ? a : c;
}
//a<b 오름차순, a>b내림차순
//true면 변동x, false이면 순서 바뀜

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string a,b,c; cin >> a >> b >> c;
    a = 'x' + a;
    b = 'x' + b;
    c = 'x' + c;
    int dp[101][101][101] = {0};
    for(int i = 1; i < b.size(); i++) {
        for(int j = 1; j < a.size(); j++) {
            for(int k = 1; k < c.size(); k++) {
                if(a[j] == b[i] && a[j] == c[k]) {
                    dp[i][j][k] = dp[i-1][j-1][k-1] + 1;
                }
                else {
                    dp[i][j][k] = big(dp[i-1][j][k], dp[i][j-1][k], dp[i][j][k-1]);
                }
            }
        }
    }
    cout << dp[b.size()-1][a.size()-1][c.size()-1];
}
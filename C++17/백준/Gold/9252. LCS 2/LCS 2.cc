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

int big(int a, int b) {return a>b?a:b;}
//a<b 오름차순, a>b내림차순
//true면 변동x, false이면 순서 바뀜

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string a,b; cin >> a >> b;
    a = 'x' + a;
    b = 'x' + b;
    int dp[1001][1001] = {0};
    for(int i = 1; i < b.size(); i++) {
        for(int j = 1; j < a.size(); j++) {
            if(a[j] == b[i]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else {
                dp[i][j] = big(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    cout << dp[b.size()-1][a.size()-1] << '\n';
    // for(int i = 1; i < b.size(); i++) {
    //     for(int j = 1; j < a.size(); j++) {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << a << ' ' << a.size() << endl;
    // cout << b << ' ' << b.size() << endl;
    string ans = "";
    int i = b.size()-1, j = a.size()-1;
    while(i > 0 && j > 0) {
        if(dp[i][j] == dp[i-1][j]) {
            i--;
        }
        else if(dp[i][j] == dp[i][j-1]) {
            j--;
        }
        else {
            ans.push_back(a[j]);
            i--;
            j--;
        }
    }
    while(!ans.empty()) {
        cout << ans.back();
        ans.pop_back();
    }
}
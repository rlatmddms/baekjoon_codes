                        /*<입출력 라이브러리>*/
#include <iostream>
//#include <cstdio>
                        /*<c++ 컨테이너 라이브러리>*/
// #include <vector>
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
// typedef unsigned long long ull;
// typedef long long ll;
// typedef double llf;
// typedef float f;

// bool cmp(int a, int b) {
//     return a > b;
// }
//a<b 오름차순, a>b내림차순
//true면 변동x, false이면 순서 바뀜

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n; cin >> n;
    if(n == 1) {
        cin >> n;
        cout << n;
        return 0;
    }
    queue<pair<int,int>> q;
    int tmp; cin >> tmp;
    q.push(make_pair(tmp,0));
    // cout  << q.back().first << ' ' << q.back().second << '\n';
    cin >> tmp;
    q.push(make_pair(tmp+q.back().first,tmp));
    // cout  << q.back().first << ' ' << q.back().second << '\n';
    for(int i = 0; i < n-2; i++) {
        cin >> tmp;
        int max = q.front().second < q.front().first ? q.front().first : q.front().second;
        q.push(make_pair(tmp + q.back().second, tmp + max));
        q.pop();
        // cout  << q.back().first << ' ' << q.back().second << '\n';
    }
    cout << (q.back().first < q.back().second ? q.back().second : q.back().first);
}
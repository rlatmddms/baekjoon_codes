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

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef double llf;
typedef float f;

int visit[1000001];

int bfs(int n) {
    queue<int> q;
    q.push(n);
    visit[n] = 1;
    while(!q.empty()) {
        int n = q.front(); q.pop();
        // cout << visit[n] << ' ' << n << '\n';
        if(n == 1) return visit[n]-1;
        
        if(n%3 == 0 && visit[n/3] == 0) {
            visit[n/3] = visit[n]+1;
            q.push(n/3);
        }
        if(n%2 == 0 && visit[n/2] == 0) {
            visit[n/2] = visit[n]+1;
            q.push(n/2);
        }
        if(n-1 != 0 && visit[n-1] == 0) {
            visit[n-1] = visit[n]+1;
            q.push(n-1);
        }
    }
    return 0;
}

//bool cmp(int a, int b) {
//    return a > b;
//}
//a<b 오름차순, a>b내림차순
//true면 변동x, false이면 순서 바뀜

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n; cin >> n;
    cout << bfs(n);
}
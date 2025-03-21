/*<입출력 라이브러리>*/
#include <iostream>
//#include <cstdio>
                        /*<c++ 컨테이너 라이브러리>*/
// #include <vector>
#include <queue>
// #include <deque>
#include <stack>
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


int arr[1000001][2] = {0};

void bfs(int n) {
    queue<int> q; q.push(n);
    arr[n][0] = 1; arr[n][1] = -1;
    while(!q.empty()) {
        int v = q.front(); q.pop();
        if(v == 1) break;
        if(arr[v-1][0] == 0) {
            arr[v-1][0] = arr[v][0] + 1;
            arr[v-1][1] = v;
            q.push(v-1);
        }
        if(v%2 == 0 && arr[v/2][0] == 0) {
            arr[v/2][0] = arr[v][0] + 1;
            arr[v/2][1] = v;
            q.push(v/2);
        }
        if(v%3 == 0 && arr[v/3][0] == 0) {
            arr[v/3][0] = arr[v][0] + 1;
            arr[v/3][1] = v;
            q.push(v/3);
        }
    }
}

int main() {
    FASTIO;
    int n; cin >> n;
    
    arr[0][0] = -1;
    bfs(n);
    stack<int> st;
    for(int i = 1; arr[i][1] != -1; i = arr[i][1]) {
        st.push(arr[i][1]);
    }
    cout << arr[1][0] - 1 << '\n';
    while(!st.empty()) {
        cout << st.top() << ' ';
        st.pop();
    }
    cout << 1;
}
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
    int n,sol = -1; cin >> n;
    int arr[1000];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int cnt1[1000] = { 0 },cnt2[1000] = { 0 };
    for(int i = 0; i < n; i++) {
        cnt1[i] = 1; int max = 0;
        for(int j = 0; j < i; j++) {
            if(arr[j] < arr[i]) {
                if(cnt1[j] > max) max = cnt1[j];
            }
        }
        cnt1[i] += max;
        // cout << cnt1[i] << ' ';
    }
    // cout << endl;
    for(int i = n-1; i > -1; i--) {
        cnt2[i] = 1; int max = 0;
        for(int j = i+1; j < n; j++) {
            if(arr[j] < arr[i]) {
                if(cnt2[j] > max) max = cnt2[j];
            }
        }
        cnt2[i] += max;
    }
    // for(int i = 0; i < n; i++) cout << cnt2[i] << ' ';
    // cout << endl;
    for(int i = 0; i < n; i++) {
        if(sol < cnt1[i] + cnt2[i]) sol = cnt1[i] + cnt2[i];
    }
    cout << sol - 1;
}

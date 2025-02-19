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

int biggest4(int a,int b, int c, int d) {
    a = a > b ? a : b;
    c = c > d ? c : d;
    return a > c ? a : c;
}
int biggest3(int a,int b, int c) {
    a = a > b ? a : b;
    return a > c ? a : c;
}

int bigger(int a, int c) {
    return a > c ? a : c;
}

ll solution(int* arr, int n, int m) {
    ll sum = 0;
    arr[0] %= m;
    // cout << arr[0] << ' ';
    for(int i = 1; i < n; i++) {
        arr[i] = (arr[i] + arr[i-1])%m;
        // cout << arr[i] << ' ';
    }
    
    for(int i = 1; i < m; i++) {
        int cnt = 0;
        for(int j = 0; j < n; j++) {
            if(arr[j] == i) cnt++;
        }
        sum += ((ll)cnt * (cnt-1)) / (ll)2;
    }
    int cnt = 0;
    for(int j = 0; j < n; j++) {
        if(arr[j] == 0) cnt++;
    }
    sum += ((ll)cnt * (cnt+1)) / (ll)2;

    return sum;
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int arr[1000001], n,m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << solution(arr, n,m);
}
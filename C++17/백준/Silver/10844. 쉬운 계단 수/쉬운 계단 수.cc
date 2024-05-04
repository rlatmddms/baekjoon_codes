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
    int n; cin >> n;
    ull a[10];
    ull arr[10] = {0,1,1,1,1,1,1,1,1,1};
    for(int i = 0; i < n-1; i++) {
        a[0] = arr[1]; a[9] = arr[8];
        for(int i = 1; i < 9; i++) 
        a[i] = arr[i-1] + arr[i+1];
        for(int i = 0; i < 10; i++) 
            arr[i] = a[i] % 1000000000;
    }
    a[0] = 0;
    for(int i = 0; i < 10; i++) a[0] += arr[i];
    a[0] %= 1000000000;
    cout << a[0];
}
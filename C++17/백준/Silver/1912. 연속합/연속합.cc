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
    
    vector<int> arr,min;
    arr.push_back(0);
    min.push_back(0);
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        int input; cin >> input;
        arr.push_back(input+arr.back());
        min.push_back(arr.back() > min.back() ? min.back() : arr.back());
        // cout << arr.back() << ' ' << min.back() << '\n';
    }
    int max = -2222;
    for(int i = 1; i <= n; i++) {
        if(arr[i] - min[i-1] > max) {
            max = arr[i] - min[i-1];
        }
    }
    cout << max;
}
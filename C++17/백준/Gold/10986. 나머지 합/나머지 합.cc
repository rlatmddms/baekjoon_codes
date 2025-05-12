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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m; cin >> n >> m;
    vector<ll> arr;
    for(int i=0; i<n; i++) {
        ll a; cin >> a;
        arr.push_back(a%m);
    }
    for(int i=1; i<n; i++) {
        arr[i] = (arr[i-1] + arr[i])%m;
    }
    ll sum = 0,cnt[1000] = {0};
    for(int i=0; i<n; i++) {
        if(arr[i] == 0) sum++;
        else {
            cnt[arr[i]]++;
        }
        // cout << arr[i] << ' ';
    }
    // cout << endl;
    sum = (sum*(sum+1))/(ll)2;
    for(int i=1; i<m; i++) {
        if(cnt[i] > 1) {
            sum += (cnt[i]*(cnt[i]-1))/(ll)2;
        }
        // cout << cnt[i] << ' ';
    }
    cout << sum;
    return 0;

}

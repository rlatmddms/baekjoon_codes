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
#include <algorithm>
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
    return a < b;
}
//a<b 오름차순, a>b내림차순
//true면 변동x, false이면 순서 바뀜

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,c; cin >> n >> c;
    vector<int> houses;
    for(int i = 0; i < n; i++) {
        int input; cin >> input;
        houses.push_back(input);
    }
    sort(houses.begin(), houses.end(), cmp);
    // for(int i : houses) cout << i << ' ';
    int left = 1, right = 1000000000,mid,big = 0;
    while(left <= right) {
        mid = (left+right)/2; int cnt = 1,b = houses.front();
        for(int i = 0; i < n; i++) {
            if(houses[i]-b >= mid) {
                b = houses[i];
                cnt++;
            }
        }
        // cout << left << ' ' << right;
        if(cnt >= c) {
            // cout << 'O';
            if(big < mid) big = mid;
            left = mid+1;
        }
        else {
            right = mid-1;
        }
        // cout << endl;
    }
    cout << big;
}
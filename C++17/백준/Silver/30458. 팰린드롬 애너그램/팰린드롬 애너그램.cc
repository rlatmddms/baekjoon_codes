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

int alp1[26] = {0};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n; cin >> n;
    char* str = new char[n+1];
    cin >> str;
    int i = 0;
    for(int whrjs = n/2; i < whrjs; i++) 
        alp1[str[i] - 'a']++;
    if(n%2 == 1) i++;
    for(; i < n; i++) 
        alp1[str[i] - 'a']++;
    for(i = 0; i < 26; i++) {
        if(alp1[i] % 2 == 1) i = 99;
    }
    if(i == 100) cout << "No";
    else cout << "Yes";
    // cout << str;
}
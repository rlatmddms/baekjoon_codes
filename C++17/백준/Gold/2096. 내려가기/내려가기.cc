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
    int max[3],min[3];
    cin >> max[0] >> max[1] >> max[2];
    min[0] = max[0]; min[1] = max[1]; min[2] = max[2];
    
    
    for(int i = 0; i < n-1; i++) {
        int a,b,c,tmp,ta,tb,tc; cin >> a >> b >> c;
        ta = a; tb = b; tc = c;
        tmp = (max[0] < max[1]) ? max[1] : max[0];
        ta += tmp;
        tb += (tmp < max[2]) ? max[2] : tmp;
        tc += (max[1] < max[2]) ? max[2] : max[1];
        max[0] = ta; max[1] = tb; max[2] = tc;
        
        ta = a; tb = b; tc = c;
        tmp = (min[0] < min[1]) ? min[0] : min[1];
        ta += tmp;
        tb += (tmp < min[2]) ? tmp : min[2];
        tc += (min[1] < min[2]) ? min[1] : min[2];
        min[0] = ta; min[1] = tb; min[2] = tc;
    }
    max[0] = (max[0] < max[1]) ? max[1] : max[0];
    max[0] = (max[0] < max[2]) ? max[2] : max[0];
    min[0] = (min[0] < min[1]) ? min[0] : min[1];
    min[0] = (min[0] < min[2]) ? min[0] : min[2];
    cout << max[0] << ' ' << min[0];
}
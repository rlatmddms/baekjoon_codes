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
bool erts[20000001] = {0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    erts[0] = 1; erts[1] = 1;
    vector<int> primes; primes.push_back(2);
    for(int i = 4; i < 20000001; i+=2) {
        erts[i] = 1;
    }
    for(int i = 3; i < 20000001; i+=2) {
        if(erts[i] == false) {
            primes.push_back(i);
            for(int j = i+i; j < 20000001; j+=i)
                erts[j] = 1;
        }
    }
    ull c[6], x[7]; cin >> c[0] >> c[1] >> c[2] >> c[3] >> c[4] >> c[5];
    for(int x0 : primes) {
        x[0] = x0;
        
        if(c[0] % x0 != 0) continue;
        x[1] = c[0] / x0;
        if(erts[x[1]]) 
            continue;
            
        if(c[4] % x[1] != 0) continue;
        x[2] = c[4] / x[1];
        if(erts[x[2]]) 
            continue;

        break;
    }
    for(int x6 : primes) {
        x[6] = x6;
        
        if(c[2] % x6 != 0) continue;
        x[5] = c[2] / x6;
        if(erts[x[5]]) 
            continue;
        
        if(c[5] % x[5] != 0) continue;
        x[4] = c[5] / x[5];
        if(erts[x[4]]) 
            continue;

        break;
    }
    cout << x[0] << ' ' << x[1] << ' ' << x[2] << ' ' << x[4] << ' ' << x[5] << ' ' << x[6] << ' ';
}
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
    int T; cin >> T;
    for(int test = 0; test < T; test++) {
        vector<int> student_codes;
        int n; cin >> n;
        for(int i = 0; i < n; i++) {
            int code; cin >> code;
            student_codes.push_back(code);
        }
        int* new_codes = new int[n+1];
        for(int i = 1; i < 100000; i++) {
            for(int j = 0; j < n; j++) {
                new_codes[j] = student_codes[j] % i;
            }
            for(int j = 0; j < n; j++) {
                for(int k = j+1; k < n; k++) {
                    if(new_codes[j] == new_codes[k]) {
                        new_codes[0] = -1;
                        j = n;
                        break;
                    }
                }
            }
            if(new_codes[0] == -1) continue;
            cout << i << '\n';
            break;
        }
    }
}
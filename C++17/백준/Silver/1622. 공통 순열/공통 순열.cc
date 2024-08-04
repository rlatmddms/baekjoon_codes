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
#include <string>
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
    string str1,str2;
    while(1) {
        getline(cin,str1);
        if(cin.eof()) break;
        getline(cin,str2);
        if(cin.eof()) {
            cout << '\n';
            break;
        }
        int str1_alp[26] = {0},str2_alp[26] = {0};
        for(auto c : str1) 
            str1_alp[c-'a']++;
        for(auto c : str2) 
            str2_alp[c-'a']++;
        
        for(int i = 0; i < 26; i++) {
            if(str1_alp[i] > str2_alp[i]) {
                if(str2_alp[i] == 0) continue;
                while(str2_alp[i]--) {
                    cout << (char)(i + 'a');
                }
            }
            else {
                if(str1_alp[i] == 0) continue;
                while(str1_alp[i]--) {
                    cout << (char)(i + 'a');
                }
            }
        }
        cout << '\n';
    }
}
                        /*<입출력 라이브러리>*/
#include <iostream>
//#include <cstdio>
                        /*<c++ 컨테이너 라이브러리>*/
#include <vector>
// #include <queue>
#include <deque>
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
// #define ABS(x) ((x<0)?(-x):(x))

using namespace std;
// typedef unsigned long long ull;
// typedef long long ll;
// typedef double llf;
// typedef float f;

// bool cmp(int a, int b) {
//     return a > b;
// }
//a<b 오름차순, a>b내림차순
//true면 변동x, false이면 순서 바뀜

int tr(string str) {
    int sum = 0;
    for(int i = 1; str.size(); i*=10) {
        sum += (str.back() - '0') * i;
        str.pop_back();
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T; cin >> T;
    for(int t = 0; t < T; t++) {
        string func; cin >> func;
        int len; cin >> len;
        bool turned = false;
        deque<int> dq;
        string str,s; cin >> s; 
        for(int i = 1; i < s.size()-1; i++) {
            if(s[i] == ',') {
                dq.push_back(tr(str));
                str = "";
                continue;
            }
            str.push_back(s[i]); 
        }
        if(str != "")
            dq.push_back(tr(str));
        for(int i = 0; i < func.size(); i++) {
            if(func[i] == 'R') {
                turned = !turned;
            }
            else {
                if(!dq.size()) {
                    len = -1;
                    break;
                }
                if(turned) 
                    dq.pop_back();
                else 
                    dq.pop_front();
            }
        }
        if(len == -1) cout << "error\n";
        else {
            cout << '[';
            if (dq.size() == 0) {int j;}
            else if(!turned) {
                for(int i = 0; i < dq.size()-1; i++) {
                    cout << dq[i] << ',';
                }
                if(dq.size()) cout << dq.back();
            }
            else {
                for(int i = dq.size()-1; i > 0; i--) {
                    cout << dq[i] << ',';
                }
                if(dq.size()) cout << dq.front();
            }
            cout << "]\n";
        }
    }
}
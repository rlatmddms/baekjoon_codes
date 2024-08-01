#include <iostream>

using namespace std;

int main() {
    int n,left=1,right,cnt = 0,act; cin >> n >> right >> act;
    while(act--) {
        int pos; cin >> pos;
        if(pos <= right && pos >= left) {
            continue;
        }
        else if(pos >= right) {
            left += pos - right;
            cnt += pos - right;
            right = pos;
        }
        else {
            right += pos - left;
            cnt -= pos - left;
            left = pos;
        }
    }
    cout << cnt;
}
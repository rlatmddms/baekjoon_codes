#include <iostream>
#include <vector>
#include <queue>
#define ABS(x) ((x<0)?(-x):(x))

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n; cin >> n;
    int arr[1000], cnt[1000] = {0};
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int sol = 0;
    for(int i = 0; i < n; i++) {
        cnt[i] = 1; int max = 0;
        for(int j = 0; j < i; j++) {
            if(arr[j] < arr[i]) {
                if(cnt[j] > max) max = cnt[j];
            }
        }
        if(max+1 > sol) sol = max+1;
        cnt[i] += max;
        // cout << cnt[i] << ' ';
    }
    cout << sol;
}

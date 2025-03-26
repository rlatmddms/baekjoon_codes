#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define ABS(x) ((x<0)?(-x):(x))

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n; cin >> n;
    vector<pair<int,int>> lines;
    for(int i = 0; i < n; i++) {
        int a,b; cin >> a >> b;
        lines.push_back(make_pair(a,b));
    }
    sort(lines.begin(),lines.end());
    vector<int> arr;
    for(int i = 0; i < n; i++) {
        arr.push_back(lines[i].second);
    }
    int cnt[1000] = { 0 };
    for(int i = 0; i < n; i++) {
        cnt[i] = 1; int max = 0;
        for(int j = 0; j < i; j++) {
            if(arr[j] < arr[i]) {
                if(cnt[j] > max) max = cnt[j];
            }
        }
        cnt[i] += max;
        // cout << cnt1[i] << ' ';
    }
    int sol = -1;
    for(int i = 0; i < n; i++) {
        if(sol < cnt[i]) sol = cnt[i];
    }

    cout << n-sol;

}

#include <iostream>
using namespace std;
typedef unsigned long long ull;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n; cin >> n;
    ull a[10];
    ull arr[10] = {0,1,1,1,1,1,1,1,1,1};
    for(int i = 0; i < n-1; i++) {
        a[0] = arr[1]; a[9] = arr[8];
        for(int i = 1; i < 9; i++) 
        a[i] = arr[i-1] + arr[i+1];
        for(int i = 0; i < 10; i++) 
            arr[i] = a[i] % 1000000000;
    }
    a[0] = 0;
    for(int i = 0; i < 10; i++) a[0] += arr[i];
    a[0] %= 1000000000;
    cout << a[0];
}
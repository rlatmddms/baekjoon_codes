#include <iostream>

#include <vector>

#include <algorithm>

using namespace std;

int arr[1000001] = { 0 };

int sol(int n) {

    if (arr[n]) {

        return arr[n];

        }

    int min = 999999;    

    for(int i = 1; i*i < n; i++) {

        int tmp = sol(i*i) + sol(n - i*i);

        if(min > tmp) min = tmp;

    }

    arr[n] = min;

    return min;

}

int main() {

    ios::sync_with_stdio(false);

    cin.tie(NULL);

    cout.tie(NULL);

    int n; cin >> n;

    for(int i = 1; i*i <= n; i++) arr[i*i] = 1;

    sol(n);

    cout << arr[n];

}
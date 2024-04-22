#include <iostream>

using namespace std;

int main() {
    int n; cin >> n;
    int a = 1, b = 1;
    for(int i = 0; i < n; i++) {
        int tmp = a+b;
        a = b%15746;
        b = tmp%15746;
    }
    cout << a%15746;
}
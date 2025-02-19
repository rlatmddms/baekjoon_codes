#include <iostream>

using namespace std;

int main() {
    int n; cin >> n;
    int a = 1,b=1;
    for(int i = 0; i < n; i++) {
        int tmp = a;
        a = b;
        b = (tmp+b)%15746;
    }
    cout << a;
}
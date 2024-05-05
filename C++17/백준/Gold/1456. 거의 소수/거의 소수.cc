#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    long long a1, a2;
    cin >> a1 >> a2;

    long long n = static_cast<long long>(sqrt(a2)) + 1;
    vector<bool> isPrime(n + 1, true);

    for (long long i = 2; i * i <= n; ++i) {
        if (isPrime[i]) {
            for (long long j = i * i; j <= n && j > 0; j += i) {
                isPrime[j] = false;
            }
        }
    }

    long long countPrimes = 0;
    for (long long i = 2; i <= n; ++i) {
        if (isPrime[i]) {
            long long power = i;
            while (power <= a2 / i && power > 0) {
                power *= i;
                if (power >= a1) {
                    countPrimes++;
                }
            }
        }
    }

    cout << countPrimes;

    return 0;
}

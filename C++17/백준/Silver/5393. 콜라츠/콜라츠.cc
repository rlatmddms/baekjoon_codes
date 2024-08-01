#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T; cin >> T;
    while(T--) {
        int n; cin >> n;
// Calculate the threshold for j
        int threshold = (n - 1) / 3;

        // Calculate the count of odd numbers greater than threshold
        int start = threshold + 1;

        // If start is even, go to the next odd number
        if (start % 2 == 0) {
            start++;
        }

        // Total odds from 1 to n
        int totalOdds = (n + 1) / 2;

        // Calculate the count of odd numbers greater than the threshold
        int count = 0;
        for (int j = start; j <= n; j += 2) {
            count++;
        }

        // Final count
        count += (n + 1) / 2;
        cout << count << '\n';
    }
}
#include<iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    char tmp;
    int arr[10] = {0};
    while(cin >> tmp) {
        arr[tmp-'0']++;
    }
    int is_multiple3 = arr[1] + arr[2]*2 + arr[4]*4 + arr[5]*5 + arr[7]*7 + arr[8]*8;
    if(arr[0] == 0 || is_multiple3 % 3 != 0) {
        cout << "-1";
    }
    else {
        for(int i = 9; i > -1; i--) {
            while(arr[i]--) cout << i;
        }
    }
}
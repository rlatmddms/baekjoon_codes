#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    vector<int> peoples(n,1);
    for(int i : lost) {
        peoples[i-1] -= 1;
    }
    for(int i : reserve) {
        peoples[i-1] += 1;
    }
    for(int i = 0; i < n; i++) {
        if(peoples[i] == 2) {
            if(i-1 >= 0 and peoples[i-1] == 0) {
                peoples[i] = 1;
                peoples[i-1] = 1;
            }
            else if(i+1 < n and peoples[i+1] == 0) {
                peoples[i] = 1;
                peoples[i+1] = 1;
            }
        }
    }
    int ans = 0;
    for(int i : peoples) {
        ans += (i ? 1 : 0); 
        // cout << i << ' ';
    }
    return ans;
}
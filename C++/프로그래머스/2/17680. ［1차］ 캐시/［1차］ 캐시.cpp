#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    if(cacheSize == 0) return cities.size() * 5;
    for(int i = 0; i < cities.size(); i++) {
        string upper_string = "";
        for(char c : cities[i]) {
            if(c > 90) c = c - 32;
            upper_string.push_back(c);
        }
        cities[i] = upper_string;
        // cout << cities[i] << endl;
    }
    string arr[30] = {"x0x","x0x","x0x","x0x","x0x","x0x","x0x","x0x","x0x","x0x","x0x","x0x","x0x","x0x","x0x","x0x","x0x","x0x","x0x","x0x","x0x","x0x","x0x","x0x","x0x","x0x","x0x","x0x","x0x","x0x"};
    for(int i = 0; i < cities.size(); i++) {
        // cout << cities[i] << '\n';
        // for(int k = 0; k < cacheSize; k++) {
        //     cout << arr[k] << ' ';
        // }
        // cout << '\n';
        int idx = -1;
        for(int j = 0; j < 30; j++) {
            if(arr[j] == cities[i]) {
                idx = j;
                break;
            }
        }
        if(idx != -1) {
            for(int l = idx; l > 0; l--) {
                arr[l] = arr[l-1];
            }
            arr[0] = cities[i];
            answer++;
        }
        else {
            for(int l = cacheSize-1; l > 0; l--) {
                arr[l] = arr[l-1];
            }
            arr[0] = cities[i];
            
            answer+=5;
        }
    }
    return answer;
}
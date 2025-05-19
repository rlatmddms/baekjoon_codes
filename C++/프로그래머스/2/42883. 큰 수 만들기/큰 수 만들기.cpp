#include<iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    bool remove[number.size()+1];
    for(int i = 0; i < number.size()+1; i++) 
        remove[i] = false;
    int rem = 0;
    int len = number.size();
    while(rem < k) {
        bool ck = true;
        for(int i = 0; i < number.size()-1; i++) {
            if(number[i] < number[i+1]) {
                number.erase(i, 1);
                rem++;
                ck = false;
                break;
            }
        }
        if(ck) {
            number.pop_back();
            rem++;
        }
    }
    string ans = "";
    for(int i = 0; i < number.size(); i++) {
        ans.push_back(number[i]);
    }
    return ans;
}
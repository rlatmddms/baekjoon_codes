#include <iostream>

using namespace std;

int main() {
    string str; cin >> str;
    for(int i = 0; i < str.size() - 1; i++) {
        for(int j = i + 1; j < str.size(); j++) {
            if(str[i] < str[j]) {
                char tmp = str[i];
                str[i] = str[j];
                str[j] = tmp;
            }
        }
    }
    cout << str;
}
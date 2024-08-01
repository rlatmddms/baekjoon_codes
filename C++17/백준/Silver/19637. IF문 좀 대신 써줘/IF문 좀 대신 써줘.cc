#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m; cin >> n >> m;
    vector<pair<string,int>> names;
    string name; int power;
    cin >> name >> power;
    names.push_back(make_pair(name,power));
    for(int i = 0; i < n-1; i++) {
        cin >> name >> power;
        if(names.back().second == power) {
            i--;
            n--;
            continue;
        }
        names.push_back(make_pair(name,power));
    }
    for(int i = 0; i < m; i++) {
        int left = 0, right = n-1, point = 0; cin >> power;
        while(left <= right) {
            int mid = (left+right)/2;
            if(names[mid].second < power) left = mid + 1;
            else if(names[mid].second > power) {
                point = mid;
                right = mid - 1;
            }
            else {
                point = mid;
                break;
            }
        }
        cout << names[point].first << '\n';
    }
}
#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int dx[4] = {0,0,1,-1}, dy[4] = {1,-1,0,0}, ylen, xlen;
vector<string> fixed_storage;

void bfs(char c) {
    queue<pair<int,int>> q; q.push({0,0});
    while(q.size()) {
        int x = q.front().second, y = q.front().first;
        q.pop();
        for(int i = 0; i < 4; i++) {
            int ax = x + dx[i];
            int ay = y + dy[i];
            if(ay >= ylen or ay < 0 or ax >= xlen or ax < 0) continue;
            if(fixed_storage[ay][ax] == c) {
                fixed_storage[ay][ax] = '1';
            }
            if(fixed_storage[ay][ax] == '0') {
                fixed_storage[ay][ax] = '1';
                q.push({ay,ax});
            }
        }
    }
}

int solution(vector<string> storage, vector<string> requests) {
    int answer = 0;
    ylen = storage.size()+2;
    xlen = storage[0].size()+2;
    string tmp(storage[0].size()+2,'0');
    fixed_storage.push_back(tmp);
    for(string s : storage) {
        fixed_storage.push_back("0" + s + "0");
    }
    fixed_storage.push_back(tmp);
    for(string request : requests) {
        if(request.size() == 2) {
            for(int i = 0; i < ylen; i++) {
                for(int j = 0; j < xlen; j++) {
                    if(request[0] == fixed_storage[i][j]) {
                        fixed_storage[i][j] = '0';
                        // able_pop.push_back({i,j});
                    }
                }
            }
        }
        else {
            bfs(request[0]);
            for(int i = 0; i < ylen; i++) {
                for(int j = 0; j < xlen; j++) {
                    if('1' == fixed_storage[i][j]) {
                        fixed_storage[i][j] = '0';
                        // able_pop.push_back({i,j});
                    }
                }
            }
        }
    }
    cout << ylen << ' ' << xlen << '\n';
    for(int i = 0; i < ylen; i++) {
        for(int j = 0; j < xlen; j++) {
            if(fixed_storage[i][j] != '0') {
                answer++;
            }
            cout << fixed_storage[i][j] << ' ';
        }
        cout << '\n';
    }
    return answer;
}
#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

int bfs(pair<int,int> pos, vector<vector<int>>& board, int xlimit, int ylimit) {
    board[pos.second][pos.first] = 1;
    queue<pair<int,int>> q; q.push(pos);
    while(q.size()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++) {
            int ax = x + dx[i];
            int ay = y + dy[i];
            if(ax >= xlimit or ay >= ylimit or ay < 0 or ax < 0) continue;
            if(board[ay][ax] == -777) return board[y][x];
            if(board[ay][ax] != 0) continue;
            board[ay][ax] = board[y][x] + 1;
            q.push({ax,ay});
        }
    }
    return -1;
}

void print_graph(vector<vector<int>>& board) {
    for(vector<int> b : board) {
        for(int i : b) {
            cout << i << ' ';
        }
        cout << '\n';
    }
}

int solution(vector<string> maps) {
    vector<vector<int>> to_labber, to_exit;
    int len_x = maps[0].size(),len_y = 0;
    pair<int,int> posS,posL;
    for(string s : maps) {
        vector<int> tmp1,tmp2;
        for(int i = 0; i < len_x; i++) {
            if(s[i] == 'L') {
                tmp1.push_back(-777);
                tmp2.push_back(0);
                posL = {i,len_y};
            }
            else if(s[i] == 'O') {
                tmp1.push_back(0);
                tmp2.push_back(0);
            }
            else if(s[i] == 'X') {
                tmp1.push_back(-1);
                tmp2.push_back(-1);
            }
            else if(s[i] == 'E') {
                tmp1.push_back(0);
                tmp2.push_back(-777);
            }
            else if(s[i] == 'S') {
                tmp1.push_back(0);
                tmp2.push_back(0);
                posS = {i,len_y};
            }
        }
        to_labber.push_back(tmp1);
        to_exit.push_back(tmp2);
        len_y++;
    }
    int a1 = bfs(posS,to_labber,len_x,len_y);
    int a2 = bfs(posL,to_exit,len_x,len_y);
    print_graph(to_labber);
    print_graph(to_exit);
    if(a1 == -1 or a2 == -1) return -1;
    return a1+a2;
}
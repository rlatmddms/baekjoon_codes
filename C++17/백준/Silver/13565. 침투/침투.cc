#include <iostream>
#include <vector>

using namespace std;

int n,m;
vector<string> board; 
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

void dfs(int x, int y) {
    if(board[y][x] == '0') {
        board[y][x] = '2';
        for(int i = 0; i < 4; i++) {
            int ax = x+dx[i], ay = y+dy[i];
            if(ax < 0 || ax == m || ay < 0 || ay == n) continue;
            dfs(ax,ay);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        string str;
        cin >> str;
        board.push_back(str);
    }
    for(int i = 0; i < m; i++) {
        dfs(i,0);
    }
    for(int i = 0; i < m; i++) {
        if(board[n-1][i] == '2') {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
}
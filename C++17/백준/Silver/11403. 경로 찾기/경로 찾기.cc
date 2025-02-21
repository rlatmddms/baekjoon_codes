#include<iostream>

#include<vector>

#include<queue>

using namespace std;

vector<int> board[101];

bool visit[101][101];

int n;

void bfs(int l) {

    queue<int> q;

    q.push(l);

    while(q.size()){

        int v = q.front(); q.pop();

        for(int i = 0; i < n; i++) {

            if(board[v][i] == 0 || visit[l][i] == true) continue;

            visit[l][i] = true;

            board[l][i] = 1;

            q.push(i);

        }

    }

}

int main() {

    cin >> n;

    for(int i = 0; i < n; i++) {

        for(int j = 0; j < n; j++) {

            int tmp; cin >> tmp;

            board[i].push_back(tmp);

        }

    }

    for(int i = 0; i < n; i++) {

        bfs(i);

    }

    for(int i = 0; i < n; i++) {

        for(int j = 0; j < n; j++) {

            cout << board[i][j] << ' ';

        }

        cout << '\n';

    }

}
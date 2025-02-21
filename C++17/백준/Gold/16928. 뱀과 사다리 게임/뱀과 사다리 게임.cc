#include<iostream>
#include<queue>
using namespace std;


int visit[101] = {};

int bfs() {
    queue<int> q;
    int x = 1;
    if(visit[1] > 0) 
        x = visit[1];
    visit[1] = -1;
    visit[x] = -1;
    q.push(x);
    int cnt = 0;
    while(!q.empty()) {
        x = q.front(); q.pop();
        if(x == 100) return visit[x];
        // cout << visit[x] << ' ' << x << "   ";
        for(int i = 1; i <= 6; i++) {
            int ax = x+i;
            if(ax > 100) break;
            if(visit[ax] < 0) continue;
            // cout << ax << ' ';
            if(visit[ax] > 0) {
                if(visit[visit[ax]] < 0) continue;
                q.push(visit[ax]);
                visit[visit[ax]] = visit[x] -1;
                visit[ax] = visit[x] -1;
            }
            else {
                q.push(ax);
                visit[ax] = visit[x] -1;
            }
        }
        // cout << '\n';
    }
    return 0;
}

int main() {
    int n,m; cin >> n >> m;
    for(int i = 0; i < n+m; i++) {
        int nn, mm; cin >> nn >> mm;
        visit[nn] = mm;
    }
    int a = -1*(bfs())-1;
    cout << a;
    //for(int i = 1; i <= 100; i++) cout << i << ' ' <<  visit[i] << '\n';
}
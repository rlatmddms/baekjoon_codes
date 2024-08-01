#include <iostream>
#include <vector>
#include <algorithm>
#define ABS(x) (((x)<0) ? (-1)*(x) : (x))


using namespace std;

bool cmp1(pair<int,int> a, pair<int,int> b) {
    return a.first < b.first;
}

bool cmp2(int a, int b) {
    return a < b;
}

int main() {
    int n,m; cin >> n >> m;
    vector<int> b;
    vector<pair<int,int>> p;
    for(int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        b.push_back(tmp);
    }
    for(int i = 0; i < m; i++) {
        int tmp1,tmp2; cin >> tmp1 >> tmp2;
        p.push_back(make_pair(tmp1,tmp2));
    }
    sort(p.begin(),p.end(),cmp1);
    sort(b.begin(),b.end(),cmp2);
    vector<pair<int,int>> near_b;
    int distance=3000000,point = 0,max = 0;
    for(int i = 0; i < p.size(); i++) {
        distance=3000000;
        while(1) {
            if(ABS(p[i].first - b[point]) < distance) distance = ABS(p[i].first - b[point]);
            else{
                point--;
                near_b.push_back(make_pair(point,distance));
                if(max < distance*p[i].second) max = distance*p[i].second;
                break;
            }
            point++;
            if(point >= b.size()) {
                point--;
                if(max < distance*p[i].second) max = distance*p[i].second;
                near_b.push_back(make_pair(point,distance));
                break;
            }
        }
    }
    cout << max;
}
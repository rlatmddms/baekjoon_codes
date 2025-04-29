#include <string>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int change_int(string a) {
    int i = 1, sum = 0;
    while(a.size()) {
        sum += (a.back() - '0') * i;
        i *= 10;
        a.pop_back();
    }
    return sum;
}

bool cmp(tuple<string,string,string,int> a, tuple<string,string,string,int> b) {
    if(get<0>(a) == get<0>(b)) {
        // if(change_int(get<1>(a)) == change_int(get<1>(b))) {
        //     return true;
        // }
        if(change_int(get<1>(a)) == change_int(get<1>(b))) return get<3>(a) < get<3>(b);
        return change_int(get<1>(a)) < change_int(get<1>(b));
    }
    return get<0>(a) < get<0>(b);
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<tuple<string,string,string,int>> dd;
    for(int idx = 0; idx < files.size(); idx++) {
        tuple<string,string,string,int> tp("","","",idx);
        int i = 0;
        for(char c : files[idx]) {
            if(c >= 'a' and c <= 'z') c = c-32;
            if(i == 0) {
                if(c >= '0' and c <= '9'){
                    i++;
                    get<1>(tp).push_back(c);
                }
                else{
                    get<0>(tp).push_back(c);
                }
            }
            else if(i == 1) {
                if(c < '0' or c > '9'){
                    i++;
                    get<2>(tp).push_back(c);
                }
                else{
                    get<1>(tp).push_back(c);
                }
            }
            else {
                get<2>(tp).push_back(c);
            }
        }
        dd.push_back(tp);
    }
    
    sort(dd.begin(),dd.end(),cmp);
    for(int i = 0; i < dd.size(); i++) {
        answer.push_back(files[get<3>(dd[i])]);
    }
    return answer;
}
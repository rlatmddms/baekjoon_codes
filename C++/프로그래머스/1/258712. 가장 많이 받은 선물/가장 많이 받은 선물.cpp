#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    unordered_map<string,int> friend_id;
    for(int i = 0; i < friends.size(); i++) {
        friend_id[friends[i]] = i;
    }
    vector<vector<int>> gift_log(friends.size(), vector<int>(friends.size(),0));
    for(int i = 0; i < gifts.size(); i++) {
        string tmp[2];
        int idx = 0;
        for(char c : gifts[i]) {
            if(c == ' ') {
                idx++;
                continue;
            }
            tmp[idx].push_back(c);
        }
        gift_log[friend_id[tmp[0]]][friend_id[tmp[1]]] += 1;
    }
    for(int i = 0; i < friends.size(); i++) {
        int give_sum = 0, recieve_sum = 0;
        for(int j = 0; j < friends.size(); j++) {
            give_sum += gift_log[i][j];
            recieve_sum += gift_log[j][i];
        }
        gift_log[i][i] = give_sum - recieve_sum;
    }
    vector<int> next_gift_log(friends.size(),0);
    for(int i = 0; i < friends.size(); i++) {
        for(int j = i+1; j < friends.size(); j++) {
            if(gift_log[i][j] == gift_log[j][i]) {
                if(gift_log[i][i] == gift_log[j][j]) {
                    continue;
                }
                if(gift_log[i][i] < gift_log[j][j]) {
                    next_gift_log[j]++;
                }
                else {
                    next_gift_log[i]++;
                }
            }
            else if(gift_log[i][j] < gift_log[j][i]) {
                next_gift_log[j]++;
            }
            else {
                next_gift_log[i]++;
            }
        }
    }
    for(int i = 0; i < next_gift_log.size(); i++)
        if(next_gift_log[i] > answer) answer = next_gift_log[i];
    return answer;
}
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    unordered_map<string,string> hash_map;
    for(string log : record) {
        string cmd[3]; int i = 0;
        for(char c : log) {
            if(c == ' ') {
                i++;
                continue;
            }
            cmd[i].push_back(c);
        }
        if(cmd[0] == "Enter" || cmd[0] == "Change") {
            hash_map[cmd[1]] = cmd[2];
        }
    }
    for(string log : record) {
        string cmd[3]; int i = 0;
        for(char c : log) {
            if(c == ' ') {
                i++;
                continue;
            }
            cmd[i].push_back(c);
        }
        if(cmd[0] == "Enter") {
            answer.push_back(hash_map[cmd[1]] + "님이 들어왔습니다.");
        }
        else if(cmd[0] == "Leave") {
            answer.push_back(hash_map[cmd[1]] + "님이 나갔습니다.");
        }
        else continue;
    }
    return answer;
}
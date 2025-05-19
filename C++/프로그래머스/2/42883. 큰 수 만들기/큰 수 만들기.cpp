#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    for(char c : number){
        while (answer.size() != 0 and k > 0 and c > answer.back()){
            answer.pop_back();
            k--;
        }
        answer.push_back(c);
    }
    while(answer.size() != 0 and k > 0) {
        k--;
        answer.pop_back();
    }
    return answer;
}
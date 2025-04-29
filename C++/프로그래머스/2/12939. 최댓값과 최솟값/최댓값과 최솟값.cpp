#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 문자열을 숫자로 바꾸어주는 함수
long long change_int(string s) {
    long long sum = 0, i = 1, is_minus = 0;
    if(s[0] == '-') is_minus = 1;
    while(s.size()>is_minus) {
        sum += (s.back() - '0')*i; // 자릿수에 맞게 곱해주며 더하고
        i*=10;                     // 자리수를 하나씩 증가시키기
        s.pop_back();
    }
    if(is_minus) return -1*sum;
    return sum;
}

string change_str(long long n) {
    if(n == 0) return "0";
    string s = "",reverse_s = "";
    if(n < 0) {
        n*=-1;
        reverse_s.push_back('-'); 
    }
    while(n > 0) {
        s.push_back((n%10) + '0');
        n/=10;
    }
    while(s.size()) {
        reverse_s.push_back(s.back());
        s.pop_back();
    }
    return reverse_s;
}

string solution(string s) {
    s.push_back(' ');
    string answer = "", buff = "";
    long long max = -9000000000000000000, min = 9000000000000000000;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == ' ') {
            if(buff == "") continue;
            long long buff_int = change_int(buff);
            // cout << buff << ' ' << buff_int << endl;
            max = buff_int > max ? buff_int : max;
            min = buff_int < min ? buff_int : min;
            buff = "";
        }
        else{
            buff.push_back(s[i]);
        }
    }
    // cout << min << ' ' << max;
    // 띄어쓰기가 나오면 버퍼의 값을 숫자로 변환하여 크기를 비교함. 
    
    answer = change_str(min) + " " + change_str(max);
    // 최소값과 최대값을 문자열로 바꾼 후 띄어쓰기로 구분함.
    return answer;
}
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 0, len;
    len = s.length();
    answer = len;
    for (int i = 1; i <= len / 2; i++) {
        string temp = "", compare = "", zip = "";
        int cnt = 0;
        compare = s.substr(0, i);
        for (int j = 0; j < len; j+=i) {
            temp = s.substr(j, i);
            if (temp != compare) {
                if (cnt != 1)
                    zip += to_string(cnt);
                zip += compare;
                compare = temp;
                cnt = 1;
            }
            else 
                cnt++;
        }
        if (cnt != 1)
            zip += to_string(cnt);
        zip += compare;
        answer = min(answer, (int)zip.length());
    }
    return answer;
}

int main() {
    cout << solution("abcabcabcabcdededededede") << '\n';
}
#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool check(string s) {
    int num = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(')
            num++;
        else
            num--;
        if (num < 0)
            return false;
    }
    return true;
}

string solution(string p) {
    string answer = "", u, v;
    int cnt = 0, mid;

    if (p == "")
        return answer;
    for (int i = 0; i < p.length(); i++) {
        if (p[i] == '(')
            cnt++;
        else
            cnt--;
        if (cnt == 0) {
            mid = i;
            break;
        }
    }
    u = p.substr(0, mid + 1);
    v = p.substr(mid + 1, p.length() - mid - 1);
    if (check(u))
        answer = u + solution(v);
    else {
        answer += '(';
        answer += solution(v);
        answer += ')';
        u = u.substr(1, u.length() - 2);
        for (int i = 0; i < u.length(); i++) {
            if (u[i] == '(')
                u[i] = ')';
            else
                u[i] = '(';
        }
        answer += u;
    }
    return answer;
}

int main() {
    string a = "(()())()";
    solution(a);

    return 0;
}
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
vector<string> arr[10001];
vector<string> r_arr[10001];

int cnt_queries(vector<string> v, string left, string right) {
    vector<string>::iterator low = lower_bound(v.begin(), v.end(), left);
    vector<string>::iterator upper = upper_bound(v.begin(), v.end(), right);
    return upper - low;
}

string change(string str, string from, string to) {
    string res = str;
    int pos = 0;
    while ((pos = res.find(from, pos)) != string::npos) {
        res.replace(pos, from.size(), to);
        pos += to.size();
    }
    return res;
}
vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;

    for (int i = 0; i < words.size(); i++) {
        string word = words[i];
        arr[word.size()].push_back(word);
        reverse(word.begin(), word.end());
        r_arr[word.size()].push_back(word);
    }

    for (int i = 0; i < 10001; i++) {
        sort(arr[i].begin(), arr[i].end());
        sort(r_arr[i].begin(), r_arr[i].end());
    }

    for (int i = 0; i < queries.size(); i++) {
        string str = queries[i];
        int len = str.size(), cnt;
        if (str[0] == '?') {
            reverse(str.begin(), str.end());
            cnt = cnt_queries(r_arr[len], change(str, "?", "a"), change(str, "?", "z"));
        }
        else
            cnt = cnt_queries(arr[len], change(str, "?", "a"), change(str, "?", "z"));
        answer.push_back(cnt);
    }

    return answer;
}

int main() {
    vector<string> a = { "frodo", "front", "frost", "frozen", "frame", "kakao" };
    vector<string> b = { "fro??", "????o", "fr???", "fro???", "pro?" };

    vector<int> answer = solution(a, b);

    for (int i = 0; i < answer.size(); i++)
        cout << answer[i] << ' ';

    return 0;
}
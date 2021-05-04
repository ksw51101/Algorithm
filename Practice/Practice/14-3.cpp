#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool compare(pair<double, int> a, pair<double, int> b) {
    if (a.first == b.first)
        return a.second < b.second;
    return a.first > b.first;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<double, int>> v;
    int num = stages.size();
    for (int i = 1; i <= N; i++) {
        int cnt = count(stages.begin(), stages.end(), i);
        double fail = (double)cnt / num;
        v.push_back({ fail, i });
        num -= cnt;
    }
    sort(v.begin(), v.end(), compare);
    for (int i = 0; i < v.size(); i++)
        answer.push_back(v[i].second);
    return answer;
}

int main() {
    int n = 5;
    vector<int> stages;
    stages.push_back(2);
    stages.push_back(1);
    stages.push_back(2);
    stages.push_back(6);
    stages.push_back(2);
    stages.push_back(4);
    stages.push_back(3);
    stages.push_back(3);
    vector<int> a = solution(n, stages);
    
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << ' ';
    return 0;
}
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool compare1(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first)
        return a.second < b.second;
    return a.first > b.first;
}
bool compare2(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int solution(vector<int> food_times, long long k) {
    long long sum = 0;
    for (int i = 0; i < food_times.size(); i++) {
        sum += food_times[i];
    }
    if (sum <= k) return -1;
        
    vector<pair<int, int>> vec;
    int answer = 0, num = food_times.size(), index = num - 1, last_index;
    for (int i = 0; i < num; i++) {
        vec.push_back({ food_times[i], i + 1 });
    }
    sort(vec.begin(), vec.end(), compare1);
    while (vec[index].first * num <= k) {
        k -= vec[index].first * num;
        last_index = vec[index].second;
        index--;
        num--;
        vec.pop_back();
    }
    sort(vec.begin(), vec.end(), compare2);

    answer = k + last_index + 1;
    if (answer > food_times.size())
        answer -= food_times.size();

    return answer;
}

int main() {
    vector<int> food_times;
    food_times.push_back(3);
    food_times.push_back(1);
    food_times.push_back(2);
    cout << solution(food_times, 4) << '\n';
}
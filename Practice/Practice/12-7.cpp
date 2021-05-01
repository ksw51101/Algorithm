#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

bool compare(int a, int b) {
    return a > b;
}

bool check_finish(vector<bool> flag) {
    for (int i = 0; i < flag.size(); i++) {
        if (flag[i] == false)
            return false;
    }
    return true;
}

int check(vector<int> weak, int location, int dist, vector<bool> *flag, int n) {
    int index;
    int new_location = (weak[location] + dist) % n;
    for (int j = 0; j < weak.size(); j++) {
        int i = (location + j) % weak.size();
        if (new_location < weak[location]) {
            if (weak[i] >= weak[location] || weak[i] <= new_location) {
                (*flag)[i] = true;
                index = i;
            }
        }
        else if (weak[i] >= weak[location] && weak[i] <= new_location) {
            (*flag)[i] = true;
            index = i;
        }
    }
    return index;
}

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = dist.size() + 1;
    vector<bool> flag(weak.size());
    sort(dist.begin(), dist.end(), compare);
    for (int i = 0; i < weak.size(); i++) {
        int num=0, location = i;
        fill(flag.begin(), flag.end(), false);
        for (int j = 0; j < dist.size(); j++) {
            num++;
            location = (check(weak, location, dist[j], &flag, n) + 1) % weak.size();
            if (check_finish(flag)) {
                answer = min(answer, num);
                break;
            }
        }
    }
    if (answer == dist.size() + 1)
        return -1;
    return answer;
}

int main() {
    int n = 12;
    vector<int> weak;
    vector<int> dist;
    weak.push_back(1);
    weak.push_back(3);
    weak.push_back(4);
    weak.push_back(9);
    weak.push_back(10);
    dist.push_back(3);
    dist.push_back(5);
    dist.push_back(7);

    cout << solution(n, weak, dist) << '\n';
}
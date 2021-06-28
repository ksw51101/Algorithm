#include <iostream>
#include <queue>
#include <set>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int k, ans = 0;
string n;
queue<pair<string, int>> q;

bool find(string s, vector<string> vec) {
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i] == s)
			return true;
	}
	return false;
}

int main() {
	cin >> n >> k;

	q.push({ n, k });

	while (!q.empty()) {
		set<string> visited;
		string temp = q.front().first;
		int num = q.front().second;
		q.pop();
		if (num == 0) {
			ans = max(ans, stoi(temp));
			continue;
		}

		for (int i = 0; i < temp.size() - 1; i++) {
			for (int j = i + 1; j < temp.size(); j++) {
				swap(temp[i], temp[j]);
				if (temp[0] == '0') {
					swap(temp[i], temp[j]);
					continue;
				}
				if (visited.count(temp) != 0) {
					swap(temp[i], temp[j]);
					continue;
				}
				visited.insert(temp);
				q.push({ temp, num - 1 });
				swap(temp[i], temp[j]);
			}
		}
	}
	if (ans == 0)
		cout << -1 << '\n';
	else
		cout << ans << '\n';

	return 0;
}
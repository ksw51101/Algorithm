#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

int k, ans = 0;;
string n;
queue<pair<string, int>> q;
bool visited[1000001][11];

int main() {
	cin >> n >> k;

	q.push({ n, k });

	while (!q.empty()) {
		string temp = q.front().first; // 값
		int num = q.front().second; // 남은 연산 수
		q.pop();
		if (num == 0) { // k번 만큼의 연산이 끝난 경우
			ans = max(ans, stoi(temp)); // ans 갱신
			continue;
		}

		for (int i = 0; i < temp.size() - 1; i++) {
			for (int j = i + 1; j < temp.size(); j++) {
				swap(temp[i], temp[j]); // i번째 자리수와 j번째 자리수 swap
				if (temp[0] == '0' || visited[stoi(temp)][num - 1] == true) { // swap된 수의 첫번째 자리수가 0이거나 이미 만들어졌던 수일 경우 다시 swap
					swap(temp[i], temp[j]);
					continue;
				}
				visited[stoi(temp)][num - 1] = true; // 방문처리
				q.push({ temp, num - 1 }); // q에 삽입
				swap(temp[i], temp[j]); // 원래대로 swap
			}
		}
	}
	if (ans == 0) // 1자리 수 또는 2자리 수 중 0으로 끝나는 수 등 k번만큼의 연산이 불가능한 경우
		cout << -1 << '\n';
	else
		cout << ans << '\n';

	return 0;
}
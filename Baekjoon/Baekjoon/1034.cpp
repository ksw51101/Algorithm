#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, k;
string str;
vector<pair<string, int>> vec; // n개의 행 중 같은 문자열의 개수를 count

// pair중 second 기준 내림차순 정렬을 위한 함수
bool compare(pair<string, int> a, pair<string, int> b) {
	return a.second > b.second;
}

// 입력 문자열 s의 0의 개수 return
int counter(string s) {
	int cnt = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '0')
			cnt++;
	}
	return cnt;
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> str;
		if (vec.empty()) { // vec가 비어있으면 첫번째 입력이므로 second에 1을 포함시켜 push_back
			vec.push_back({ str, 1 });
		}
		else {
			for (int j = 0; j <= vec.size(); j++) {
				if (j == vec.size()) { // vec에 없는 문자열이므로 second에 1을 포함시켜 push_back
					vec.push_back({ str, 1 });
					break;
				}
				if (vec[j].first == str) { // 이미 있었던 문자열이므로 second++
					vec[j].second++;
					break;
				}
			}
		}

	}
	cin >> k;

	sort(vec.begin(), vec.end(), compare); // 문자열이 많이 나온 순서대로 정렬

	for (int i = 0; i <= vec.size(); i++) {
		if (i == vec.size()) { // 가능한 경우가 없으므로 0 출력
			cout << 0 << '\n';
			break;
		}
		int num = counter(vec[i].first);
		if (num <= k && (k - num) % 2 == 0) { // k가 num보다 적을 경우 켜져 있는 경우를 만들 수가 없고, 크더라도 num과의 차이가 짝수일 경우에만 켜져 있는 상태를 만들 수 있음
			cout << vec[i].second << '\n';
			break;
		}
	}

	return 0;
}
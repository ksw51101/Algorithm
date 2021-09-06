#include <iostream>
#include <vector>
using namespace std;

int n;

// 카드를 셔플하는 함수
vector<int> shuffle(vector<int> s, vector<int> p) {
	vector<int> temp(n);
	for (int i = 0; i < n; i++) {
		temp[s[i]] = p[i];
	}
	return temp;
}

int main() {
	cin >> n;
	vector<int> p(n), s(n), target(n);

	for (int i = 0; i < n; i++) {
		cin >> p[i];
		target[i] = i % 3; // 카드가 0, 1, 2 플레이어 순으로 끝까지 돌아가야 함
	}
	vector<int> save = p; // 초기상태 저장
	for (int i = 0; i < n; i++)
		cin >> s[i];

	int ans = 0; // 셔플 횟수
	while (1) {
		if (target == p) { // 목표대로 카드가 돌아갔으면 정답 출력
			cout << ans << '\n';
			break;
		}
		p = shuffle(s, p); // 카드 셔플
		ans++; // 셔플 횟수 증가
		if (p == save) { // 사이클이 발생하면 -1 출력
			cout << -1 << '\n';
			break;
		}
	}

	return 0;
}
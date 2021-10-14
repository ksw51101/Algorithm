#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

int m, ans;
string n;
bool broken[10]; // 고장난 버튼은 true, 아니면 false

// s부터 n까지 이동하는데 걸리는 횟수를 구하고 문자열을 추가하여 재귀하는 함수
void solution(string s) {
	if (s != "") // s가 빈 문자열이 아닐경우
		ans = min(ans, (int)s.size() + abs(stoi(n) - stoi(s))); // 최솟값이 ans 갱신(s의 길이(버튼횟수) + s부터 n까지 이동하는 횟수)
	for (int i = 0; i < 10; i++) {
		if (!broken[i] && s.size() <= n.size()) { // 버튼이 고장나지 않았고 (s의 길이)+1이 (n의 길이)+1 이하일 경우
			solution(s + to_string(i)); // 문자열 추가하여 재귀
		}
	}
}

int main() {
	fill(&broken[0], &broken[10], false); // 버튼이 고장나지 않은 상태로 초기화
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int temp;
		cin >> temp;
		broken[temp] = true; // 고장난 버튼 false로 변경
	}
	ans = abs(stoi(n) - 100); // +, - 버튼만 이용하였을 때를 최솟값으로 설정

	solution("");
	cout << ans << '\n';

	return 0;
}
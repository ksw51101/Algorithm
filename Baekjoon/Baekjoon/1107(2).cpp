#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

int m, ans;
string n;
bool broken[10]; // 고장난 버튼은 true, 아니면 false

// s부터 n까지 이동하는데 걸리는 횟수를 구하고 문자열을 추가하여 재귀하는 함수
bool solution(string s) {
	for (int i = 0; i < s.size(); i++) {
		if (broken[s[i] - '0'])
			return false;
	}
	return true;
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int temp;
		cin >> temp;
		broken[temp] = true; // 고장난 버튼 false로 변경
	}
	ans = abs(stoi(n) - 100); // +, - 버튼만 이용하였을 때를 최솟값으로 설정

	for (int i = 0; i < ans; i++) {
		int up = stoi(n) + i;
		int down = stoi(n) - i;
		if (solution(to_string(up)))
			ans = min(ans, (int)to_string(up).size() + i);
		if (down >= 0 && solution(to_string(down)))
			ans = min(ans, (int)to_string(down).size() + i);
	}
	cout << ans << '\n';

	return 0;
}
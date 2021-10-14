#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

int m, ans;
string n;
bool broken[10]; // ���峭 ��ư�� true, �ƴϸ� false

// s���� n���� �̵��ϴµ� �ɸ��� Ƚ���� ���ϰ� ���ڿ��� �߰��Ͽ� ����ϴ� �Լ�
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
		broken[temp] = true; // ���峭 ��ư false�� ����
	}
	ans = abs(stoi(n) - 100); // +, - ��ư�� �̿��Ͽ��� ���� �ּڰ����� ����

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
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

int m, ans;
string n;
bool broken[10]; // ���峭 ��ư�� true, �ƴϸ� false

// s���� n���� �̵��ϴµ� �ɸ��� Ƚ���� ���ϰ� ���ڿ��� �߰��Ͽ� ����ϴ� �Լ�
void solution(string s) {
	if (s != "") // s�� �� ���ڿ��� �ƴҰ��
		ans = min(ans, (int)s.size() + abs(stoi(n) - stoi(s))); // �ּڰ��� ans ����(s�� ����(��ưȽ��) + s���� n���� �̵��ϴ� Ƚ��)
	for (int i = 0; i < 10; i++) {
		if (!broken[i] && s.size() <= n.size()) { // ��ư�� ���峪�� �ʾҰ� (s�� ����)+1�� (n�� ����)+1 ������ ���
			solution(s + to_string(i)); // ���ڿ� �߰��Ͽ� ���
		}
	}
}

int main() {
	fill(&broken[0], &broken[10], false); // ��ư�� ���峪�� ���� ���·� �ʱ�ȭ
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int temp;
		cin >> temp;
		broken[temp] = true; // ���峭 ��ư false�� ����
	}
	ans = abs(stoi(n) - 100); // +, - ��ư�� �̿��Ͽ��� ���� �ּڰ����� ����

	solution("");
	cout << ans << '\n';

	return 0;
}
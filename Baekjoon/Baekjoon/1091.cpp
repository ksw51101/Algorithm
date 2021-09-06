#include <iostream>
#include <vector>
using namespace std;

int n;

// ī�带 �����ϴ� �Լ�
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
		target[i] = i % 3; // ī�尡 0, 1, 2 �÷��̾� ������ ������ ���ư��� ��
	}
	vector<int> save = p; // �ʱ���� ����
	for (int i = 0; i < n; i++)
		cin >> s[i];

	int ans = 0; // ���� Ƚ��
	while (1) {
		if (target == p) { // ��ǥ��� ī�尡 ���ư����� ���� ���
			cout << ans << '\n';
			break;
		}
		p = shuffle(s, p); // ī�� ����
		ans++; // ���� Ƚ�� ����
		if (p == save) { // ����Ŭ�� �߻��ϸ� -1 ���
			cout << -1 << '\n';
			break;
		}
	}

	return 0;
}
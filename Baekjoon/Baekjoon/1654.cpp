#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
long long maximum = 0, l, r, ans = 0;
vector<int> vec;

int main() {
	cin >> k >> n;

	for (int i = 0; i < k; i++) {
		long long temp;
		cin >> temp;
		vec.push_back(temp);
		maximum = max(maximum, temp);
	}
	l = 1, r = maximum;

	// �̺�Ž��
	while (r >= l) {
		long long len = (r + l) / 2;
		int num = 0;
		for (int i = 0; i < k; i++)
			num += vec[i] / len; // �ڸ��� ���� ������ �������� ��� �Ǵ� ������ ��
		if (num < n) // ������ ��ǥġ���� ���� ��� �ڸ��� ���̸� �ٿ��� ������ �ø�
			r = len - 1;
		else { // ������ ��ǥġ �̻��� ��� �ڸ��� ���̸� �÷��� �õ�
			l = len + 1;
			ans = max(ans, len);
		}
	}
	cout << ans << '\n';

	return 0;
}
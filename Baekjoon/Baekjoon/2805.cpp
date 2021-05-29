#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long n, m, l, r, maximum = 0, ans = 0;
vector<int> vec;

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		long long temp;
		cin >> temp;
		vec.push_back(temp);
		maximum = max(maximum, temp);
	}

	l = 1, r = maximum;

	// �̺�Ž��
	while (l <= r) {
		long long mid = (l + r) / 2, len = 0;
		for (int i = 0; i < n; i++) {
			if (vec[i] > mid)
				len += vec[i] - mid; // �������� �Ǵ� ������ ����
		}
		if (len >= m) { // ����� ���̸� ������� �ڸ��� ���̸� �÷� �ٽ� �õ�
			l = mid + 1;
			ans = max(ans, mid);
		}
		else { // ���̰� �����ϴٸ� �ڸ��� ���̸� �ٿ� ��� �Ǵ� ���̸� �ø�
			r = mid - 1;
		}
	}
	cout << ans << '\n';

	return 0;
}
#include <iostream>
#include <algorithm>
using namespace std;

int n, k;

int main() {
	cin >> n >> k;

	int start = 1, end = k, ans = 0;

	// �̺�Ž��
	while (start <= end) {
		int mid = (start + end) / 2;
		long long num = 0;

		// mid ������ ������ ���� ã��
		for (int i = 1; i <= n; i++) 
			num += min(n, mid / i);

		if (num < k) { // mid ������ ������ ������ k���� ���� ��� ���� �� �� �����Ƿ� start�� �÷��� �ٽ� �õ�
			start = mid + 1;
		}
		else { // mid ������ ������ ������ k�̻��� ��� ���� �� �� �����Ƿ� ans�� ���� �� end�� �ٿ��� �� ���� ���� �ִ��� Ȯ��
			end = mid - 1;
			ans = mid;
		}
	}
	cout << ans << '\n';

	return 0;
}
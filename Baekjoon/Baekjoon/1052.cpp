#include <iostream>
#include <bitset>
using namespace std;

int n, k;

// ������ �ִ��� ���� ���� �ּҷ� �ٿ��� ���� ���� ���� ���ϴ� �Լ�
int cnt(bitset<32> bs) {
	int temp = 0;
	for (int i = 0; i < 32; i++) {
		if (bs[i])
			temp++;
	}
	return temp;
}

int main() {
	int ans = 0;

	cin >> n >> k;

	while (1) {
		bitset<32> bs(n);
		if (cnt(bs) <= k) // ��ǥ�� k ������ ��� break
			break;
		ans++;
		n++;
	}
	cout << ans << '\n';

	return 0;
}
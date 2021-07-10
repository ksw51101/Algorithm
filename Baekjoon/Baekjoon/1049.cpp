#include <iostream>
#include <algorithm>
using namespace std;

int n, m, min_package = 1000, min_peice = 1000, ans; // min_package : 6�� ��Ű���� �ּҰ���, min_peice : ������ �ּҰ���

int main() {
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		min_package = min(a, min_package);
		min_peice = min(b, min_peice);
	}
	bool flag;
	if (min_package < min_peice * 6)
		flag = true;
	else
		flag = false;

	if (!flag) // ������ 6�� �����ϴ� ������ ��Ű���� ���ݺ��� �� ��� �����θ� ����
		ans = n * min_peice;
	else { // ��Ű���� ��� �����ϴ� ���� ��Ű��+������ �����ϴ� ��� �� �ּҰ��� ����
		if (n % 6 == 0) 
			ans = n / 6 * min_package;
		else 
			ans = min((n / 6 + 1) * min_package, (n / 6 * min_package) + (n % 6 * min_peice));
	}
	cout << ans << '\n';

	return 0;
}
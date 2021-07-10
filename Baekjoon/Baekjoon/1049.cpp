#include <iostream>
#include <algorithm>
using namespace std;

int n, m, min_package = 1000, min_peice = 1000, ans; // min_package : 6개 패키지의 최소가격, min_peice : 낱개의 최소가격

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

	if (!flag) // 낱개를 6개 구매하는 가격이 패키지의 가격보다 싼 경우 낱개로만 구입
		ans = n * min_peice;
	else { // 패키지로 모두 구입하는 경우와 패키지+낱개로 구입하는 경우 중 최소값을 구함
		if (n % 6 == 0) 
			ans = n / 6 * min_package;
		else 
			ans = min((n / 6 + 1) * min_package, (n / 6 * min_package) + (n % 6 * min_peice));
	}
	cout << ans << '\n';

	return 0;
}
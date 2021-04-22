#include <iostream>
#include <algorithm>
using namespace std;

int n, m, money[100], sum[10001];

int main() {
	cin >> n >> m;

	fill(&sum[0], &sum[10002], 10001);
	sum[0] = 0;

	for (int i = 0; i < n; i++)
		cin >> money[i];

	for (int j = 0; j < n; j++) {
		int k = money[j];
		while (k <= m) {
			sum[k] = min(sum[k], sum[k - money[j]] + 1);
			k += money[j];
		}
	}

	if (sum[m] == 10001)
		cout << -1 << '\n';
	else
		cout << sum[m] << '\n';

	return 0;
}
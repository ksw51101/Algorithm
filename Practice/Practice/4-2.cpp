#include <iostream>
#include <algorithm>
using namespace std;

int n, m, k, num[1000], sum = 0, biggest_1, biggest_2;

int main() {
	cin >> n >> m >> k;

	for (int i = 0; i < n; i++)
		cin >> num[i];

	sort(num, num + n);

	/*while (1) {
		for (int j = 0; j < k && m > 0; j++) {
			sum += num[n - 1];
			m--;
		}
		if (m > 0) {
			sum += num[n - 2];
			m--;
		}
		else
			break;
	}*/
	biggest_1 = num[n - 1];
	biggest_2 = num[n - 2];

	int cnt = m / (k + 1);
	sum += cnt * k * biggest_1 + cnt * biggest_2;
	sum += m % (k + 1) * biggest_1;
	
	cout << sum << '\n';

	return 0;
}
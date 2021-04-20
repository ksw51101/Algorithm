#include <iostream>
using namespace std;

int n, k, cnt = 0;

int main() {
	cin >> n >> k;

	while (n != 1) {
		if (n % k == 0)
			n /= k;
		else
			n--;
		cnt++;
	}
	cout << cnt << '\n';

	return 0;
}
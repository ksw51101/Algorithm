#include <iostream>
using namespace std;

int n, cnt;

int main() {
	cin >> n;

	if (n < 3)
		cnt = 1575 * (n + 1);
	else if (n < 13)
		cnt = 1575 * n + 3600;
	else if (n < 23)
		cnt = 1575 * (n - 1) + 7200;
	else
		cnt = 1575 * (n - 2) + 10800;

	cout << cnt << '\n';

	return 0;
}
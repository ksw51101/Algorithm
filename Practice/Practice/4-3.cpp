#include <iostream>
using namespace std;

int main() {
	char x_c, y_c;
	int cnt = 0, x, y;

	cin >> x_c >> y_c;
	x = x_c - 'a' + 1;
	y = y_c - '1' + 1;

	if (y - 2 > 0) {
		if (x - 1 > 0)
			cnt++;
		if (x + 1 < 9)
			cnt++;
	}
	if (y - 1 > 0) {
		if (x - 2 > 0)
			cnt++;
		if (x + 2 < 9)
			cnt++;
	}
	if (y + 1 > 0) {
		if (x - 2 > 0)
			cnt++;
		if (x + 2 < 9)
			cnt++;
	}
	if (y + 2 > 0) {
		if (x - 1 > 0)
			cnt++;
		if (x + 1 < 9)
			cnt++;
	}
	cout << cnt << '\n';

	return 0;
}
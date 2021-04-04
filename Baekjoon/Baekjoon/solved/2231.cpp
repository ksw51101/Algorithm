#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, sum, num, minimum;

	cin >> n;
	minimum = n;

	for (int i = n - 1; i > 0; i--) {
		sum = 0;
		num = i;
		while (num > 0) {
			sum += num % 10;
			num /= 10;
		}
		if (i + sum == n) {
			minimum = min(minimum, i);
		}
	}
	if (minimum == n)
		cout << 0 << endl;
	else
		cout << minimum << endl;

	return 0;
}
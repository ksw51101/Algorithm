#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

int arr[11], n, maximum = INT_MIN, minimum = INT_MAX, oper[10];

void calculate() {
	int ans = arr[0];
	for (int i = 1; i < n; i++) {
		switch (oper[i - 1]) {
		case 1:
			ans += arr[i];
			break;
		case 2:
			ans -= arr[i];
			break;
		case 3:
			ans *= arr[i];
			break;
		case 4:
			ans /= arr[i];
			break;
		}
	}
	maximum = max(maximum, ans);
	minimum = min(minimum, ans);
}

void start(int index, int plus, int minus, int mul, int div) {
	if (index == n - 1) {
		calculate();
		return;
	}
	else {
		if (plus > 0) {
			oper[index] = 1;
			start(index + 1, plus - 1, minus, mul, div);
		}
		if (minus > 0) {
			oper[index] = 2;
			start(index + 1, plus, minus - 1, mul, div);
		}
		if (mul > 0) {
			oper[index] = 3;
			start(index + 1, plus, minus, mul - 1, div);
		}
		if (div > 0) {
			oper[index] = 4;
			start(index + 1, plus, minus, mul, div - 1);
		}
	}
}

int main() {
	int plus, minus, mul, div;

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
	cin >> plus >> minus >> mul >> div;

	start(0, plus, minus, mul, div);

	cout << maximum << '\n';
	cout << minimum << '\n';

	return 0;
}
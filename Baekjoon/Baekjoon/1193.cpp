#include <iostream>
using namespace std;

int main() {
	int X, sum = 0;

	cin >> X;

	for (int i = 1;; i++) {
		if (X > sum && X <= sum + i) {
			if (i % 2 == 0)
				cout << 1 + X - (sum + 1) << '/' << i - (X - (sum + 1)) << endl;
			else
				cout << i - (X - (sum + 1)) << '/' << 1 + X - (sum + 1) << endl;
			break;
		}

		sum += i;
	}
	return 0;
}
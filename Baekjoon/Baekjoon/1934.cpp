#include <iostream>
#include <algorithm>
using namespace std;

int t, a, b, LCM;

int main() {
	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> a >> b;
		if (a > b)
			swap(a, b);
		for (int j = 1; j <= a; j++)
			if (a % j == 0 && b % j == 0)
				LCM = j;

		LCM *= a / LCM * b / LCM;
		cout << LCM << '\n';
	}


	return 0;
}
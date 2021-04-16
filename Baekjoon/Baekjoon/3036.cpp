#include <iostream>
using namespace std;

int n, r[100];

int gcd(int a, int b) {
	int r; while (b != 0) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> r[i];

	for (int i = 1; i < n; i++) {
		int a = r[0], b = r[i];
		int gcd_ab = gcd(a, b);
		a /= gcd_ab;
		b /= gcd_ab;
		cout << a << '/' << b << '\n';
	}


	return 0;
}
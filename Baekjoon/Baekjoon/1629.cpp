#include <iostream>
using namespace std;

long long a, b, c;

long long start(int a, int b, int c) {
	if (a == 1)
		return 1;
	else if (b == 1)
		return a % c;
	else if (b % 2 == 0) {
		long long temp = start(a, b / 2, c);
		return (temp * temp) % c;
	}
	else
		return (a * start(a, b - 1, c)) % c;
}

int main() {
	cin >> a >> b >> c;

	cout << start(a, b, c) << '\n';

	return 0;
}
#include <iostream>
using namespace std;

int a, b, GCD, LCM;

int main() {
	cin >> a >> b;

	for (int i = 1; i <= a; i++)
		if (a % i == 0 && b % i == 0)
			GCD = i;

	LCM = GCD * a / GCD * b / GCD;

	cout << GCD << '\n' << LCM << '\n';

	return 0;
}
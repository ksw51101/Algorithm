#include <iostream>
#include <algorithm>
using namespace std;

int n, divisor[50];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> divisor[i];

	sort(divisor, divisor + n);

	cout << divisor[0] * divisor[n - 1] << '\n';

	return 0;
}
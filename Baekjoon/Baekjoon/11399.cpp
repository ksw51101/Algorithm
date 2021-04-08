#include <iostream>
#include <algorithm>
using namespace std;

int n, t[1000], sum = 0;

int main() {
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> t[i];

	sort(t, t + n);

	for (int i = 0; i < n; i++)
		sum += t[i] * (n - i);


	cout << sum << '\n';

	return 0;
}
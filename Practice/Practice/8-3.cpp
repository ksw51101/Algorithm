#include <iostream>
using namespace std;

int n, arr[1000] = { 0, };

int main() {
	cin >> n;

	arr[0] = 1;
	arr[1] = 3;
	for (int i = 2; i < n; i++)
		arr[i] = arr[i - 2] * 2 + arr[i - 1];

	cout << arr[n - 1] << '\n';

	return 0;
}
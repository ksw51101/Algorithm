#include <iostream>
#include <algorithm>
using namespace std;

int n, k, a[100000], b[100000];

int main() {
	cin >> n>>k;

	for (int i = 0; i < n; i++) 
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];

	sort(a, a + n);
	sort(b, b + n);

	for (int i = 0; i < k; i++)
		if (a[i] < b[n - i - 1])
			swap(a[i], b[n - i - 1]);
		else
			break;
	

	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += a[i];

	cout << sum << '\n';

	return 0;
}
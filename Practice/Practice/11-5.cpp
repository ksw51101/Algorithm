#include <iostream>
using namespace std;

int n, m, k[11] = { 0, }, ans = 0;

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int weight;
		cin >> weight;
		k[weight]++;
	}
	for (int i = 1; i <= 9; i++) {
		for (int j = i + 1; j <= 10; j++)
			ans += k[i] * k[j];
	}
	cout << ans << '\n';

	return 0;
}
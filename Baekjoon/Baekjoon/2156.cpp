#include <iostream>
#include <algorithm>
using namespace std;

int n, quantity[10001], maximum[10001], ans = 0;

void start(int pos) {
	if (pos == n + 1)
		return;

	maximum[pos] = max(max(maximum[pos - 3] + quantity[pos] + quantity[pos - 1], maximum[pos - 2] + quantity[pos]), maximum[pos - 1]);

	start(pos + 1);

}
int main() {
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> quantity[i];

	maximum[0] = maximum[0] = 0;
	maximum[1] = maximum[1] = quantity[1];
	if (n > 1) {
		maximum[2] = quantity[1] + quantity[2];
	}
	if (n > 2)
		start(3);

	cout << maximum[n] << '\n';

	return 0;
}
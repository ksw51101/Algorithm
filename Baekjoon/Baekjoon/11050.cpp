#include <iostream>
using namespace std;

long long n, k, C[1001][1001];

void solve() {
	for (int i = 0; i < 1001; i++) {
		C[i][0] = 1;
		C[i][1] = i;
	}
	for (int i = 1; i < 1001; i++) 
		for (int j = 1; j <= i; j++) 
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % 10007;
}

int main() {
		cin >> n >> k;

		solve();

		cout << C[n][k]<< '\n';

	return 0;
}
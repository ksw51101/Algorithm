#include <iostream>
using namespace std;

int main() {
	int n, t;
	long long P[101];

	cin >> t;
	P[1] = 1;
	P[2] = 1;
	P[3] = 1;
	P[4] = 2;
	P[5] = 2;
	for (int i = 6; i <= 100; i++)
		P[i] = P[i - 1] + P[i - 5];
	for (int i = 0; i < t; i++) {
		cin >> n;
		cout << P[n] << '\n';
	}

	return 0;
}
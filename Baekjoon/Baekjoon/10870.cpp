#include <iostream>
using namespace std;

int main() {
	int N, sum = 0, fibo[21];

	cin >> N;

	fibo[0] = 0;
	fibo[1] = 1;

	for (int i = 2; i <= N; i++)
		fibo[i] = fibo[i - 2] + fibo[i - 1];

	cout << fibo[N] << endl;

	return 0;
}
#include <iostream>
using namespace std;

int main() {
	int N, fac = 1;

	cin >> N;

	if (N == 0)
		fac = 1;
	else
		for (int i = 2; i <= N; i++)
			fac *= i;

	cout << fac << endl;

	return 0;
}
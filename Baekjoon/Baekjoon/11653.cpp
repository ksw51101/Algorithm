#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int N;

	cin >> N;

	if (N != 1) {
		for (int i = 2; i <= sqrt(N); i++) {
			if (N % i == 0) {
				cout << i << endl;
				N /= i;
				i--;
			}
		}
		cout << N << endl;
	}
	return 0;
}
#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int N, sum = 1;

	cin >> N;

	for (int i = 0;; i++) {
		sum += 6 * i;
		if (N <= sum) {
			cout << i + 1 << endl;
			break;
		}
	}
	return 0;
}
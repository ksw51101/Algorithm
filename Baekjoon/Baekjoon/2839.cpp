#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N, sum = 0, minimum;

	cin >> N;
	minimum = N;

	for (int i = N / 5; i >= 0; i--) {
		sum = i * 5;
		while (sum <= N) {
			if (sum == N)
				minimum = min(minimum, i + (N - i * 5) / 3);
			sum += 3;
		}
	}
	if (minimum != N)
		cout << minimum << endl;
	else
		cout << -1 << endl;

	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int main() {
	int M, N, sum = 0, minimum = 10000;
	vector<int> prime;
	bool flag;

	cin >> M >> N;
	for (int i = M; i <= N; i++) {
		if (i == 1)
			continue;
		else if (i == 2)
			prime.push_back(i);
		else {
			flag = true;
			for (int j = 2; j <= sqrt(i); j++) {
				if (i % j == 0) {
					flag = false;
					break;
				}
			}
			if (flag)
				prime.push_back(i);
		}
	}
	if (prime.empty())
		cout << -1 << endl;
	else {
		for (int i = 0; i < prime.size(); i++) {
			minimum = min(minimum, prime[i]);
			sum += prime[i];
		}
		cout << sum << endl;
		cout << minimum << endl;
	}

	return 0;
}
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

long long T, x, y, dist;

int main() {

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> x >> y;

		dist = y - x;

		for (long long j = 1;; j++) {
			if (sqrt(dist) == j) {
				cout << 1 + (j - 1) * 2 << endl;
				break;
			}
			else {
				if (sqrt(dist) > j && sqrt(dist) < j + 1) {
					if (dist < ((j + 1) * (j + 1) - j * j) / 2.0 + j * j) {
						cout << 1 + (j - 1) * 2 + 1 << endl;
					}
					else
						cout << 1 + (j - 1) * 2 + 2 << endl;
					break;
				}
			}
		}
	}

	return 0;
}
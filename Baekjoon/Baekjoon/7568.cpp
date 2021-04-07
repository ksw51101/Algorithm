#include <iostream>
using namespace std;

int main() {
	int n, x[50], y[50], bigger[50], minimum, count;

	cin >> n;
	minimum = n;

	for (int i = 0; i < n; i++)
		cin >> x[i] >> y[i];

	fill(&bigger[0], &bigger[50], 1);

	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (x[i] < x[j] && y[i] < y[j])
				bigger[i]++;
			else if (x[i] > x[j] && y[i] > y[j])
				bigger[j]++;
		}
	}

	for (int i = 0; i < n; i++)
		cout << bigger[i] << ' ';

	return 0;
}
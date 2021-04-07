#include <iostream>
#include <math.h>
using namespace std;

int T, n, a, b;
bool arr[10002];
int main() {

	cin >> T;


	for (int i = 0; i < T; i++) {
		cin >> n;

		fill(&arr[0], &arr[n + 1], 1);

		arr[1] = false;
		for (int i = 1; i <= sqrt(n); i++) {
			if (arr[i] == true)
				for (int j = i; i + j <= n; j += i) {
					arr[i + j] = false;
				}
		}

		a = b = n / 2;

		while (arr[a] != true || arr[b] != true) {
			a--;
			b++;
		}
		cout << a << ' ' << b << endl;
	}

	return 0;
}